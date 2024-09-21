#include <QApplication>
#include "LIHONGKE_mainWindows.h"

#include "style/Style_main.hpp"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    
    app.setStyle(new Style_main(std::make_shared<StyleConfig_Base> ()));
    
    LIHONGKE_mainWindows *main_wid = new LIHONGKE_mainWindows();
    main_wid->show();
    
    return app.exec();
}
