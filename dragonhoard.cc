#include "dragonhoard.h"

const int DRAGON_HOARD_VAL = 6;

DragonHoard::DragonHoard(Player *player,  Enemy *protector)
    : Gold{ "Dragon Hoard", player, protector, DRAGON_HOARD_VAL, true } {}
