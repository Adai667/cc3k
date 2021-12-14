#include "dragon.h"
#include "player.h"
#include <iostream>
using namespace std;

Dragon::Dragon():Enemy{150,20,20,"Dragon"}
{
  setSymbol('D');
  setHostile(true);
  setmaxHP(150);
  setAttackBonus(0);
  setMissChance(0);
}

