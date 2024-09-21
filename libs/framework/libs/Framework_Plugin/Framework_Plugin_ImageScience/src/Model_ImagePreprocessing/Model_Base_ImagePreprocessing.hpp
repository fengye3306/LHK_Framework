#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QJsonObject>
#include <QtCore/QObject>
#include <QtWidgets/QLabel>
#include <Framework_Data/data.hpp>

#include <iostream>

namespace framework{


/**
 * @brief 图像预处理接口类，构建图像预处理模型
 * - 输入 - 图像矩阵
 * - 输出 - 图像矩阵
 */
class Model_Base_ImagePreprocessing : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    ~Model_Base_ImagePreprocessing() = default;

public:
    virtual unsigned int nPorts(QtNodes::PortType portType) const override;
    virtual NodeDataType dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;
    virtual std::shared_ptr<NodeData> outData(QtNodes::PortIndex port) override;
    virtual void setInData(std::shared_ptr<NodeData> data, QtNodes::PortIndex portIndex) override;
    virtual QWidget *embeddedWidget() override { return nullptr; }

protected:
    virtual void compute() = 0;
protected:

    std::weak_ptr<Data_Image>   data_input_Image_1;       // 数据输入
    std::shared_ptr<Data_Image> _result;                  // 数据输出
};

}