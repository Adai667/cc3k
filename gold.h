#ifndef GOLD_H
#define GOLD_H
using namespace std;
#include <string>
#include "items.h"
#include "enemy.h"

class Gold :public Items {
    Enemy *protector;
    int value;
    bool pro;
    public:
    void setGold(int newVal);
    bool isProtected(); void setProtected(bool &b);
    void beingPicked();
    Enemy* getProtector();
    Gold(string name, Player *player, Enemy *protector, int value,bool b);
    virtual ~Gold();
};

#endif
