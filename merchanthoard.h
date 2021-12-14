#ifndef MERCHANTHOARD_H
#define MERCHANTHOARD_H
#include "gold.h"
#include "enemy.h"

class MerchantHoard :public Gold {
    public:
    MerchantHoard(Player *player);
};

#endif
