#include "medicament.h"

medicament::medicament()
{
nom="";
    type="";
prix="";
    quantite="";
}
void medicament::setnom(QString n){nom=n;}
void medicament::settype(QString n){type=n;}
void medicament::setprix(QString n){prix=n;}
void medicament::setquantite(QString n){quantite=n;}
QString medicament::get_nom(){return nom;}
QString medicament::get_type(){return type;}
QString medicament::get_prix(){return prix;}
QString medicament::get_quantite(){return quantite;}

