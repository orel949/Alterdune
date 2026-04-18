#include "Game.h"

Game::Game(string nom){
    this->joueur=Player(nom);
}

void Game::chargerItems(){
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

vector<Monster*> Game::chargerMonstres(){
    vector<Monster*> listeMonstres;
    ifstream fichier("monsters.csv");
    if(!fichier){
        cout << "Le fichier est introuvable ! ERREUR !"<<endl;
        return listeMonstres;
    }
    string ligne;
    while(getline(fichier, ligne)){
        if (!ligne.empty()){
            stringstream ss(ligne);
            string categorie;
            string nom;
            string hp_str;
            string atk_str;
            string def_str;
            string mercy_str;
            getline(ss, categorie, ';');     
            getline(ss, nom, ';');
            getline(ss,hp_str,';');
            getline(ss,atk_str,';'); 
            getline(ss,def_str,';');   
            getline(ss,mercy_str,';'); 
            int hp = stoi(hp_str);
            int atk= stoi(atk_str);
            int def= stoi(def_str);
            int mercy=stoi(mercy_str);
            string action;
            vector<string> actions;
            while(getline(ss, action, ';')){
                if (action == "-" || action.empty()){
                    break;
                }
                actions.push_back(action);
            }
            if (actions.size()==2){
                listeMonstres.push_back(new NormalMonster(categorie,nom,hp,atk,def,mercy));
                listeMonstres[listeMonstres.size()-1]->setIdACT(actions);
            }
            else if (actions.size()==3){
                listeMonstres.push_back(new MiniBossMonster(categorie,nom,hp,atk,def,mercy));
                listeMonstres[listeMonstres.size()-1]->setIdACT(actions);
            }
            else if (actions.size()==4){
                listeMonstres.push_back(new BossMonster(categorie,nom,hp,atk,def,mercy));
                listeMonstres[listeMonstres.size()-1]->setIdACT(actions);
            }
        }
    }
    return listeMonstres;
}

void Game::afficherMenu(){
    cout << "\n===== MENU DE SIMULATION =====" << endl;
    cout << "1. Bestiaire (bitacora de monstres)" << endl;
    cout << "2. Demarrer un combat" << endl;
    cout << "3. Statistiques du personnage" << endl;
    cout << "4. Items" << endl;
    cout << "5. Quitter" << endl;
    cout << "Choix : ";
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

void Game::lancerJeu(){

    chargerItems();
    this->monstres = chargerMonstres();
    int choix;
    string input;

    do {
        afficherMenu();
        getline(cin, input);

        try {
            choix = stoi(input);
        } 
        catch (...) {
            cout << "Entrée invalide (pas un nombre). Réessaie !" << endl;
            cout<<endl;
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
                afficherStatJoueur(this->joueur);
                break;
            case 4:
                cout << "Ouverture des items..." << endl;
                cout<<endl;
                afficherInventaire(this->joueur);
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
}