#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
using namespace std;
#include"medicament.h"
#include"connection.h"
#include <iostream>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->tableView->setModel(m.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_ajouter_clicked()
{
 qDebug();
    int code=ui->lineEdit->text().toInt();
    QString nom=ui->lineEdit_2->text();
     QString type=ui->lineEdit_3->text();
      int ddp=ui->lineEdit_6->text().toInt();
      int prix=ui->lineEdit_5->text().toInt();
      int qte=ui->lineEdit_4->text().toInt();
      medicament m(code,nom,type,qte,prix,ddp);

bool test=m.ajouter();
if (test){
    QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("ajout avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" ajout non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_supp_clicked()
{
    int code=ui->lineEdit_9->text().toInt();
bool test=m.supprimer(code);
if (test)
 {   QMessageBox::information(nullptr, QObject::tr("ok"),
                QObject::tr("suppression avec success.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);
}
else
    QMessageBox::critical(nullptr, QObject::tr("not ok"),
                QObject::tr(" suppression non effectué.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}

