#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication::setStyle("Fusion");
    QApplication application(argc, argv);

    MainWindow mainWindow;
    mainWindow.show();

    return QApplication::exec();
}
