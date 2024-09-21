#pragma once

#include <QtNodes/NodeDelegateModel>
#include <QtCore/QObject>

#include <QLabel>
#include <QDoubleSpinBox>

#include <Framework_Data/data.hpp>

class Model_NumberSet : public QtNodes::NodeDelegateModel
{
    Q_OBJECT

public:
    Model_NumberSet():
        m_doubleSpinBox(nullptr),
        m_numberData(std::make_shared<Data_Double>(0))
    {

    };

    ~Model_NumberSet() = default;

public:
    
    virtual bool    captionVisible() const override { return true; }
    virtual QString caption()        const override { return QStringLiteral("有理数输入"); }    
    virtual QString name()           const override { return QStringLiteral("有理数输入"); }

public:
    virtual unsigned int                       nPorts(QtNodes::PortType portType) const override;
    virtual QtNodes::NodeDataType              dataType(QtNodes::PortType portType, QtNodes::PortIndex portIndex) const override;
    virtual std::shared_ptr<QtNodes::NodeData> outData(QtNodes::PortIndex port) override;
    virtual void                               setInData(std::shared_ptr<QtNodes::NodeData> data, QtNodes::PortIndex portIndex) override;
    virtual QWidget *                          embeddedWidget() override;

    virtual QJsonObject                        save() const override;
    virtual void                               load(QJsonObject const &p) override;
private:
    void                                       run(QString const &string);

private:
    std::shared_ptr<Data_Double>       m_numberData;        // 数据
    QDoubleSpinBox*                    m_doubleSpinBox;     // 数据输入窗
};



