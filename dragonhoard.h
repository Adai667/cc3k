#ifndef DRAGONHOARD_H
#define DRAGONHOARD_H
#include "gold.h"

class DragonHoard :public Gold {
    public:
    DragonHoard(Player *player,  Enemy *protector);
};

#endif
