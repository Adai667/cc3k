#include "enemy.h"
#include "gold.h"
#include "player.h"
#include <iostream>
#include <cmath>
#include <random>
using namespace std;

Enemy::Enemy(double hp, double atk, double def ,string race):Character(hp,atk,def,race),hostile{false}{}
void Enemy::setHostile(bool hos)
{
   hostile = hos;
}
bool Enemy::getHostile() {
    return hostile;
}
void Enemy::becomeHostile() {
    hostile = true;
}
void Enemy::setChambernumber(int n)
{
    chambernumber = n;
}
void Enemy::getChambernumber(int &n)
{
    n = chambernumber;
}
void Enemy::setSymbol(char a)
{
   symbol = a;
}
void Enemy::getSymbol(char &a)
{
    a = symbol;
}

Enemy::~Enemy(){}

void Enemy::dropGold() {
    ///
}

void Enemy::attack(Player* player) {
    random_device random_device;mt19937 engine{random_device()};uniform_int_distribution<> dist(0,1);
    auto n = dist(engine);
    char sym;
    getSymbol(sym);
    if(n == 0) {cout <<" "<< sym<<" missed. "<<endl<<": ";return;}
    
    double playerDef;
    player->getDef(playerDef);
    double enemyAtk;
    getAtk(enemyAtk);
    player->loseHP(ceil(( 100 / (100 + playerDef)) * enemyAtk));
    cout << endl << endl << "[ " << sym << " deals " << ceil(( 100 / (100 + playerDef)) * enemyAtk)
    << " damage to you ]" << endl<<": ";
        
     
}
