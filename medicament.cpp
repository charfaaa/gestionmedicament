#include "medicament.h"
#include<QString>
#include<QObject>
#include <iostream>
using namespace std;
medicament::medicament(){
    code=" ";
    nom=" ";
    qte=" ";
    type=" ";
    ddp=0;
    prix=0;
}
medicament::medicament(QString code,QString nom,QString qte,QString type,int prix,int ddp){

    this->code=code;
    this->nom=nom;
    this->qte=qte;
    this->type=type;
    this->prix=prix;
    this->ddp=ddp;
}
bool medicament::ajouter(){
    QSqlQuery query;
    QString res =QString::number(prix);
    QString res2 =QString::number(ddp);
    query.prepare("insert into medicament(code,nom,qte,type,prix,ddp)""values(:code,:nom,:qte,:type,:prix,:ddp)");
query.bindValue(":code",code);
query.bindValue(":nom",nom);
query.bindValue(":qte",qte);
query.bindValue(":type",type);

query.bindValue(":prix",res);
query.bindValue(":ddp",res2);

return query.exec();
}
bool medicament::supprimer(QString code){
QSqlQuery query;
query.prepare("Delete from medicament where code=:code");
query.bindValue(":code",code);
return query.exec();
}
QSqlQueryModel *medicament::afficher(){
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from medicament");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("code"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("type"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("qte"));
    model->setHeaderData(4,Qt::Horizontal,QObject::tr("prix"));
    model->setHeaderData(5,Qt::Horizontal,QObject::tr("date p"));

return model;
}
bool medicament::modifier(QString code)
{
    QSqlQuery query;
    query.prepare("UPDATE medicament SET code=:code , nom=:nom , type= :type , qte= :qte,prix=:prix, ddp= :ddp WHERE code=:code");

    query.bindValue(":code",code);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":qte",qte);
    query.bindValue(":prix",prix);
    query.bindValue(":ddp",ddp);


    return query.exec();
}

