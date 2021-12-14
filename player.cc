#include "player.h"
#include "enemy.h"
#include <iostream>
#include <cmath>
#include <random>
#include <string>
Player::Player(double &hp, double &atk, double &def ,string race)
   : Character(hp,atk,def,race),totalgold{0},score{0},levelover{false}{}

void Player::learnNewPotion(string potionName) {
   learnedPotions.emplace_back(potionName);
}

bool Player::haveLearnPotion(string potionName) {
   bool haveLearned = false;
   for (auto p : learnedPotions) {
      if (p == potionName) {haveLearned = true; break;}
   }
   return haveLearned;
}

void Player::setGold(int g)
{
   totalgold = g;
}

void Player::getGold(int &g)
{
   g = totalgold;
}

Player::~Player(){}

void Player::attack(Enemy* enemy) {
   double enemyDef;
   enemy->getDef(enemyDef);
   double playerAtk;
   getAtk(playerAtk);
   string playerrace;
   getRace(playerrace);
   double playerHP;
   getHP(playerHP);
   random_device random_device;mt19937 engine{random_device()};uniform_int_distribution<> dist(0,1);
   auto n = dist(engine);
   string enemyRace;
   enemy->getRace(enemyRace);
   if (enemyRace == "Halfling") 
   {
      if(n == 0) {cout << " You missed. ";return;}
   }
  
   enemy->loseHP(ceil(( 100 / (100 + enemyDef)) * playerAtk));
   cout << " PC deals " << ceil(( 100 / (100 + enemyDef)) * playerAtk) << " damage to ";
   char sym;
   enemy->getSymbol(sym);
   cout << sym;
   double enemyHP;
   enemy->getHP(enemyHP);
   if (enemyHP >= 0) 
      {
      cout << " (" << enemyHP << " HP). ";
      } 
   else 
      {
         bool death = true;
	 enemy->setDeath(death);
         cout << " (" << 0 << " HP). ";
      }
   if(playerrace == "Vampire")
   {
      if(enemyRace == "dwarf") {setHP(playerHP + 5);cout << "PC lose 5 HP.";}
      else 
      {
         setHP(playerHP + 5);
         cout << "PC regains 5 HP.";
      }
   }
   
}
