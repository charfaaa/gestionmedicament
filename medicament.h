#ifndef MEDICAMENT_H
#define MEDICAMENT_H
#include<QString>

class medicament
{
public:
    void setnom(QString n);
    void settype(QString n);
    void setprix(QString n);
    void setquantite(QString n);
    QString get_nom();
    QString get_type();
    QString get_prix();
    QString get_quantite();
    medicament();
private:
    QString nom, type, prix, quantite;

};

#endif // MEDICAMENT_H
