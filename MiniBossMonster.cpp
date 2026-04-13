#include "MiniBossMonster.h"

MiniBossMonster::MiniBossMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax):Monster(categorie,nom,hpMax,atk,def,mercyMax){}
int MiniBossMonster::getNbActions(){
    return 3;
}
