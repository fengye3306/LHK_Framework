#include "Model_MathOperation.hpp"

#include <Framework_Data/data.hpp>

unsigned int Model_MathOperation::nPorts(PortType portType) const
{
    unsigned int result;
    if (portType == PortType::In)
        result = 2;
    else
        result = 1;
    return result;
}

NodeDataType Model_MathOperation::dataType(PortType, PortIndex) const
{
    return Data_Double().type();
}

std::shared_ptr<NodeData> Model_MathOperation::outData(PortIndex)
{
    return std::static_pointer_cast<NodeData>(_result);
}

void Model_MathOperation::setInData(std::shared_ptr<NodeData> data, PortIndex portIndex)
{
    auto numberData = std::dynamic_pointer_cast<Data_Double>(data);

    if (!data) {
        Q_EMIT dataInvalidated(0);
    }

    if (portIndex == 0) {
        _number1 = numberData;
    } else {
        _number2 = numberData;
    }

    compute();
}
