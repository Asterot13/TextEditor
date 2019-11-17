#include "mainwindow.h"

#include <QApplication>
#include <QStatusBar>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    QString style(":/rec/style.txt");
    QFile file(style);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        w.statusBar()->showMessage("style not assigned");
        return a.exec();
    }
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
    qApp->setStyleSheet(text);
    return a.exec();
}
