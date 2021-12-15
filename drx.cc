#include "drx.h"
#include <random>
DrX::DrX():Enemy{1000,1,1,"DR.X"}
{
  setSymbol('X');
  setHostile(true);
  setmaxHP(1000);
  setAttackBonus(0);
  setMissChance(0);
}

DrX::~DrX(){}

virtual void DrX::attack(Player *player) {
    random_device random_device;mt19937 engine{random_device()};uniform_int_distribution<> dist(0,2);
    auto n = dist(engine);
    char sym;
    getSymbol(sym);
    if (n == 1) 
    {
        double playerHP;
        player->getHP(playerHP);
        player->loseHP(playerHP);
        cout << " " << sym << " deals " << playerHP << " damage to PC." << endl<<": ";
    } 
   else 
   {
      cout << " " << sym << " missed. ";
   } 
}

