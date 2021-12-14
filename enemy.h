#ifndef ENEMY_H
#define ENEMY_H
#include<string>
#include "gold.h"
#include "character.h"
using namespace std;
class Player;
class Enemy :public Character{
    bool hostile;
    int chambernumber;
    char symbol;
//    Gold goldpile;
    public:
       Enemy(double hp, double atk, double def,string race);
       void setHostile(bool hos);
       bool getHostile();
       void becomeHostile();
       void dropGold();
       void setChambernumber(int n);void getChambernumber(int &n);
       void setSymbol(char a); void getSymbol(char &a);
       ////
       virtual void attack(Player* player);
       virtual ~Enemy();
};


#endif
