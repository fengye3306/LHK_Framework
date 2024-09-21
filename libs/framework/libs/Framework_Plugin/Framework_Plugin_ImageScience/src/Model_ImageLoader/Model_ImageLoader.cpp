#include "Model_ImageLoader.hpp"

#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QLabel>
#include <QPixmap>
#include <QWidget>
#include <QMessageBox>
#include <QEvent>

namespace framework {

unsigned int Model_ImageLoader::nPorts(QtNodes::PortType portType) const { 
    
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
QtNodes::NodeDataType Model_ImageLoader::dataType
    (QtNodes::PortType portType, QtNodes::PortIndex portIndex) const { 

    return Data_Image().type();

}
std::shared_ptr<QtNodes::NodeData> Model_ImageLoader::outData(QtNodes::PortIndex port) { 
    return this->m_data_image;
}
void Model_ImageLoader::setInData(
    std::shared_ptr<QtNodes::NodeData> data, 
    QtNodes::PortIndex portIndex) 
{  
    return;
}

QWidget *Model_ImageLoader::embeddedWidget() 
{
    if(nullptr == m_label_loadFile) {
        m_label_loadFile = new QLabel();
        m_label_loadFile->setMaximumSize(160,90);
        m_label_loadFile->setMinimumSize(160,90);

        m_label_loadFile->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
        m_label_loadFile->installEventFilter(this);
    }

    return this->m_label_loadFile;
}


bool Model_ImageLoader::eventFilter(QObject *object, QEvent *event){
    if (object == m_label_loadFile) {

        int w = m_label_loadFile->width();
        int h = m_label_loadFile->height();

        if (event->type() == QEvent::MouseButtonPress) {

            QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                            tr("Open Image"),
                                                            QDir::homePath(),
                                                            tr("Image Files (*.png *.jpg *.bmp)"));

            if(true == this->run(fileName)) {
                m_pixmap = QPixmap(fileName);
                m_label_loadFile->setPixmap(m_pixmap.scaled(w, h, Qt::KeepAspectRatio));

            };

            return true;

        } else if (event->type() == QEvent::Resize) {
            if (!m_pixmap.isNull())
                m_label_loadFile->setPixmap(m_pixmap.scaled(w, h, Qt::KeepAspectRatio));
        }
    }

    return false;    
};


bool Model_ImageLoader::run(QString const &string){

    QString fileName = string;
 

    cv::Mat image = cv::imread(fileName.toStdString());

    // 检查图片是否读取成功
    if (true == image.empty()) {
        return false;
    } 

    this->m_str_filepath = fileName;
    this->m_data_image = std::make_shared<Data_Image>(image); 

    // 触发执行流
    Q_EMIT dataUpdated(0);
    
    return true;
}


QJsonObject Model_ImageLoader::save() const {
    QJsonObject modelJson = NodeDelegateModel::save();
    return modelJson;
}

void Model_ImageLoader::load(QJsonObject const &p) {
    
}

}