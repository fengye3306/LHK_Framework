#pragma once

#include <QtNodes/NodeDelegateModel>
#include <QtCore/QObject>

#include <QLabel>
#include <QDoubleSpinBox>

#include <Framework_Data/data.hpp>

/// @brief 本地图像 加载
namespace framework {

class Model_ImageLoader : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:

    Model_ImageLoader():
        m_data_image(std::make_shared<Data_Image>()),
        m_label_loadFile(nullptr),
        m_str_filepath("")
    {
        
    };

    ~Model_ImageLoader() = default;

public:

    virtual bool    captionVisible() const override { return true; }
    virtual QString caption()        const override { return QStringLiteral("图像采样_本地图像"); }    
    virtual QString name()           const override { return QStringLiteral("图像采样_本地图像"); }

public:
    virtual unsigned int                       nPorts(QtNodes::PortType portType) const override;
    virtual QtNodes::NodeDataType              dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;
    virtual std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override;
    virtual void                               setInData(std::shared_ptr<QtNodes::NodeData> data, QtNodes::PortIndex portIndex) override;
    virtual QWidget *                          embeddedWidget() override;

    virtual QJsonObject                        save() const override;
    virtual void                               load(QJsonObject const &p) override;

protected:
    virtual bool eventFilter(QObject *object, QEvent *event) override;
private:
    bool run(QString const &string);                // 运行
private:
    std::shared_ptr<Data_Image> m_data_image;       // 数据
    QLabel                      *m_label_loadFile;  // 
    QPixmap                     m_pixmap;           // 
    QString                     m_str_filepath;     // 图片路径
};

}


