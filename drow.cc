#include "drow.h"
Drow::Drow(double hp, double atk, double def):Player{hp,atk,def,"Drow"}
{
   setmaxHP(hp);
   setAttackBonus(0);
   setMissChance(0);
}
