#pragma once 

#include "./Model_MathOperation.hpp"

#include <Framework_Data/data.hpp>


class Model_MathOperation_Multiplication : public Model_MathOperation{

public :
    QString caption() const override { return QStringLiteral("乘法"); }
    bool captionVisible() const override { return true; }
    QString name() const override { return QStringLiteral("乘法"); }
    
public:
    void compute() override
    {
        PortIndex const outPortIndex = 0;

        auto n1 = _number1.lock();
        auto n2 = _number2.lock();

        if (n1 && n2) {
            //modelValidationState = NodeValidationState::Valid;
            //modelValidationError = QString();
            _result = std::make_shared<Data_Double>(n1->number() * n2->number());
        } else {
            //modelValidationState = NodeValidationState::Warning;
            //modelValidationError = QStringLiteral("Missing or incorrect inputs");
            _result.reset();
        }

        Q_EMIT dataUpdated(outPortIndex);
    }


};