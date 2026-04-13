#include "NormalMonster.h"

NormalMonster::NormalMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax):Monster(categorie,nom,hpMax,atk,def,mercyMax){}
int NormalMonster::getNbActions(){
    return 2;
}
