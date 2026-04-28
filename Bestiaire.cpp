#include "Bestiaire.h"
#include <iostream>
using namespace std;

Bestiaire::Bestiaire(string nom, string categorie, int hpMax, int atk, int def, int resultat)
    : nom(nom), categorie(categorie), hpMax(hpMax), atk(atk), def(def), resultat(resultat) {}

string Bestiaire::getNom(){
    return nom; 
}
string Bestiaire::getCategorie(){
    return categorie; 
}
int Bestiaire::getHpMax(){ 
    return hpMax; 
}
int Bestiaire::getAtk(){
    return atk; 
}
int Bestiaire::getDef(){
    return def; 
}
int Bestiaire::getResultat(){
    return resultat; 
}
void Bestiaire::afficher(){
    cout << "- " << nom << " [" << categorie << "] "
     << "HP:" << hpMax << " ATK:" << atk << " DEF:" << def << " | ";

    if (resultat == 1){
        cout << "Tue";
    }
    else{
        cout << "Epargne";
    }
    cout << endl;
}