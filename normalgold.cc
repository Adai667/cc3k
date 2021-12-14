#include "normalgold.h"

const int NORMAL_GOLD_VAL = 2;

NormalGold::NormalGold(Player *player)
    : Gold{ "Normal Gold", player, nullptr, NORMAL_GOLD_VAL,false } {}
