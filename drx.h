#ifndef DRX_H
#define DRX_H
#include<string>
#include "enemy.h"
using namespace std;
// DR.X has 1/3 chance to cause a player to die when in the same chamber
class DrX :public Enemy{
    public:
       DrX();
       virtual ~DrX();
       virtual void attack(Player *player);
};


#endif