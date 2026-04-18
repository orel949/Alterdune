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

int Inventaire::getTaille(){
    return inventaire.size();
}

int Inventaire::utiliserItem(int index){
    if (inventaire[index].getQuantite() <= 0){
        cout << "Cet item est épuisé !" << endl;
        return 0;
    }
    return inventaire[index].utiliser();
}

Item& Inventaire::getItem(int index){
    return inventaire[index];
}