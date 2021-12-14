#ifndef POTION_H
#define POTION_H
using namespace std;
#include <string>
#include "items.h"

class Potion :public Items {
    string effect;
    int effectPoints; // how many HP/Atk/Def it will effect;
                      // for example, RH has 10, PH has -10
    
    public:
    bool isUsed();
    void beingUsed();
    Potion(string name, Player *player, string effect, int effectPoints);
};

#endif
