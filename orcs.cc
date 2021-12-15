#include "orcs.h"
#include "player.h"
#include <random>
#include <cmath>
#include <iostream>
using namespace std;

Orcs::Orcs():Enemy{180,30,25,"Orcs"}
{
  setSymbol('O');
  setHostile(true);
  setmaxHP(180);
  setAttackBonus(0);
  setMissChance(0);
}

void Orcs::attack(Player* player) {
    random_device random_device;mt19937 engine{random_device()};uniform_int_distribution<> dist(0,1);
    auto n = dist(engine);
    string playerRace;
    player->getRace(playerRace);
    char sym;
    getSymbol(sym);
    if (n == 1) 
    {
        double playerDef;
        player->getDef(playerDef);
        double enemyAtk;
        getAtk(enemyAtk);
        if (playerRace != "Goblin") {
          player->loseHP(ceil(( 100 / (100 + playerDef)) * enemyAtk));
          cout << " " << sym << " deals " << ceil(( 100 / (100 + playerDef)) * enemyAtk)
         << " damage to PC." << endl<<": ";
        } 
	else 
	{
          player->loseHP(ceil(( 1.5 * 100 / (100 + playerDef)) * enemyAtk));
          cout << " " << sym << " deals " << ceil((1.5 * 100 / (100 + playerDef)) * enemyAtk)
          << " damage to PC." << endl<<": ";
        }
        
    } 
    else 
   {
      cout << " " << sym << " missed. " << endl;
   }   
}
