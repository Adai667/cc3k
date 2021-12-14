#include "woundatk.h"

WoundAtk::WoundAtk(Player *player)
    : Potion{ "WA", player, "Potion effect: decrease Atk by 5", -5 } {}
