#include "NormalMonster.h"
#include"Monster.h"
#include<string>
#include<iostream>
using namespace std;

NormalMonster::NormalMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax):Monster(categorie,nom,hpMax,atk,def,mercyMax){}
int NormalMonster::getNbActions(){
    return 2;
}
