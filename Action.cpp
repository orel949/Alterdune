#include "Action.h"

Action::Action(string id, string texte, int impact){
    this->id=id;
    this->texte=texte;
    this->impact=impact;
}
string Action::getId(){
    return this->id;
}
string Action::getTexte(){
    return this->texte;
}
int Action::getImpact(){
    return this->impact;
}

vector<Action> getCatalogue(){
    vector<Action> catalogue;
    catalogue.push_back(Action("JOKE", "Tu racontes une blague nulle... le monstre ricane.", 10));
    catalogue.push_back(Action("COMPLIMENT", "Tu fais un compliment sincere... le monstre rougit.", 25));
    catalogue.push_back(Action("INSULTE", "Tu insultes le monstre... il se met en colere !", -15));
    catalogue.push_back(Action("DANSE", "Tu fais faire une danse au monstre... le monstre se sent ridicule.", -15));
    catalogue.push_back(Action("RAGEBAIT", "Tu te moques de lui... le monstre est furieux !", -20));
    catalogue.push_back(Action("NOURRITURE", "Tu lui proposes un fast food... le monstre accepte et se régale.", 15));
    catalogue.push_back(Action("BOISSON", "Tu lui proposes une boisson... le monstre se detend.", 10));
    catalogue.push_back(Action("TROLL", "Tu te moques de lui... le monstre s'enerve !", -10));
    return catalogue;
}