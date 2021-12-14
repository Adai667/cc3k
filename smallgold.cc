#include "smallgold.h"

const int SMALL_GOLD_VAL = 1;

SmallGold::SmallGold(Player *player)
    : Gold{ "Small Gold", player, nullptr, SMALL_GOLD_VAL,false } {}
