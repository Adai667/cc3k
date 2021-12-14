#include "goblin.h"
#include "enemy.h"
#include <math.h>
#include <cstdlib>
#include <iostream>
using namespace std;

Goblin::Goblin(double &hp, double &atk, double &def):Player{hp,atk,def,"Goblin"}
{
   setmaxHP(hp);
   setAttackBonus(0);
   setMissChance(0);
}

