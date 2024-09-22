#ifndef LIHONGKE_MAINWINDOWS_H
#define LIHONGKE_MAINWINDOWS_H

#include <QMainWindow>
#include <framework/Wid_Framework.hpp>

namespace Ui {
class LIHONGKE_mainWindows;
}

/**
 * 主工程
 * 
 * * 新建工程
 * * 读取工程
 * * 保存工程
 * 
 * - 流程区块
 * - 工作视图区块
 */
class LIHONGKE_mainWindows : public QMainWindow
{
    Q_OBJECT

public:
    explicit LIHONGKE_mainWindows(QWidget *parent = nullptr);
    ~LIHONGKE_mainWindows();
    
    // 新建工程 
    void createProject();

    // 保存工程
    bool saveProject();
    
    // 读取工程
    bool loadProject();

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
