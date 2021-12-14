#ifndef GOBLIN_H
#define GOBLIN_H
#include<string>
#include "player.h"
using namespace std;
class Goblin :public Player{
    public:
       Goblin(double &hp,double &atk,double &def);
};


#endif
