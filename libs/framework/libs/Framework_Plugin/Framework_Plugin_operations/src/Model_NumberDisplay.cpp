#include "Model_NumberDisplay.hpp"
#include <Framework_Data/data.hpp>

#include <QtWidgets/QLabel>

Model_NumberDisplay::Model_NumberDisplay()
    : _label{nullptr}
{}

unsigned int Model_NumberDisplay::nPorts(PortType portType) const
{
    unsigned int result = 1;

    switch (portType) {
    case PortType::In:
        result = 1;
        break;

    case PortType::Out:
        result = 0;

    default:
        break;
    }

    return result;
}

NodeDataType Model_NumberDisplay::dataType(PortType, PortIndex) const
{
    return Data_Double().type();
}

std::shared_ptr<NodeData> Model_NumberDisplay::outData(PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void Model_NumberDisplay::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex)
{
    _numberData = std::dynamic_pointer_cast<Data_Double>(data);

    if (!_label)
        return;

    if (_numberData) {
        _label->setText(_numberData->numberAsText());
    } else {
        _label->clear();
    }

    _label->adjustSize();
}

QWidget *Model_NumberDisplay::embeddedWidget()
{
    if (!_label) {
        _label = new QLabel();
        _label->setMargin(3);
    }

    return _label;
}

double Model_NumberDisplay::number() const
{
    if (_numberData)
        return _numberData->number();

    return 0.0;
}
