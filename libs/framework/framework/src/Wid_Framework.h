#ifndef WID_FRAMEWORK_H
#define WID_FRAMEWORK_H

#include <QWidget>

#include <QtNodes/NodeDelegateModelRegistry>
#include <QtNodes/DataFlowGraphModel>
#include <QtNodes/DataFlowGraphicsScene>
#include <QtNodes/GraphicsView>


namespace Ui {
    class Wid_Framework;
}

namespace framework {
class Wid_Framework : public QWidget
{
    Q_OBJECT

public:
    explicit Wid_Framework(QString str_plugin_path, QWidget *parent = nullptr);
    ~Wid_Framework();

    bool save();
    bool load();
    bool createProject();
    
    bool add_plugin(QString str_Plugin_path);

private:
    
    /// 节点样式设计
    void set_Nodes_Style();

    /// 插件安装_文件夹读取
    std::shared_ptr<QtNodes::NodeDelegateModelRegistry> registerDataModels(QString str_Plugin_path);

private:
    Ui::Wid_Framework *ui;
    
    QtNodes::DataFlowGraphModel     m_ModelManger;
    QtNodes::DataFlowGraphicsScene  *m_scene;
    QtNodes::GraphicsView           *m_view;
};

}

#endif // WID_FRAMEWORK_H
