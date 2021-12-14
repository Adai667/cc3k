#ifndef ORCS_H
#define ORCS_H
#include<string>
#include "enemy.h"
using namespace std;
class Orcs :public Enemy{
    public:
       Orcs();
       void attack(Player* player);
};


#endif
