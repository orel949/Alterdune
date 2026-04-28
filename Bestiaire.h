#ifndef BESTIAIRE_H
#define BESTIAIRE_H
#include<string>
#include<iostream>
#include<vector>
using namespace std;

class Bestiaire {
private:
    string nom;
    string categorie;
    int hpMax;
    int atk;
    int def;
    int resultat; 

public:
    Bestiaire(string nom, string categorie, int hpMax, int atk, int def, int resultat);
    string getNom();
    string getCategorie();
    int getHpMax();
    int getAtk();
    int getDef();
    int getResultat();
    void afficher();
};

#endif