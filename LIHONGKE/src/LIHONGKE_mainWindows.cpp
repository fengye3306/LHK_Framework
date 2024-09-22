#include "LIHONGKE_mainWindows.h"
#include "ui_LIHONGKE_mainWindows.h"


#include "./style/Style_QTabWidget.hpp"

#include <framework/Wid_Framework.hpp>

#include <QVBoxLayout>
#include <QTabBar>
#include <memory>

LIHONGKE_mainWindows::LIHONGKE_mainWindows(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::LIHONGKE_mainWindows),
    wid_framework(new framework::Wid_Framework("./framework_plugin/"))
{
    ui->setupUi(this);

    this->style();
    this->this_connect();
}

LIHONGKE_mainWindows::~LIHONGKE_mainWindows()
{
    delete ui;
}

void LIHONGKE_mainWindows::createProject(){
    
}

bool LIHONGKE_mainWindows::saveProject()  {
    this->wid_framework->save();
    
    return false;
}

bool LIHONGKE_mainWindows::loadProject()  {
    this->wid_framework->load();

    return false;
}

void LIHONGKE_mainWindows::style(){

    QVBoxLayout *layout = new QVBoxLayout(this->ui->tab_Flower);

    layout->addWidget(this->wid_framework);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->setSpacing(0);

}
void LIHONGKE_mainWindows::this_connect(){

    // 保存工程
    connect(this->ui->action_save, &QAction::triggered, this, &LIHONGKE_mainWindows::saveProject);
    // 加载工程
    connect(this->ui->action_load, &QAction::triggered, this, &LIHONGKE_mainWindows::loadProject);
}