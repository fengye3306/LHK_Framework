#pragma once

#include <QtNodes/NodeDelegateModel>

#include <QtCore/QJsonObject>
#include <QtCore/QObject>
#include <QtWidgets/QLabel>

#include <iostream>

class Data_Double;

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class Model_MathOperation : public NodeDelegateModel
{
    Q_OBJECT

public:
    ~Model_MathOperation() = default;

public:
    virtual unsigned int nPorts(PortType portType) const override;
    virtual NodeDataType dataType(PortType portType, PortIndex portIndex) const override;
    virtual std::shared_ptr<NodeData> outData(PortIndex port) override;
    virtual void setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) override;
    virtual QWidget *embeddedWidget() override { return nullptr; }

protected:
    virtual void compute() = 0;
protected:

    std::weak_ptr<Data_Double>  _number1;       // 数据输入
    std::weak_ptr<Data_Double>  _number2;       // 数据输入
    std::shared_ptr<Data_Double> _result;       // 数据输出
};
