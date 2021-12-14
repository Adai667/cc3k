#include "halfling.h"
Halfling::Halfling():Enemy{100,15,20,"Halfling"}
{
  setSymbol('L');
  setHostile(true);
  setmaxHP(100);
  setAttackBonus(0);
  setMissChance(0.5);
}
