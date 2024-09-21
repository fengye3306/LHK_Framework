#include "./Model_GlobalBinaryThresholding.hpp"

#include <QWidget>
#include <QSlider>
#include <QVBoxLayout>

namespace framework {


QWidget * Model_GlobalBinaryThresholding::embeddedWidget() {

    if(this->wid_config == nullptr){
        wid_config = new QWidget();

        // 创建垂直布局
        QVBoxLayout *layout = new QVBoxLayout(wid_config);

        // 创建第一个滑块
        QSlider *slider1 = new QSlider(Qt::Horizontal);
        slider1->setRange(0, 255);  // 设置滑块范围
        layout->addWidget(slider1); // 将滑块添加到布局中

        // 创建第二个滑块
        QSlider *slider2 = new QSlider(Qt::Horizontal);
        slider2->setRange(0, 255);  // 设置滑块范围
        layout->addWidget(slider2); // 将滑块添加到布局中

        // 设置自适应大小
        wid_config->setLayout(layout);  // 应用布局
        wid_config->adjustSize();       // 自适应调整窗口大小
    
        connect (slider1, &QSlider::valueChanged,this,[&](int value){
            this->m_thresh = value;
            compute();
        });
        connect (slider2, &QSlider::valueChanged,this,[&](int value){
            this->m_maxval = value;
            compute();
        });
    }
    return this->wid_config;
};

void Model_GlobalBinaryThresholding::compute() {

    QtNodes::PortIndex const outPortIndex = 0;

    auto n1 = data_input_Image_1.lock();

    if (n1 ) {

        if(n1->data().empty() == true){
        
        }

        // 如果图像是多通道（彩色图像），则转换为灰度图像
        cv::Mat grayImg;
        if (n1->data().channels() > 1) {
            cv::cvtColor(n1->data(), grayImg, cv::COLOR_BGR2GRAY);
        } else {
            grayImg = n1->data();  // 如果已经是单通道，直接使用原图
        }
        
        // 保存二值化后的图像
        cv::Mat binImg;
        // 二值化
        double otsuThresh = cv::threshold(grayImg, binImg, this->m_thresh, this->m_maxval, cv::THRESH_BINARY );

        _result = std::make_shared<Data_Image>(binImg);

        } else {
            _result.reset();
        }

        Q_EMIT dataUpdated(outPortIndex);
    }

}