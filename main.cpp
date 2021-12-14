#include "mainwindow.h"
#include <QApplication>
#include <QSqlDatabase>
#include <QtDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    qDebug() << "Available SQL drivers:" << QSqlDatabase::drivers();
    w.show();
    return a.exec();
}
