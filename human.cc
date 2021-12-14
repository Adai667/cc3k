#include "human.h"
Human::Human():Enemy{140,20,20,"Human"}
{
  setSymbol('H');
  setHostile(true);
  setmaxHP(140);
  setAttackBonus(0);
  setMissChance(0);
}
