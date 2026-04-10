#ifndef MONSTER_H
#define MONSTER_H
#include <string>
#include <vector>
using namespace std;

class Monster{
private:
    string categorie;
    string nom;
    int hp;
    int hpMax;
    int atk;
    int def;
    int mercy;
    int mercyMax;
    vector<string> idACT;
public:
    Monster(string categorie, string nom, int hpMax, int atk,int def,int mercyMax);
    string getCategorie();
    string getNom();
    int getHp();
    int getHpMax();
    int getAtk();
    int getDef();
    int getMercy();
    int getMercyMax();
    vector<string> getIdAct();
    virtual int getNbActions()=0;
    virtual ~Monster();
};

#endif