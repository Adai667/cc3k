#ifndef VAMPIRE_H
#define VAMPIRE_H
#include<string>
#include "player.h"
using namespace std;
class Vampire :public Player{
    public:
       Vampire(double &hp,double &atk,double &def);
};


#endif
