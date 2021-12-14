#ifndef RESTOREHEALTH_H
#define RESTOREHEALTH_H
#include "potion.h"

class RestoreHealth :public Potion {
    public:
    RestoreHealth(Player *player);
};

#endif
