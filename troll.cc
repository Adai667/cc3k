#include "troll.h"
Troll::Troll(double &hp, double &atk, double &def):Player{hp,atk,def,"Troll"}
{
   setmaxHP(hp);
   setAttackBonus(0);
   setMissChance(0);
}
