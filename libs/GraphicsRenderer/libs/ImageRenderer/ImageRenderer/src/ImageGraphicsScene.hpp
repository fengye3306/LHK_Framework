// ImageGraphicsScene.hpp
#pragma once

#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsRectItem>
#include <QBrush>


class ImageGraphicsScene : public QGraphicsScene
{
    Q_OBJECT

public:
    ImageGraphicsScene(QObject* parent = nullptr) 
        : QGraphicsScene(parent) {

    }
    virtual ~ImageGraphicsScene();
    
protected:

};
