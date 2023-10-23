#include "dialog.h"
#include "ui_dialog.h"


Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}
void Dialog::setmedicament(medicament m)
{
    ui->lineEdit_nomoucode->setText(m.get_nom());
    ui->lineEdit_tupe->setText(m.get_type());
    ui->lineEdit_prix->setText(m.get_prix());
    ui->lineEdit_quan->setText(m.get_quantite());
}
