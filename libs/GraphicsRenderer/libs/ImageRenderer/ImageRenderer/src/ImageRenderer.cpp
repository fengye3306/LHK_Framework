
#include <QVBoxLayout>

#include "ImageRenderer.h"
#include "ui_ImageRenderer.h"

#include <QDebug>
#include <QGraphicsPixmapItem>
#include <QImage>
#include <QPixmap>
#include <ImageROI/ImageROI_interface.hpp>



ImageRenderer::ImageRenderer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ImageRenderer),
    m_view(new ImageGraphicsView()),
    m_scene(new ImageGraphicsScene()),
    m_Image(new QGraphicsPixmapItem())
{
    ui->setupUi(this);

    // 视窗中添加 GraphicsView
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addWidget(m_view);
    this->ui->view->setLayout(layout);

    m_view->setScene(m_scene);

    this_Connect();
    this_Style();
}

void ImageRenderer::this_Style(){
    QPixmap pixmap(":/img/img/FULL.png");
    this->ui->btn_FULL->setIcon(pixmap);
    QSize iconSize(this->ui->btn_FULL->width() * 0.9, this->ui->btn_FULL->height() * 0.9);
    this->ui->btn_FULL->setIconSize(iconSize);
}

void ImageRenderer::this_Connect(){
    this->connect(  
        this->ui->btn_FULL, &QPushButton::clicked, 
        this,[&](){
            m_view->fitInView(m_Image, Qt::KeepAspectRatio);
            m_view->scale(0.8, 0.8);    // 获取当前变换矩阵，并缩放到80%
        }  
    );
}

ImageRenderer::~ImageRenderer()
{
    delete ui;
}
