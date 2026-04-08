#ifndef PLAYER_H
#define PLAYER_H
#include "Item.h"
#include <vector>
#include <string>
using namespace std;

class Player{
private:
    string nom;
    int hp;
    int hpMax;
    int nbTues;
    int nbEpargnes;
    int nbVictoires;
    vector<Item> inventaire;
public:
    Player(string nom);
    string getNom();
    int getHp();
    int getHpMax();
    int getNbTues();
    int getNbEpargnes();
    int getNbVictoires();
    vector<Item> getInventaire();
};

#endif