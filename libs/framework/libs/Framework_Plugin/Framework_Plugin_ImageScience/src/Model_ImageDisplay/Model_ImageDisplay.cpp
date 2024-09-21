#include "Model_ImageDisplay.hpp"


#include <QtNodes/NodeDelegateModelRegistry>

#include <QtCore/QDir>
#include <QtCore/QEvent>
#include <QtWidgets/QFileDialog>

#include <QPixmap>
#include <QDebug>

#include <Framework_Data/data.hpp>

namespace framework {

Model_ImageDisplay::Model_ImageDisplay()
    : _label(new QLabel("Image will appear here"))
{
    _label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);

    QFont f = _label->font();
    f.setBold(true);
    f.setItalic(true);

    _label->setFont(f);
    _label->setMinimumSize(224, 126);
    _label->installEventFilter(this);
}

unsigned int Model_ImageDisplay::nPorts(QtNodes::PortType portType) const
{
    unsigned int result = 1;

    switch (portType) {
    case QtNodes::PortType::In:
        result = 1;
        break;

    case QtNodes::PortType::Out:
        result = 0;

    default:
        break;
    }
    return result;
}

bool Model_ImageDisplay::eventFilter(QObject *object, QEvent *event)
{
    if (object == _label) {
        int w = _label->width();
        int h = _label->height();

        if (event->type() == QEvent::Resize) {
            
            auto image = std::dynamic_pointer_cast<framework::Data_Image>(_nodeData);
            if(image){
                QPixmap pixmap =  MatToQImage(image->data());
                _label->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
                
            } 
        }
    }

    return false;
}


    // 将 cv::Mat 转换为 QPixmap
QPixmap Model_ImageDisplay::MatToQImage(const cv::Mat& mat) {

    
    if (mat.type() == CV_8UC1) {  // 灰度图像
        QImage image(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_Grayscale8);
        return QPixmap::fromImage(image);
    } else if (mat.type() == CV_8UC3) {  // 彩色图像
        QImage image(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_RGB888);
        return QPixmap::fromImage(image.rgbSwapped());  // OpenCV 使用 BGR 顺序，因此需要交换为 RGB
    } else if (mat.type() == CV_8UC4) {  // 带有 alpha 通道的图像
        QImage image(mat.data, mat.cols, mat.rows, static_cast<int>(mat.step), QImage::Format_ARGB32);
        return QPixmap::fromImage(image);
    } else {
        // 不支持的图像格式
        return QPixmap();
        
    }
}


QtNodes::NodeDataType Model_ImageDisplay::dataType(QtNodes::PortType const, QtNodes::PortIndex const) const
{
    return framework::Data_Image().type();
}

std::shared_ptr<QtNodes::NodeData> Model_ImageDisplay::outData(QtNodes::PortIndex)
{
    std::shared_ptr<NodeData> ptr;
    return ptr;
}

void Model_ImageDisplay::setInData(std::shared_ptr<QtNodes::NodeData> nodeData, QtNodes::PortIndex const)
{
    _nodeData = nodeData;

    if (_nodeData) {
        auto image = std::dynamic_pointer_cast<framework::Data_Image>(_nodeData);

        int w = _label->width();
        int h = _label->height();

        QPixmap pixmap =  MatToQImage(image->data());
        _label->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));
        _label->setPixmap(pixmap.scaled(w, h, Qt::KeepAspectRatio));


    } else {
        _label->setPixmap(QPixmap());
    }

    Q_EMIT dataUpdated(0);
}


}