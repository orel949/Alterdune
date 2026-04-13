#include "Inventaire.h"

Inventaire::Inventaire(){}

void Inventaire::ajouterItem(Item item){
    inventaire.push_back(item);
}

void Inventaire::afficherInventaire(){
    for (int i=0;i<inventaire.size();i++){
        cout << "ITEM "<<i+1<<" : "<<endl;
        inventaire[i].afficherItem();
    }
}