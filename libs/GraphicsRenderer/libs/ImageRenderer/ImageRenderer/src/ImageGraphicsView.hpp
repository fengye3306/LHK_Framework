#pragma once

#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsEllipseItem>
#include <QPoint>

// 自定义的 QGraphicsView 子类
class ImageGraphicsView : public QGraphicsView {
    Q_OBJECT
public:
    ImageGraphicsView(QWidget *parent = nullptr);
    
protected:
    // 鼠标滚动
    virtual void wheelEvent(QWheelEvent *event) override;
    // 鼠标点击
    virtual void mousePressEvent(QMouseEvent *event) override;
    // 鼠标移动
    virtual void mouseMoveEvent(QMouseEvent *event) override ;
    // 重写鼠标释放事件
    virtual void mouseReleaseEvent(QMouseEvent *event) override;

private:
    void translateView(QPointF point);

private:
    double m_scale;         // 缩放值
    QPoint m_lastMousePos;  // 拖拽时，鼠标锚点值
    bool   m_drag;          // 拖拽
};