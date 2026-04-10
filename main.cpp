#include "Item.h"
#include "Action.h"
#include "Player.h"
#include "Inventaire.h"
#include<iostream>
#include<string>
#include <fstream>
#include <sstream>
using namespace std;

void menu(){
    cout << "\n===== MENU DE SIMULATION =====" << endl;
    cout << "1. Bestiaire (bitacora de monstres)" << endl;
    cout << "2. Demarrer un combat" << endl;
    cout << "3. Statistiques du personnage" << endl;
    cout << "4. Items" << endl;
    cout << "5. Quitter" << endl;
    cout << "Choix : ";
}

void chargerItems(Player& joueur){
    ifstream fichier("item.csv");
    if(!fichier){
        cout << "Le fichier est introuvable ! ERREUR !"<<endl;
    }
    string ligne;
    while(getline(fichier, ligne)){
        if (!ligne.empty()){
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

            Item item = Item(nom,type,valeur,quantite);
            joueur.ajouterItem(item);
        }
    }
}

void afficherInventaire(Player& joueur){
    joueur.getInventaire().afficherInventaire();
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
    chargerItems(joueur1);
    int choix;
    string input;

    do {
        menu();
        getline(cin, input);

        try {
            choix = stoi(input);
        } 
        catch (...) {
            cout << "Entrée invalide (pas un nombre). Réessaie !" << endl << endl;
            continue;
        }

        switch (choix) {
            case 1:
                cout << "Ouverture du bestiaire..." << endl;
                cout<<endl;
                break;
            case 2:
                cout << "Lancement du combat..." << endl;
                cout<<endl;
                break;
            case 3:
                cout << "Affichage des statistiques..." << endl;
                cout<<endl;
                afficherStatJoueur(joueur1);
                break;
            case 4:
                cout << "Ouverture des items..." << endl;
                cout<<endl;
                afficherInventaire(joueur1);
                break;
            case 5:
                cout << "Fermeture du jeu..." << endl;
                cout<<endl;
                break;
            default:
                cout << "Choix invalide, reessaye !" << endl;
                cout<<endl;
        }

    } while (choix != 5);

    return 0;
}