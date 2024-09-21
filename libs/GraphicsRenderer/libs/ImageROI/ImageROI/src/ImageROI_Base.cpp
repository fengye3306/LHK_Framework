#include "./ImageROI_Base.hpp"

ImageROI_Base::ImageROI_Base(QGraphicsItem *parent /*= nullptr*/){
    m_color = ImageROI_Base::Color::GREEN;
}

void ImageROI_Base::Set_Color(ImageROI_Base::Color color){
    this->m_color = color;
}

std::string ImageROI_Base::Get_Color(){
    switch (m_color) {
        case Color::GREEN:
            return "#00FF00";  // 莫兰迪风格绿色的十六进制表示
        case Color::RED:
            return "#FF0000";  // 莫兰迪风格红色的十六进制表示
        default:
            return "#000000";  // 默认颜色（黑色），或者你可以选择其他合适的默认值
    }
};