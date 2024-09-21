#include "Style_main.hpp"


#include <QDebug>
#include <QStyleOptionTab>


Style_main::Style_main(std::shared_ptr<StyleConfig_Base> style_)
    : m_style(style_) 
{
    
}

QSize Style_main::sizeFromContents
    (   ContentsType type, 
        const QStyleOption *option,
        const QSize &size, 
        const QWidget *widget) const
{

    QSize size_QProxy = QProxyStyle::sizeFromContents(type, option, size, widget);



    return size_QProxy;
}

void Style_main::drawControl(
    ControlElement element, 
    const QStyleOption *option, 
    QPainter *painter, 
    const QWidget *widget) const
{
        if (option->state & QStyle::State_Selected) {               // 选中样式
            
            painter->setPen(m_style->getColor_Selected());
            painter->setBrush(QBrush(m_style->getColor_Selected()));

        } else if (option->state & QStyle::State_MouseOver) {       // 鼠标停留样式

            painter->setPen( m_style->getColor_Hover());    
            painter->setBrush(QBrush( m_style->getColor_Hover()));
        } 

        QProxyStyle::drawControl(element, option, painter, widget);

}
