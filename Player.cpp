#include "Player.h"
#include "Item.h"
#include "Inventaire.h"
#include<vector>
#include<string>
#include<iostream>
using namespace std;

Player::Player(string nom){
    this->nom=nom;
    this->hpMax=100;
    this->hp=hpMax;
    this->nbTues=0;
    this->nbEpargnes=0;
    this->nbVictoires=0;
}
string Player::getNom(){
    return this->nom;
}
int Player::getHp(){
    return this->hp;
}
int Player::getHpMax(){
    return this->hpMax;
}
int Player::getNbTues(){
    return this->nbTues;
}
int Player::getNbEpargnes(){
    return this->nbEpargnes;
}
int Player::getNbVictoires(){
    return this->nbVictoires;
}
Inventaire& Player::getInventaire(){
    return this->inventaire;
}
void Player::ajouterItem(Item item){
    inventaire.ajouterItem(item);
}