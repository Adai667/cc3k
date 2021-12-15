#ifndef ITEMS_H
#define ITEMS_H
using namespace std;
#include <string>
#include "player.h"

class Items {
    string name;
    int posnX;
    int posnY;
    protected:
    Player *player;
    
    public:
    Player *getPlayer();
    string getName();
    void getPosn(int &xCor, int &yCor);
    void setPosn(int xCor, int yCor);
    Items(string name, Player *player);
    virtual ~Items();
};

#endif
