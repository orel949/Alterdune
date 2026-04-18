#include "Combat.h"

Combat::Combat(Player& joueur, Monster* monstre): joueur(joueur){
    this->monstre=monstre;
}

int Combat::lancerCombat(){
    cout << "\n=== COMBAT CONTRE " << monstre->getNom() << " ===" << endl;
    
    while(true){
        int resultatJoueur = tourJoueur();     
        if (resultatJoueur == 1){
            return 1;
        }
        if (resultatJoueur == 2){
            return 2;
        }
        tourMonstre();
        if (joueur.getHp() == 0){
            return 3;
        }
    }
}

int Combat::tourJoueur(){

    int choix;
    while(true){
        cout << "\n--- Tour du Joueur ---" << endl;
        cout << monstre->getNom() << " HP: " << monstre->getHp() << "/" << monstre->getHpMax() << endl;
        cout << "Mercy: " << monstre->getMercy() << "/" << monstre->getMercyMax() << endl;
        cout << "\n1. FIGHT  2. ACT  3. ITEM  4. MERCY" << endl;
        cout << "Choix : ";
    
        string input;
        getline(cin, input);

        try {
            choix = stoi(input);
            break;
        } 
        catch (...) {
            cout << "Entrée invalide (pas un nombre). Réessaie !" << endl;
            cout<<endl;
            continue;
        }
    }

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, monstre->getHpMax());
    int degats = dist(gen);

    switch(choix){
        case 1: {
            if (degats == 0){
                cout << joueur.getNom() << " rate sont attaque !" << endl;
            } 
            else {
                cout << joueur.getNom() << " inflige " << degats << " degats !" << endl;
                monstre->subirDegats(degats);
            }
            if (monstre->getHp()==0){
                cout << joueur.getNom() << " a vaincu "<<monstre->getNom()<<endl;
                return 1;
            }
            else{
                return 0;
            }
        }
        case 2: {
            vector<string> actions = monstre->getIdAct();
            cout << "Actions disponibles :" << endl;
            for (int i=0; i<actions.size(); i++){
                cout << i+1 << ". " << actions[i] << endl;
            }

            int choixAct;
            while(true){
                string input;
                getline(cin,input);
                try {
                    choixAct = stoi(input);
                    if (choixAct >= 1 && choixAct <= actions.size()){
                        break;
                    }
                    else {
                        cout << "Choix invalide, entre 1 et " << actions.size() << endl;
                    }
                }    
                catch (...) {
                    cout << "Entrée invalide (pas un nombre). Réessaie !" << endl;
                    cout<<endl;
                    continue;
                }
            }
            vector<Action> catalogue = getCatalogue();
            string idChoisi = actions[choixAct-1];
            for (int i=0; i<catalogue.size(); i++){
                if (catalogue[i].getId() == idChoisi){
                    cout << catalogue[i].getTexte() << endl;
                    monstre->modifMercy(catalogue[i].getImpact());
                    break;
                }
            }
            return 0;
        }
        case 3: {
            joueur.getInventaire().afficherInventaire();
    
            int choixItem;
            while(true){
                cout << "Choix : ";
                string input;
                getline(cin, input);
                try {
                    choixItem = stoi(input);
                    if (choixItem >= 1 && choixItem <= joueur.getInventaire().getTaille()){
                        if (joueur.getInventaire().getItem(choixItem-1).getQuantite() <= 0){
                            cout << "Cet item est épuisé, choisis un autre !" << endl;
                        }
                        else {
                            break;
                        }
                    }
                    else {
                        cout << "Choix invalide !" << endl;
                    }
                }
                catch(...){
                    cout << "Entrée invalide !" << endl;
                }
            }
            int soin = joueur.getInventaire().utiliserItem(choixItem-1);
            joueur.soigner(soin);
            cout << "Vous avez récupéré " << soin << " HP !" << endl;
            return 0;
        }
        case 4: {
            if (monstre->getMercy() >= monstre->getMercyMax()){
                cout << "Vous épargnez " << monstre->getNom() << " !" << endl;
                return 2;
            }
            else {
                cout << "La Mercy n'est pas encore assez haute !" << endl;
                cout << "Mercy : " << monstre->getMercy() << "/" << monstre->getMercyMax() << endl;
                return 0;
            }
        }
        default:
            cout << "Choix invalide !" << endl;
            return tourJoueur();
    }
}

void Combat::tourMonstre(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, joueur.getHpMax());
    int degats = dist(gen);
    
    if (degats == 0){
        cout << monstre->getNom() << " rate son attaque !" << endl;
    } else {
        cout << monstre->getNom() << " inflige " << degats << " degats !" << endl;
        joueur.subirDegats(degats);
    }
    cout << "HP joueur : " << joueur.getHp() << "/" << joueur.getHpMax() << endl;
}
