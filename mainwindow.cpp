#include "ui_mainwindow.h"
#include"mainwindow.h"
#include"medicament.h"
#include"dialog.h"
#include"connection.h"
#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEdit->setValidator(new QIntValidator(0,99999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    medicament m;
    m.setnom(ui->lineEdit->text());
    m.settype(ui->lineEdit_1->text());
    m.setprix(ui->lineEdit_2->text());
    m.setquantite(ui->lineEdit_3->text());
    Dialog d;
    d.setmedicament(m);
    d.exec();

}




