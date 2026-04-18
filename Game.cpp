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
void Game::ajouterAuBestiaire(Monster* monstre, int resultat)
{
    EntreeBestiaire entree;
    entree.nom = monstre->getNom();
    entree.categorie = monstre->getCategorie();
    entree.hpMax = monstre->getHpMax();
    entree.atk = monstre->getAtk();
    entree.def = monstre->getDef();
    entree.resultat = resultat;

    bestiaire.push_back(entree);
}
void Game::afficherBestiaire()
{
    if(bestiaire.empty())
    {
        cout << "Le bestiaire est vide." << endl;
        cout << endl;
        return;
    }

    cout << "Bestiaire : " << endl;
    for(int i = 0; i < bestiaire.size(); i++)
    {
        cout << "Monstre " << i+1 << " :" << endl;
        cout << "Nom : " << bestiaire[i].nom << endl;
        cout << "Categorie : " << bestiaire[i].categorie << endl;
        cout << "HP max : " << bestiaire[i].hpMax << endl;
        cout << "ATK : " << bestiaire[i].atk << endl;
        cout << "DEF : " << bestiaire[i].def << endl;

        if(bestiaire[i].resultat == 1)
        {
            cout << "Resultat : Tue" << endl;
        }
        else
        {
            cout << "Resultat : Epargne" << endl;
        }

        cout << endl;
    }
}


void Game::lancerCombat()
{
    if(monstres.empty())
    {
        cout<<"Aucun monstre disponible !"<<endl;
        cout<<endl;
        return;
    }
    int index = rand() % monstres.size();
    Monster* monstre = monstres[index];
    cout << "Un monstre apparait !" << endl;
    cout << "Nom : " << monstre->getNom() << endl;
    cout << "Categorie : " << monstre->getCategorie() << endl;
    cout << "Nombre d'actions ACT : " << monstre->getNbActions() << endl;
    cout << endl;
    int resulatCombat=0; //test 
    //combat(joueur,monstre); voir en fct de ce que fait orel
    //int resulatCombat = combat.Match();
    if(resulatCombat==-1)
    {
        cout << "Le joueur a perdu le combat." << endl;
        exit(0);
    }
    else if(resulatCombat==0)
    {
        joueur.ajouterEpargne();
        joueur.ajouterVictoire();
        ajouterAuBestiaire(monstre, 0);
        cout << "Le monstre a ete epargne." << endl;
    }
    else if(resulatCombat==1)
    {
        joueur.ajouterTue();
        joueur.ajouterVictoire();
        ajouterAuBestiaire(monstre, 1);
        cout << "Le joueur a gagné le combat." << endl;
    }
    cout << endl;
    
    return;
    // if (joueur.getNbVictoires() >= 10) {
    //     //afficher une fin de partie
    // }
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
            cout << "Entrée invalide (pas un nombre). Réessaie !" << endl << endl;
            continue;
        }

        switch (choix) {
            case 1:
                cout << "Ouverture du bestiaire..." << endl;
                cout<<endl;
                afficherBestiaire();
                break;
            case 2:
                cout << "Lancement du combat..." << endl;
                cout<<endl;
                lancerCombat();
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