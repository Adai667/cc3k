#include "shade.h"
Shade::Shade(double &hp, double &atk, double &def):Player{hp,atk,def,"Shade"}
{
   setmaxHP(hp);
   setAttackBonus(0);
   setMissChance(0);
}
