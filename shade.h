#ifndef SHADE_H
#define SHADE_H
#include<string>
#include "player.h"
using namespace std;
class Shade :public Player{
    public:
       Shade(double &hp,double &atk,double &def);
};


#endif
