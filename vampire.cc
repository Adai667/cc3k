#include "vampire.h"
#include "enemy.h"
#include <cstdlib>
#include <math.h>
#include <iostream>
using namespace std;

Vampire::Vampire(double &hp, double &atk, double &def):Player{hp,atk,def,"Vampire"}
{
  setmaxHP(-1);
  setAttackBonus(0);
  setMissChance(0);
}

