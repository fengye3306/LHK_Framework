#pragma once

#include <QtNodes/NodeDelegateModel>
#include <QtCore/QObject>
#include <iostream>

#include "Model_MathOperation.hpp"

using QtNodes::NodeData;
using QtNodes::NodeDataType;
using QtNodes::NodeDelegateModel;
using QtNodes::PortIndex;
using QtNodes::PortType;

class QLabel;

/// The model dictates the number of inputs and outputs for the Node.
/// In this example it has no logic.
class Model_NumberDisplay : public NodeDelegateModel
{
    Q_OBJECT

public:
    Model_NumberDisplay();

    ~Model_NumberDisplay() = default;

public:
    QString caption() const override { return QStringLiteral("有理数展示"); }
    bool captionVisible() const override { return true; }
    QString name() const override { return QStringLiteral("有理数展示"); }

public:
    unsigned int nPorts(PortType portType) const override;

    NodeDataType dataType(PortType portType, PortIndex portIndex) const override;

    std::shared_ptr<NodeData> outData(PortIndex port) override;

    void setInData(std::shared_ptr<NodeData> data, PortIndex portIndex) override;

    QWidget *embeddedWidget() override;

    double number() const;

private:
    std::shared_ptr<Data_Double> _numberData;

    QLabel *_label;
};
