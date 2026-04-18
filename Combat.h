#ifndef COMBAT_H
#define COMBAT_H
#include<string>
#include <iostream>
#include <random>
#include "Player.h"
#include "Monster.h"

class Combat{
private:
    Player& joueur;
    Monster* monstre;
public:
    Combat(Player& joueur, Monster* monstre);
    int lancerCombat();
    int tourJoueur();
    void tourMonstre();
};
#endif