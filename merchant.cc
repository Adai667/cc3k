#include "merchant.h"
#include "player.h"
#include <cmath>
#include <iostream>
using namespace std;

Merchant::Merchant():Enemy{30,70,5,"Merchant"}
{
  setSymbol('M');
  setHostile(false);
  setmaxHP(30);
  setAttackBonus(0);
  setMissChance(0);
}

