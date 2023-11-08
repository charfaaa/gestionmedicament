#ifndef MEDICAMENT_H
#define MEDICAMENT_H

#include <QObject>
#include <QWidget>
#include <QString>
#include <QDate>
#include <QSqlQueryModel>

class Medicament
{
public:
    Medicament();

    Medicament(int code, QString nom, QString type, QDate dateNaissance, QString prix , int qte);

    // Getters
    int getcode() const;
    QString getnom() const;
    QString gettype() const;
    QDate getdateNaissance() const;
    QString getprix() const;
    int getqte() const;

    // Setters
    void setcode(int code);
    void setnom(const QString &nom);
    void settype(const QString &type);
    void setdateNaissance(const QDate &dateNaissance);
    void setprix(const QString &prix);
    void setqte(int qte);

    bool ajouter();
    static QSqlQueryModel* afficher();
    static bool supprimer(int code);
    static Medicament findBycode(int code);
    bool modifier();


    static void imprimer(int code);
    static QSqlQueryModel* trie(QString croissance, QString critere);
    static QHash<QString, int> getqteDistribution();

private:
    int code;
    QString nom;
    QString type;
    QDate dateNaissance;
    QString prix;
    int qte;
};

#endif // MEDICAMENT_H
