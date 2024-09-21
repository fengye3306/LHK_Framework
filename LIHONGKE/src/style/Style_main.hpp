#pragma once

#include <QPainter>
#include <QProxyStyle>


#include "StyleConfig_Base.hpp"
 
class Style_main : public QProxyStyle
{

public:

    Style_main(std::shared_ptr<StyleConfig_Base> style_);

    /**
     * @brief 计算控件内容的尺寸。
     * 
     * 该函数会根据控件的类型、控件的选项、默认大小和控件本身来确定控件的适当大小。
     * 通常用于调整控件的布局，使控件的外观更符合自定义需求。例如，按钮可以通过
     * 增加边距或改变其默认大小来进行调整。
     * 
     * @param type 控件的类型（如按钮、框架、文本框等），类型为 QStyle::ContentsType。
     * @param option 描述控件的外观和状态的 QStyleOption 对象。
     * @param size 控件的默认大小。
     * @param widget 指向控件本身的指针，可能为空。
     * @return QSize 返回调整后的控件大小。
     */
    virtual QSize sizeFromContents(
        ContentsType type, 
        const QStyleOption *option,
        const QSize &size, 
        const QWidget *widget) const;

    /**
     * @brief 控件元素的绘制函数。
     * 
     * 该函数根据提供的元素类型、控件选项和绘制设备，绘制特定的控件元素。通过重载此函数，
     * 可以自定义 Qt 控件的外观。你可以使用 QPainter 在给定的控件区域中绘制矩形、文本等元素。
     * 
     * @param element   控件的元素类型，如按钮、滑块、滚动条等
     * @param option    描述控件的外观和状态的 QStyleOption 对象。
     * @param painter   用于绘制的 QPainter 对象。
     * @param widget    指向控件本身的指针，可能为空。
     */
    virtual void drawControl(
        ControlElement      element, 
        const QStyleOption *option, 
        QPainter           *painter, 
        const QWidget      *widget  ) const;



private:
    /**
     * @brief 样式
     * 
     */
    std::shared_ptr<StyleConfig_Base> m_style;

};