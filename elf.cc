#include "elf.h"
#include "player.h"
#include "enemy.h"
#include <random>
#include <cmath>
#include <iostream>
using namespace std;

Elf::Elf():Enemy{140,30,10,"Elf"}
{
  setSymbol('E');
  setHostile(true);
  setmaxHP(140);
  setAttackBonus(0);
  setMissChance(0);
}
Elf::~Elf(){}

void Elf::attackOnce(Player *player) {
    random_device random_device;mt19937 engine{random_device()};uniform_int_distribution<> dist(0,1);
    auto n = dist(engine);
    char sym;
    getSymbol(sym);
    if (n == 1) 
    {
        double playerDef;
        player->getDef(playerDef);
        double enemyAtk;
        getAtk(enemyAtk);
        player->loseHP(ceil(( 100 / (100 + playerDef)) * enemyAtk));
        cout << " " << sym << " deals " << ceil(( 100 / (100 + playerDef)) * enemyAtk)
         << " damage to PC." << endl<<": ";
   } 
   else 
   {
      cout << " " << sym << " missed. ";
   } 
}

void Elf::attack(Player *player) {
    string playerRace;
    player->getRace(playerRace);
    if (playerRace != "Drow") {
        attackOnce(player);
        attackOnce(player);
	cout<<endl<<": ";
    } else {
        attackOnce(player);
    }
}
