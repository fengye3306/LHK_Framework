# pragma once  

#include <QGraphicsItem>


class ImageROI_Base : public QGraphicsItem {
public:
    enum Color {
        RED,
        GREEN
    };

    ImageROI_Base(QGraphicsItem *parent = nullptr);
    virtual ~ImageROI_Base() = default;
    
    /**
     * @brief 设置ROI颜色
     * @param str_color 
     */
    virtual void Set_Color(ImageROI_Base::Color color);

    /**
     * @brief 获取ROI颜色
     * @return std::string  0xRRGGBB格式
     */
    virtual std::string Get_Color();


protected:
    virtual QRectF boundingRect() const = 0; 
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) = 0; 

private:


private:
    ImageROI_Base::Color m_color;
};
