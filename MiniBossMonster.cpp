#include "MiniBossMonster.h"
#include"Monster.h"
#include<string>
#include<iostream>
using namespace std;

MiniBossMonster::MiniBossMonster(string categorie, string nom, int hpMax, int atk, int def, int mercyMax):Monster(categorie,nom,hpMax,atk,def,mercyMax){}
int MiniBossMonster::getNbActions(){
    return 3;
}
