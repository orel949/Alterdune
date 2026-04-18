#ifndef GAME_H
#define GAME_H
#include<string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "Combat.h"
#include "NormalMonster.h"
#include "MiniBossMonster.h"
#include "BossMonster.h"
#include <vector>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
using namespace std;

class Game{
private:
    Player joueur;
    vector<Monster*> monstres;
    struct EntreeBestiaire
    {
        string nom;
        string categorie;
        int hpMax;
        int atk;
        int def;
        int resultat;
    };
    vector<EntreeBestiaire> bestiaire;
    
public:
    Game(string nom);
    void chargerItems();
    vector<Monster*> chargerMonstres();
    void afficherMenu();
    void lancerJeu();
    void lancerCombat();
    void ajouterAuBestiaire(Monster* monstre, int resultat);
    void afficherBestiaire();
    
};

#endif