#include "Combat.h"

Combat::Combat(Player& joueur, Monster* monstre): joueur(joueur){
    this->monstre=monstre;
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
        case 1: 
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
        case 2: 
            
        case 3: // ITEM
            // ...
        case 4: // MERCY
            // ...
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
