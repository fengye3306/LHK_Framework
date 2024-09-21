#pragma once 

#include "./../Model_Base_ImagePreprocessing.hpp"


namespace framework {

/// 手动全局阈值
class Model_GlobalBinaryThresholding : public Model_Base_ImagePreprocessing{

public :

    Model_GlobalBinaryThresholding() : 
        wid_config(nullptr)
    {

    };
    virtual ~Model_GlobalBinaryThresholding(){

    }

    QString caption() const override { return QStringLiteral("图像预处理_手动全局阈值"); }
    bool    captionVisible() const override { return true; }
    QString name() const override { return QStringLiteral   ("图像预处理_手动全局阈值"); }
    
private:
    virtual QWidget * embeddedWidget() override;
    void              compute() override;

private:
    QWidget *wid_config;
    double m_thresh;
    double m_maxval;
};

}