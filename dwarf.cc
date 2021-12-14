#include "dwarf.h"
Dwarf::Dwarf():Enemy{100,20,30,"Dwarf"}
{
  setSymbol('W');
  setHostile(true);
  setmaxHP(100);
  setAttackBonus(0);
  setMissChance(0);
}
