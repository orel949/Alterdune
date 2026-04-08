#ifndef ACTION_H
#define ACTION_H
#include<string>
using namespace std;

class Action{
private:
    string id;
    string texte;
    int impact;

public:
    Action(string id, string texte, int impact);
    string getId();
    string getTexte();
    int getImpact();
};

#endif