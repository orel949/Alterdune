#include "Item.h"
#include<iostream>

Item::Item(string nom, string type, int valeur, int quantite){
    this->nom=nom;
    this->type=type;
    this->valeur=valeur;
    this->quantite=quantite;
}

string Item::getNom(){
    return this->nom;
}
string Item::getType(){
    return this->type;
}
int Item::getValeur(){
    return this->valeur;
}
int Item::getQuantite(){
    return this->quantite;
}
void Item::utiliser(){
    quantite--;
}