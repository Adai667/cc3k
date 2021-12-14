#include "restorehealth.h"

RestoreHealth::RestoreHealth(Player *player)
    : Potion{ "RH", player, "Potion effect: restore up to 10 HP", 10 } {}
