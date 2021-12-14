#include "gold.h"
#include <iostream>

bool Gold::isProtected() {;
    return pro;
}

void Gold::beingPicked() {
    string goldName = getName();
    int newTotalGold = 0;
    getPlayer()->getGold( newTotalGold );
    newTotalGold += value;
    getPlayer()->setGold( newTotalGold );
    cout << endl<< "[ Picked Treasure: " << goldName << " ]" << endl;
}
Enemy* Gold::getProtector()
{
   return protector ;
}
Gold::Gold(string name, Player *player, Enemy *protector, int value,bool b)
    : Items{ name, player }, protector{ protector }, value{ value },pro{b} {}
void Gold::setProtected(bool &b)
{
   pro = b;
}
Gold::~Gold() {}
