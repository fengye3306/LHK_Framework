#include "ImageGraphicsView.hpp"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsRectItem>
#include <QMouseEvent>
#include <QWheelEvent>
#include <QScrollBar>
#include <QDebug>

ImageGraphicsView::ImageGraphicsView(QWidget *parent ) : 
    QGraphicsView(parent) 
{
    // 设置视图的背景色
    setBackgroundBrush(Qt::lightGray);
    // 设置背景的缩放
    m_scale = 1.0;

    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); // 禁用水平滚动条
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);   // 禁用垂直滚动条
}

// 鼠标滚动
void ImageGraphicsView::wheelEvent(QWheelEvent *event) {
    // 获取滚轮的增量
    qreal factor = 1.2;
    if (event->angleDelta().y() < 0) {
        factor = 1.0 / factor;
    }
    
    // 缩放视图
    scale(factor, factor);

    // 获取当前的变换矩阵 取得缩放
    QTransform t = this->transform();
    double scaleX = t.m11();  
    // 记录缩放
    this -> m_scale = scaleX;
};

void ImageGraphicsView::translateView(QPointF point) {
    point = point * this->m_scale;
    QPoint newCenter(
        viewport()->rect().width() / 2 - point.x(),  
        viewport()->rect().height() / 2 - point.y());
    centerOn(mapToScene(newCenter));
    setTransformationAnchor(QGraphicsView::AnchorViewCenter);
}

void ImageGraphicsView::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        // 更新上一次鼠标位置
        m_lastMousePos = event->pos();
        // 标志为拖拽
        m_drag = true;
    }
    QGraphicsView::mousePressEvent(event);   
}

void ImageGraphicsView::mouseMoveEvent(QMouseEvent *event)  {
    if(m_drag == true){
        QPointF mouseDelta = 
            mapToScene(event->pos()) - mapToScene(m_lastMousePos);
        translateView(mouseDelta);
        this->scene()->setSceneRect(
            this->scene()->sceneRect().x()-mouseDelta.x(),
            this->scene()->sceneRect().y()-mouseDelta.y(),
            this->scene()->sceneRect().width(),
            this->scene()->sceneRect().height());
        this->scene()->update();
        m_lastMousePos = event->pos();
    }
    QGraphicsView::mouseMoveEvent(event);   
};

void ImageGraphicsView::mouseReleaseEvent(QMouseEvent *event) {

    // 鼠标释放时完成平移
    m_drag = false;

    if (event->button() == Qt::RightButton) {
        setCursor(Qt::ArrowCursor);
    }
    QGraphicsView::mouseReleaseEvent(event);
}