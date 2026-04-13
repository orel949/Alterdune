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