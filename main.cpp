#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>
#include "medicament.h"
#include <QDebug>
#include<iostream>
using namespace std;

//AAPLICATION DESKTOP POUR GESTION DES medicaments
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Connection c;
    medicament m;
    qDebug();
    bool test=c.createconnect();
    MainWindow w;
    if(test)
    {w.show();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    return a.exec();
}
