#include "poisonhealth.h"

PoisonHealth::PoisonHealth(Player *player)
    : Potion{ "PH", player, "Potion effect: lose up to 10 HP", -10 } {}
