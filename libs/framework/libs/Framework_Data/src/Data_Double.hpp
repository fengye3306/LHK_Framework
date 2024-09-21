#pragma once

#include <QtNodes/NodeData>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

/// The class can potentially incapsulate any user data which
/// need to be transferred within the Node Editor graph
class Data_Double : public NodeData
{
public:
    Data_Double()
        : _number(0.0)
    {

    }

    Data_Double(double const number)
        : _number(number)
    {

    }

    NodeDataType type()         const override { return NodeDataType{"有理数", "有理数"}; }
    double       number()       const { return _number; }
    QString      numberAsText() const { return QString::number(_number, 'f'); }

private:
    double _number;
};
