#include "Item.h"

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
int Item::utiliser(){
    if (quantite>=1){
        quantite--;
        return valeur;
    }
    return 0;
}
void Item::afficherItem(){
    cout << "Nom : "<<nom<<" / ";
    cout << "Type : "<<type<<" / ";
    cout << "Valeur : "<<valeur<<" / ";
    cout << "Quantité : "<<quantite<<endl;
}