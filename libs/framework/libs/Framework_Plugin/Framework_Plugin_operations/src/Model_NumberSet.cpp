#include "Model_NumberSet.hpp"



unsigned int Model_NumberSet::nPorts(QtNodes::PortType portType) const { 
    
    unsigned int result = 0;

    switch (portType) {
    case QtNodes::PortType::In:
        result = 0;
            break;
    case QtNodes::PortType::Out:
        result = 1;
    default:
        break;
    }

    return result;
}
QtNodes::NodeDataType Model_NumberSet::dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const { 
    return Data_Double().type();
}
std::shared_ptr<QtNodes::NodeData> Model_NumberSet::outData(QtNodes::PortIndex port) { 
    return this->m_numberData;
}
void Model_NumberSet::setInData(
    std::shared_ptr<QtNodes::NodeData> data, 
    QtNodes::PortIndex portIndex) 
{  

}

QWidget *Model_NumberSet::embeddedWidget() 
{
    if (!m_doubleSpinBox) {
        m_doubleSpinBox = new QDoubleSpinBox();
    }
    connect(this->m_doubleSpinBox, &QDoubleSpinBox::textChanged, 
        this, &Model_NumberSet::run);

    return m_doubleSpinBox;
}

void Model_NumberSet::run(QString const &string){
    bool ok = false;
    double number = string.toDouble(&ok);

    if (ok) {
        this->m_numberData = std::make_shared<Data_Double>(number);
        Q_EMIT dataUpdated(0);
    } else {
        Q_EMIT dataInvalidated(0);
    }
}


QJsonObject                        Model_NumberSet::save() const {
    QJsonObject modelJson = NodeDelegateModel::save();
    modelJson["number"] = QString::number(this->m_numberData->number());
    return modelJson;
}
void                               Model_NumberSet::load(QJsonObject const &p) {
    
    QJsonValue v = p["number"];

    if (!v.isUndefined()) {
        QString strNum = v.toString();

        bool ok;
        double d = strNum.toDouble(&ok);

        if (ok) {
            this->m_numberData = std::make_shared<Data_Double>(d);
            if (this->m_doubleSpinBox)
                m_doubleSpinBox->setValue(d);
        }
    }
}