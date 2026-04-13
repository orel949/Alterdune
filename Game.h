#ifndef GAME_H
#define GAME_H
#include<string>
#include <iostream>
#include "Player.h"
#include "Monster.h"
#include "NormalMonster.h"
#include "MiniBossMonster.h"
#include "BossMonster.h"
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

class Game{
private:
    Player joueur;
    vector<Monster*> monstres;
public:
    Game(string nom);
    void chargerItems();
    vector<Monster*> chargerMonstres();
    void afficherMenu();
    void lancerJeu();
};

#endif