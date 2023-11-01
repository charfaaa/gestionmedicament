#ifndef CLIENT_H
#define CLIENT_H
#include<QString>
#include <QSqlQuery>
#include <QObject>
#include <QMainWindow>
#include <QSqlError>
#include<QSqlQueryModel>
#include<iostream>
using namespace std;
class medicament {
    public:
        medicament();
        medicament(QString,QString,QString,QString,int,int);

        //virtual ~Client();


        QString Getcode() { return code; }
        void Setcode(QString val) { code = val; }
        QString Gettype() { return type; }
        void Settype(QString val) { type = val; }
        QString Getnom() { return nom; }
        void Setnom(QString val) { nom = val; }
        QString Getqte() { return qte; }
        void Setqte(QString val) { qte = val; }

        int Getprix() { return prix; }
        void Setprix(int val) { prix = val; }
        int Getddp() { return ddp; }
        void Setddp(int val) { ddp = val; }

        QString code;
        QString nom;
        QString qte;
        QString type;
        int ddp;
        //crud
        bool ajouter();
        QSqlQueryModel*afficher();
        bool supprimer(QString);
        bool modifier(QString);
    protected:

    private:
        int prix;
};

#endif // CLIENT_H
