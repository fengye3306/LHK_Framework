#pragma once

#include <iostream>

#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include <QtNodes/NodeDelegateModel>
#include <QtNodes/NodeDelegateModelRegistry>

#include <opencv2/opencv.hpp>

namespace framework {

/// 图像展示
class Model_ImageDisplay : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    Model_ImageDisplay();

    ~Model_ImageDisplay() = default;

public:
    QString         caption()   const override { return QString("图像展示"); }
    QString         name()      const override    { return QString("图像展示"); }
    virtual QString modelName() const { return QString("图像展示"); }

public:
    unsigned int nPorts(QtNodes::PortType const portType) const override;
    QtNodes::NodeDataType dataType(QtNodes::PortType const portType, QtNodes::PortIndex const portIndex) const override;
    std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex const port) override;
    void setInData(std::shared_ptr<QtNodes::NodeData> nodeData, QtNodes::PortIndex const port) override;
    QWidget *embeddedWidget() override { return _label; }
    bool resizable() const override { return true; }

protected:
    bool eventFilter(QObject *object, QEvent *event) override;

private:
    // 将 cv::Mat 转换为 QPixmap
    QPixmap MatToQImage(const cv::Mat& mat) ;


private:
    QLabel *_label;

    std::shared_ptr<QtNodes::NodeData> _nodeData;
};

}