#ifndef MINIBOSSMONSTER_H
#define MINIBOSSMONSTER_H
#include"Monster.h"
#include <string>
using namespace std;

class MiniBossMonster : public Monster{
public:
    MiniBossMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax);
    int getNbActions() override;
};

#endif