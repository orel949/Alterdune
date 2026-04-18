#include "Player.h"

Player::Player(){}
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
void Player::subirDegats(int degats){
    if (hp-degats<0){
        hp=0;
    }
    else{
        hp-=degats;
    }
}
void Player::soigner(int soin){
    if (hp+soin>hpMax){
        hp=hpMax;
    }
    else{
        hp+=soin;
    }
}
void Player::ajouterVictoire(){
    nbVictoires++;
}
void Player::ajouterTue(){
    nbTues++;
}
void Player::ajouterEpargne(){
    nbEpargnes++;
}