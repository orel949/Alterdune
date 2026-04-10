#ifndef INVENTAIRE_H
#define INVENTAIRE_H
#include "Item.h"
#include <vector>
#include <string>
using namespace std;

class Inventaire{
private:
    vector<Item> inventaire;
public:
    Inventaire();
    void ajouterItem(Item item);
    void afficherInventaire();
};

#endif