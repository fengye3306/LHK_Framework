

#include <iostream>

#include <QApplication>

#include <ImageRenderer/ImageRenderer.hpp>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); 

    // 如果你想在此处创建和显示 ImageRenderer 实例，可以添加如下代码：
    ImageRenderer renderer;
    renderer.show();

    return app.exec();
}
