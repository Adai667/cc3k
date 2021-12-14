#ifndef TROLL_H
#define TROLL_H
#include<string>
#include "player.h"
using namespace std;
class Troll :public Player{
    public:
       Troll(double &hp,double &atk,double &def);
};


#endif
