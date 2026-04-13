#include "BossMonster.h"

BossMonster::BossMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax):Monster(categorie,nom,hpMax,atk,def,mercyMax){}
int BossMonster::getNbActions(){
    return 4;
}
