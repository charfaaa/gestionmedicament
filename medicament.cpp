#include "Medicament.h"
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QObject>
#include <QPrinter>
#include <QPrintDialog>
#include <QPainter>

Medicament::Medicament()
{
    code = 0;
    qte = 0;
}
Medicament::Medicament(int code, QString nom, QString type, QDate dateNaissance, QString prix, int qte)
{
    this->code = code;
    this->nom = nom;
    this->type = type;
    this->dateNaissance = dateNaissance;
    this->prix = prix;
    this->qte = qte;
}
int Medicament::getcode() const {
    return code;
}

QString Medicament::getnom() const {
    return nom;
}

QString Medicament::gettype() const {
    return type;
}

QDate Medicament::getdateNaissance() const {
    return dateNaissance;
}

QString Medicament::getprix() const {
    return prix;
}

int Medicament::getqte() const {
    return qte;
}

// Setters
void Medicament::setcode(int code) {
    this->code= code;
}

void Medicament::setnom(const QString &nom) {
    this->nom = nom;
}

void Medicament::settype(const QString &type) {
    this->type = type;
}

void Medicament::setdateNaissance(const QDate &dateNaissance) {
    this->dateNaissance = dateNaissance;
}

void Medicament::setprix(const QString &prix) {
    this->prix = prix;
}

void Medicament::setqte(int qte) {
    this->qte = qte;
}

// CRUD
bool Medicament::ajouter()
{
    QSqlQuery q;
    q.prepare("INSERT INTO MEDICAMENT (code,nom, type, dateNaissance, prix,qte) VALUES (:code, :nom, :type, :dateNaissance, :prix, :qte)");
    q.bindValue(":code", code);
    q.bindValue(":nom", nom);
    q.bindValue(":type", type);
    q.bindValue(":dateNaissance", dateNaissance);
    q.bindValue(":prix", prix);
    q.bindValue(":qte", qte);

    return q.exec();
}
QSqlQueryModel* Medicament::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM MEDICAMENT");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("code"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("dateNaissance"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("prix"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("qte"));

    return model;
}

bool Medicament::supprimer(int code)
{
    QSqlQuery q;
    q.prepare("DELETE FROM MEDICAMENT WHERE code = :code");
    q.bindValue(":code", code);

    return q.exec();
}

Medicament Medicament::findBycode(int code)
{
    QSqlQuery q;
    q.prepare("SELECT * FROM MEDICAMENT WHERE code = :code");
    q.bindValue(":code", code);

    if (q.exec() && q.next()) {
        QString nom = q.value("nom").toString();
        QString type= q.value("type").toString();
        QDate dateNaissance = q.value("dateNaissance").toDate();
        QString prix = q.value("prix").toString();
        int qte = q.value("qte").toInt();
        return Medicament(code, nom, type , dateNaissance, prix , qte);
    }

    return Medicament();
}

bool Medicament::modifier()
{
    QSqlQuery q;
    q.prepare("UPDATE MEDICAMENT SET nom = :nom, type = :type, dateNaissance = :dateNaissance, prix = :prix, qte = :qte WHERE code = :code");
    q.bindValue(":nom", nom);
    q.bindValue(":type", type);
    q.bindValue(":dateNaissance", dateNaissance);
    q.bindValue(":prix", prix);
    q.bindValue(":qte", qte);
    q.bindValue(":code", code);

    return q.exec();
}

void Medicament::imprimer(int code)
{
    QString nom;
    int y0 = 2000;
    Medicament e = findBycode(code);

    QString pdfFileName = QString::number(e.getcode()) + "_" + e.getnom() + "_" + e.gettype() + ".pdf";

    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setFullPage(QPrinter::A4);
    printer.setOutputFileName(pdfFileName);

    QPainter painter(&printer);
    painter.setFont(QFont("Verdana", 30));
    painter.drawText(200, 1000, "Fiche des medicament");

    painter.setFont(QFont("Verdana", 12));
    y0 += 250;
    painter.drawText(400, y0, "Nom de l'Application : PharmaDeliver");
    y0 += 500;

    QFont titleFont("Verdana", 12, QFont::Bold);
    titleFont.setUnderline(true);
    titleFont.setCapitalization(QFont::AllUppercase);
    painter.setFont(titleFont);

    painter.setPen(QColor(Qt::darkBlue)); // Set color to dark blue

    QStringList subtitles = {
        "CODE",
        "NOM",
        "TYPE",
        "DATE DE NAISSANCE",
        "PRIX",
        "QUANTITE"
    };

    QStringList contents = {
        QString::number(e.getcode()),
        e.getnom(),
        e.gettype(),
        e.getdateNaissance().toString(),
        e.getprix(),
        QString::number(e.getqte())
    };

    for (int i = 0; i < subtitles.size(); ++i)
    {
        painter.drawText(400, y0, subtitles[i] + " :");
        painter.setFont(QFont("Verdana", 12)); // Set content font to normal
        painter.drawText(4000, y0, contents[i]);
        painter.setFont(titleFont); // Reset font to subtitle style
        y0 += 250;
    }

    painter.end();
}



QSqlQueryModel* Medicament::trie(QString croissance, QString critere)
{
    QSqlQueryModel* modal = new QSqlQueryModel();
    QSqlQuery query;

    QString sqlQuery = "SELECT * FROM MEDICAMENT ORDER BY %1 %2";
    sqlQuery = sqlQuery.arg(critere).arg(croissance);

    query.prepare(sqlQuery);
    if (query.exec()) {
        modal->setQuery(query);
    }

    return modal;
}

QHash<QString, int> Medicament::getqteDistribution()
{
    QHash<QString, int> qteDistribution;

    // Récupérez la liste des élèves depuis votre base de données
    // Par exemple, vous pouvez utiliser votre fonction afficher() pour obtenir une liste de tous les élèves.
    QSqlQueryModel* model = afficher();

    // Calculez l'âge de chaque élève et mettez à jour la répartition par âge
    QDateTime now = QDateTime::currentDateTime();
    for (int row = 0; row < model->rowCount(); ++row) {
        int qte = model->data(model->index(row, 6)).toInt(); // Supposons que la date de naissance est dans la colonne 3

        // Classifiez l'âge dans des groupes
        QString qteGroup;
        if (qte < 2) {
            qteGroup = "Moins de 2 ans";
        } else if (qte < 4) {
            qteGroup = "2-4 ans";
        } else if (qte < 6) {
            qteGroup = "4-6 ans";
        } else {
            qteGroup = "6 ans et plus";
        }

        // Mettez à jour la répartition par âge
        if (qteDistribution.contains(qteGroup)) {
            qteDistribution[qteGroup]++;
        } else {
            qteDistribution[qteGroup] = 1;
        }
    }

    return qteDistribution;
}

