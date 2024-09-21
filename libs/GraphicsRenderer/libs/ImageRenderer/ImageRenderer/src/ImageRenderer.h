#ifndef IMAGERENDERER_H
#define IMAGERENDERER_H

#include <QWidget>

#include "./ImageGraphicsView.hpp"
#include "./ImageGraphicsScene.hpp"

namespace Ui {
class ImageRenderer;
}

class ImageRenderer : public QWidget
{
    Q_OBJECT

public:
    explicit ImageRenderer(QWidget *parent = nullptr);
    ~ImageRenderer();
    

    void this_Connect();
    void this_Style();
private:
    Ui::ImageRenderer  *ui;
    ImageGraphicsView  *m_view;
    ImageGraphicsScene *m_scene; 
    QGraphicsPixmapItem *m_Image;
};

#endif // IMAGERENDERER_H
