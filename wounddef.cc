#include "wounddef.h"

WoundDef::WoundDef(Player *player)
    : Potion{ "WD", player, "Potion effect: decrease Def by 5", -5 } {}
