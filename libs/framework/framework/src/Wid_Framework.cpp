#include "Wid_Framework.h"
#include "ui_Wid_Framework.h"

#include <QVBoxLayout>

#include <dlfcn.h>  // 动态链接库函数头
#include <vector>
#include <string>
#include <QDebug>
#include <filesystem>

namespace framework {

Wid_Framework::Wid_Framework(QString str_plugin_path,QWidget *parent):
    QWidget(parent),
    ui(new Ui::Wid_Framework),

    m_ModelManger(this->registerDataModels(str_plugin_path)),
    m_scene(nullptr),
    m_view(nullptr)
{
    ui->setupUi(this);

    this->set_Nodes_Style();
    QVBoxLayout *layout = new QVBoxLayout(this);
    this->m_scene  = new QtNodes::DataFlowGraphicsScene(m_ModelManger, this);
    this->m_view   =  new QtNodes::GraphicsView(m_scene);

    layout->addWidget(m_view);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);
}

Wid_Framework::~Wid_Framework()
{
    delete ui;
}

/// 节点安装
std::shared_ptr<QtNodes::NodeDelegateModelRegistry> Wid_Framework::registerDataModels(QString str_Plugin_path){
    auto ret = std::make_shared<QtNodes::NodeDelegateModelRegistry>();

    // 获取插件目录
    std::filesystem::path pluginDir(str_Plugin_path.toStdString());
    if (!std::filesystem::exists(pluginDir) || !std::filesystem::is_directory(pluginDir)) {
        // 处理错误：目录不存在
        return ret;
    }

    // 遍历目录中的所有动态链接库
    for (const auto& entry : std::filesystem::directory_iterator(pluginDir)) {
        if (entry.is_regular_file() && entry.path().extension() == ".so") {  // 针对 Linux 系统的 .so 文件
            std::string libPath = entry.path().string();
            void* handle = dlopen(libPath.c_str(), RTLD_LAZY);
            if (!handle) {
                // 处理错误：库加载失败
                continue;
            }

            // 获取 PLUGIN_OUTPUT 函数的地址
            using PluginOutputFunc = bool(*)(std::shared_ptr<QtNodes::NodeDelegateModelRegistry>);
            PluginOutputFunc pluginOutput = reinterpret_cast<PluginOutputFunc>(dlsym(handle, "PLUGIN_OUTPUT"));

            if (!pluginOutput) {
                const char* error = dlerror();
                if (error) {
                    //qDebug() << "dlsym 错误: " << QString::fromUtf8(error);
                } else {
                    //qDebug() << "未找到 PLUGIN_OUTPUT 符号";
                }
            } else {
                // 调用 PLUGIN_OUTPUT 函数
                pluginOutput(ret);
            }

            // 关闭库
            dlclose(handle);
        }
    }
    
    return ret;
}

bool Wid_Framework::save(){
    return m_scene->save();
};

bool Wid_Framework::load(){
    return m_scene->load();
};
bool Wid_Framework::createProject(){
    return false;
};

bool Wid_Framework::add_plugin(QString str_Plugin_path){
    return false;
}

void Wid_Framework::set_Nodes_Style(){
    QtNodes::ConnectionStyle::setConnectionStyle(
    R"(
        {
            "ConnectionStyle": {
            
                "ConstructionColor": "gray",
                "NormalColor"      : "black",
                "SelectedColor"    : "gray",
                "SelectedHaloColor": "deepskyblue",
                "HoveredColor"     : "deepskyblue",

                "LineWidth"        : 3.0,
                "ConstructionLineWidth": 2.0,
                "PointDiameter"    : 10.0,

                "UseDataDefinedColors": true
            }
        }
    )");

}
}

