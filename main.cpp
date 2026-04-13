#include "Game.h"
#include<iostream>
#include<string>
using namespace std;

int main(){
    string nom;
    cout << "Saisissez le nom de votre personnage" << endl;
    getline(cin, nom);
    Game game = Game(nom);
    game.lancerJeu();
    return 0;
}