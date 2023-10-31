#include "medicament.h"
#include<QString>
#include<QObject>
#include <iostream>
using namespace std;
medicament::medicament(){
    code=0;
    nom=" ";
    type=" ";
    qte=0;
    prix=0;
    ddp=0 ;
}
medicament::medicament(int code,QString nom,QString type,int qte,int prix,int ddp){

    this->code=code;
    this->nom=nom;
    this->type=type;
    this->qte=qte;
    this->prix=prix;
    this->ddp=ddp;
}
bool medicament::ajouter(){
    QSqlQuery query;
    QString res =QString::number(ddp);
    query.prepare("insert into Client(code,nom,type,qte,prix,ddp,)""values(:code,:nom,:type,:qte,:prix,:ddp,)");
query.bindValue(":code",code);
query.bindValue(":nom",nom);
query.bindValue(":type",type);
query.bindValue(":qte",qte);
query.bindValue(":prix",prix);
query.bindValue("ddp",ddp);

return query.exec();
}
bool medicament::supprimer(int code){
QSqlQuery query;
query.prepare("Delete from medicament where code=:code");
query.bindValue(":code",code);
return query.exec();
}
QSqlQueryModel *medicament::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from Client");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(6,Qt::Horizontal,QObject::tr("qte"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("ddp"));
return model;
}
