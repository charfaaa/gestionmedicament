#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QString>
#include <QSqlQuery>
#include <QObject>
#include<QSqlQueryModel>
#include<iostream>
using namespace std;


class medicament {
    public:
        medicament();
        medicament(int,QString,QString,int,int,int);
        //virtual ~medicament();


        int Getcode() { return code; }
        void Setcode(int val) { code = val; }
        QString Getnom() { return nom; }
        void Setnom(QString val) { nom = val; }
        QString Gettype() { return type; }
        void Set(QString val) { type = val; }
        int Getqte() { return qte; }
        void Setqte(int val) { qte = val; }
        int Getprix() { return prix; }
        void Setprix(int val) { prix = val; }
        int Getddp() { return ddp; }
        void Setddp(int val) { ddp = val; }

        int code;
        QString nom;
        QString type;
        int qte;
        int ddp;
        //crud
        bool ajouter();
        QSqlQueryModel*afficher();
        bool supprimer(int);
    protected:

    private:
        int prix ;
};


#endif // MEDICAMENT_H
