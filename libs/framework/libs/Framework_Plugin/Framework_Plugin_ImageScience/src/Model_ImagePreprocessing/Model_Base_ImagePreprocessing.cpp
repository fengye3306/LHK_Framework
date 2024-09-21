#include "Model_Base_ImagePreprocessing.hpp"

#include <Framework_Data/data.hpp>


namespace framework{



unsigned int Model_Base_ImagePreprocessing::nPorts(QtNodes::PortType portType) const
{
    unsigned int result;
    if (portType == QtNodes::PortType::In)
        result = 1;
    else
        result = 1;
    return result;
}

NodeDataType Model_Base_ImagePreprocessing::dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const
{

    NodeDataType datatype;

    if (portType == QtNodes::PortType::In){
        if(0 == portIndex) {
            datatype = framework::Data_Image().type();
        }
    }
    else{
        if(0 == portIndex) {
            datatype = framework::Data_Image().type();
        }
    }
        
    return datatype;
}

std::shared_ptr<NodeData> Model_Base_ImagePreprocessing::outData(QtNodes::PortIndex)
{
    return std::static_pointer_cast<NodeData>(_result);
}

void Model_Base_ImagePreprocessing::setInData(std::shared_ptr<NodeData> data, QtNodes::PortIndex portIndex)
{
    if( portIndex == 0){
        // 尝试进行类型转换
        auto imageData = std::dynamic_pointer_cast<framework::Data_Image>(data);
        if(!imageData){
            Q_EMIT dataInvalidated(0);
        }
        data_input_Image_1 = imageData;
    }
    compute();
}
}