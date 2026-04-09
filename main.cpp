#include "Item.h"
#include "Action.h"
#include "Player.h"
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

void menu(){

}

void afficherInventaire(){
    ifstream fichier("item.csv");
    if(!fichier){
        cout << "Le fichier est introuvable ! ERREUR !"<<endl;
    }
    string ligne;
    int compteur=1;
    cout << "Voici l'inventaire initial : "<<endl;
    while(getline(fichier, ligne)){
        stringstream ss(ligne);
        string nom;
        string type;
        string valeur_str;
        string quantite_str;
        getline(ss, nom, ';');     
        getline(ss, type, ';');
        getline(ss,valeur_str,';');
        getline(ss,quantite_str,';');    
        int valeur = stoi(valeur_str);
        int quantite= stoi(quantite_str);
        cout << "ITEM "<<compteur<<" : "<<endl;
        cout << nom << " "<< type << " " << valeur << " "<<quantite<<endl;
        cout<<endl;
        compteur++;
    }
}

void afficherStatJoueur(Player joueur){
    cout<<endl;
    cout << "Nom du Joueur : "<<joueur.getNom()<<endl;
    cout << "Point de vie : "<<joueur.getHp()<<endl;
    cout << "Point de vie MAX : "<<joueur.getHpMax()<<endl;
    cout << "Nombre de monstres tués : "<<joueur.getNbTues()<<endl;
    cout << "Nombre de monstres épargnés : "<<joueur.getNbEpargnes()<<endl;
    cout << "Nombre de victoires : "<<joueur.getNbVictoires()<<endl;
    cout<<endl;
}



int main(){
    string nomPersonnage;
    cout << "Saisissez le nom de votre personnage"<<endl;
    cin >> nomPersonnage;

    Player joueur1 = Player(nomPersonnage);
    afficherStatJoueur(joueur1);
    afficherInventaire();

    return 0;
}