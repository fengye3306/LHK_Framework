#pragma once

#include <opencv2/opencv.hpp>
#include <QtNodes/NodeData>
#include <QString>

using QtNodes::NodeData;
using QtNodes::NodeDataType;

namespace framework {

/**
 * @brief 表达2D图像矩阵
 */
class Data_Image : public NodeData
{
public:
    // 默认构造函数
    Data_Image()
        : _data(cv::Mat())
    {

    }

    Data_Image(cv::Mat mat)
        : _data(mat)
    {

    }

    // 拷贝构造函数
    Data_Image(const Data_Image& other)
        : _data(other._data.clone())  // 深拷贝 cv::Mat 数据
    {

    }

    // 析构函数
    ~Data_Image() override
    {
        // 由于 cv::Mat 会自动管理其内部数据，通常不需要显式释放资源
    }

    // 重写类型函数
    NodeDataType type() const override { return NodeDataType{"图片", "图片"}; }

    // 返回数据函数
    cv::Mat data() const { return _data; }

    // 将数据作为文本返回函数
    QString dataAsText() const { return QString::fromStdString("Image_cv"); }

private:
    cv::Mat _data;
};

}