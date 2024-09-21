# pragma once  

#include "./ImageROI_Base.hpp"

#include <QGraphicsItem>
#include <QObject>
#include <QWidget>
#include <QMouseEvent>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QRect>
#include <QPainter>
#include <QPolygon>
#include <QList>

enum STATE_FLAG{

    DEFAULT_FLAG = 0,
    MOV_LEFT_LINE       ,        //标记当前为用户按下矩形的左边界区域
    MOV_TOP_LINE        ,        //标记当前为用户按下矩形的上边界区域
    MOV_RIGHT_LINE      ,        //标记当前为用户按下矩形的右边界区域
    MOV_BOTTOM_LINE     ,        //标记当前为用户按下矩形的下边界区域
    MOV_RIGHTBOTTOM_RECT,        //标记当前为用户按下矩形的右下角
    MOV_RECT            ,        //标记当前为鼠标拖动图片移动状态
    ROTATE                       //标记当前为旋转状态
    
};


/**
 * @brief 矩形
 */
class ImageROI_Rectangular : 
    public ImageROI_Base{

public:
    ImageROI_Rectangular(ImageROI_Base *parent = nullptr);
    ~ImageROI_Rectangular() override;

    /**
     * @brief 设置矩形的大小
     * 
     * @param mrect              新的矩形大小
     * @param bResetRotateCenter 是否重置旋转中心，默认为 true
     */
    void setRectSize(QRectF mrect, bool bResetRotateCenter = true);

    /**
     * @brief 获取旋转后的点
     * 
     * @param ptCenter 旋转中心点
     * @param ptIn 待旋转的点
     * @param angle 旋转角度，单位为度
     * @return QPointF 旋转后的点
     */
    QPointF getRotatePoint(QPointF ptCenter, QPointF ptIn, qreal angle);

    /**
     * @brief 获取多个旋转后的点
     * 
     * @param ptCenter 旋转中心点
     * @param ptIns 待旋转的多个点
     * @param angle 旋转角度，单位为度
     * @return QList<QPointF> 旋转后的多个点
     */
    QList<QPointF> getRotatePoints(QPointF ptCenter, QList<QPointF> ptIns, qreal angle);

    /**
     * @brief 将矩形旋转之后返回对应的多边形
     * 
     * @param ptCenter 旋转中心点
     * @param rectIn 待旋转的矩形
     * @param angle 旋转角度，单位为度
     * @return QPolygonF 旋转后的多边形
     */
    QPolygonF getRotatePolygonFromRect(QPointF ptCenter, QRectF rectIn, qreal angle);

    /**
     * @brief 设置旋转角度并根据给定中心点进行旋转
     * 
     * @param RotateAngle 旋转角度，单位为度
     * @param ptCenter 旋转中心点，默认值为 (-999, -999)，表示自动选择中心
     */
    void SetRotate(qreal RotateAngle, QPointF ptCenter = QPointF(-999, -999));

    /**
     * @brief 获取项在屏幕上的当前位置信息（转换为屏幕坐标）
     * 
     * @return QRectF 项在屏幕上的边界矩形
     */
    QRectF getCrtPosRectToSceen();

    /**
     * @brief 获取旋转标记的中心点
     * 
     * @param ptA 矩形的一角
     * @param ptB 矩形的对角
     * @return QPointF 旋转标记的中心点
     */
    QPointF getSmallRotateRectCenter(QPointF ptA, QPointF ptB);

    /**
     * @brief 获取表示旋转标记的矩形
     * 
     * @param ptA 矩形的一角
     * @param ptB 矩形的对角
     * @return QRectF 旋转标记的矩形
     */
    QRectF getSmallRotateRect(QPointF ptA, QPointF ptB);

protected:
    /**
     * @brief 返回项的边界矩形
     * 
     * 该函数继承自 QGraphicsItem，需要在子类中实现。
     * 
     * @return QRectF 项的边界矩形，用于碰撞检测、更新和绘制区域的确定
     */
    virtual QRectF boundingRect() const override;

    /**
     * @brief 绘制项
     * 
     * 该函数继承自 QGraphicsItem，用于实现自定义绘图逻辑。
     * 
     * @param painter 用于绘制项的 QPainter 对象
     * @param option 提供绘制的样式选项
     * @param widget 指定在哪个窗口中进行绘制
     */
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

    /**
     * @brief 处理鼠标按下事件
     * 
     * 该函数继承自 QGraphicsItem，用于处理鼠标按下时的交互逻辑。
     * 
     * @param event 鼠标按下事件对象，包含事件的相关信息
     */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief 处理鼠标移动事件
     * 
     * 该函数继承自 QGraphicsItem，用于处理鼠标拖拽或移动时的交互逻辑。
     * 
     * @param event 鼠标移动事件对象，包含事件的相关信息
     */
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

    /**
     * @brief 处理鼠标释放事件
     * 
     * 该函数继承自 QGraphicsItem，用于处理鼠标释放时的交互逻辑。
     * 
     * @param event 鼠标释放事件对象，包含事件的相关信息
     */
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;

private: 

    QRectF      m_SmallRotateRect;     //矩形顶部用来表示旋转的标记的矩形
    QPolygonF   m_SmallRotatePolygon;  //矩形顶部用来表示旋转的标记的矩形旋转后形成的多边形

    bool        m_bRotate;
    qreal       m_RotateAngle;
    QPointF     m_RotateCenter;
    QRectF      m_oldRect;          
    QPolygonF   m_oldRectPolygon;
    QRectF      m_RotateAreaRect;
    bool        m_bResize;
    QPolygonF   m_insicedPolygon;
    QRectF      m_insicedRectf;
    QPolygonF   m_leftPolygon;
    QRectF      m_leftRectf;
    QPolygonF   m_topPolygon;
    QRectF      m_topRectf;
    QPolygonF   m_rightPolygon;
    QRectF      m_rightRectf;
    QPolygonF   m_bottomPolygon;
    QRectF      m_bottomRectf;
    QPointF     m_startPos;
    STATE_FLAG  m_StateFlag;
    QPointF *   pPointFofSmallRotateRect;

};
