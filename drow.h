#ifndef DROW_H
#define DROW_H
#include<string>
#include "player.h"
using namespace std;
class Drow :public Player{
    public:
       Drow(double hp = 150, double atk = 25, double def = 15);
};


#endif
