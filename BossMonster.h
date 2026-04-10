#ifndef BOSSMONSTER_H
#define BOSSMONSTER_H
#include"Monster.h"
#include <string>
using namespace std;

class BossMonster : public Monster{
public:
    BossMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax);
    int getNbActions() override;
};

#endif