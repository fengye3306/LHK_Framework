#pragma once

/**
 * @brief 样式配置
*/
#include <QColor>
#include <QFont>

// 定义莫兰迪色系的配色
namespace MorandiColors {
    const QColor LightGray  = QColor("#D3CBC2");  // 浅灰
    const QColor SoftBlue   = QColor("#A7BBC7");  // 柔和的蓝色
    const QColor SoftGreen  = QColor("#A5A299");  // 柔和的绿色
    const QColor SoftPink   = QColor("#CBB7A2");  // 柔和的粉色
    const QColor SoftYellow = QColor("#D9C7A2");  // 柔和的黄色
    const QColor SoftPurple = QColor("#ABA9BF");  // 柔和的紫色
    const QColor PureBlack  = QColor("#000000");  // 纯黑
}


class StyleConfig_Base {

public:

    StyleConfig_Base() = default;
    virtual ~StyleConfig_Base() = default;
    
    // 获取全局的字体样式
    virtual QFont getFont_Globel() const {
        return QFont("楷体", 22);  
    }

    // 获取选中状态的颜色（默认是莫兰迪色系的柔和蓝色）
    virtual QColor getColor_Selected() const {
        return MorandiColors::SoftBlue;
    }

    // 获取鼠标移动状态的颜色（默认是莫兰迪色系的柔和灰色）
    virtual QColor getColor_Hover() const {
        return MorandiColors::LightGray;
    }

    // 获取默认的字体颜色
    virtual QColor getColor_Text_Default() const {
        return MorandiColors::PureBlack;  // 默认纯黑色字体
    }

    // 获取控件的默认背景颜色
    virtual QColor getColor_DefaultBackgroundColor() const {
        return MorandiColors::SoftGreen;
    }

    // 获取焦点状态颜色
    virtual QColor getColor_Focus() const {
        return MorandiColors::SoftPink;
    }
};
