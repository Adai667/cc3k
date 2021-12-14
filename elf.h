#ifndef ELF_H
#define ELF_H
#include<string>
#include "enemy.h"
using namespace std;
class Elf :public Enemy{
    void attackOnce(Player *player);
    public:
       Elf();
       virtual ~Elf();
       void attack(Player *player);
};


#endif
