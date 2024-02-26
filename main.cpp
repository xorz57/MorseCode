#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication application(argc, argv);
    application.setStyle("Fusion");
    MainWindow mainWindow;
    mainWindow.show();
    return application.exec();
}
