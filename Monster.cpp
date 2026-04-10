#include "Monster.h"
#include<string>
#include<iostream>
#include <vector>
using namespace std;

Monster::Monster(string categorie, string nom, int hpMax, int atk,int def,int mercyMax){
    this->categorie=categorie;
    this->nom=nom;
    this->hp=hpMax;
    this->hpMax=hpMax;
    this->atk=atk;
    this->def=def;
    this->mercy=0;
    this->mercyMax=mercyMax;
}

string Monster::getCategorie(){
    return this->categorie;
}
string Monster::getNom(){
    return this->nom;
}
int Monster::getHp(){
    return this->hp;
}
int Monster::getHpMax(){
    return this->hpMax;
}
int Monster::getAtk(){
    return this->atk;
}
int Monster::getDef(){
    return this->def;
}
int Monster::getMercy(){
    return this->mercy;
}
int Monster::getMercyMax(){
    return this->mercyMax;
}
vector<string> Monster::getIdAct(){
    return this->idACT;
}
Monster::~Monster(){}