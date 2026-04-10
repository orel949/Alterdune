#ifndef NORMALMONSTER_H
#define NORMALMONSTER_H
#include"Monster.h"
#include <string>
using namespace std;

class NormalMonster : public Monster{
public:
    NormalMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax);
    int getNbActions() override;
};

#endif