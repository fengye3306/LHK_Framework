

#include <iostream>
#include <QApplication>

#include <framework/Wid_Framework.hpp>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv); 

    framework::Wid_Framework wid("./../framework_plugin/");
    wid.showNormal();
    
    return app.exec();
}
