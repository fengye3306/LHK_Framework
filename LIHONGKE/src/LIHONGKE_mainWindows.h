#ifndef LIHONGKE_MAINWINDOWS_H
#define LIHONGKE_MAINWINDOWS_H

#include <QMainWindow>
#include <framework/Wid_Framework.hpp>

namespace Ui {
class LIHONGKE_mainWindows;
}

class LIHONGKE_mainWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit LIHONGKE_mainWindows(QWidget *parent = nullptr);
    ~LIHONGKE_mainWindows();
    
    // 新建工程 
    void createProject();
    // 保存工程
    bool save();
    // 读取工程
    bool load();

private:

    // 布局&样式
    void style();
    // 槽函数
    void this_connect();

private:
    Ui::LIHONGKE_mainWindows  *ui;
    framework::Wid_Framework  *wid_framework;  // 流程工具
};

#endif // LIHONGKE_MAINWINDOWS_H
