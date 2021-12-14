#ifndef PLAYER_H
#define PLAYER_H
#include<string>
#include <vector>
#include "character.h"
class Enemy;
using namespace std;
class Player :public Character{
    int totalgold;
    int score;
    vector<string> learnedPotions;
       public:
       bool levelover;
       void learnNewPotion(string potionName);
       bool haveLearnPotion(string potionName);
       Player(double &hp, double &atk, double &def,string race);
       void setGold(int g); void getGold(int &g);
       void attack(Enemy* enemy);
       ~Player() override;
};


#endif
