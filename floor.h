#ifndef FLOOR_H
#define FLOOR_H
#include<vector>
#include<string>
#include <memory>
#include "player.h"
#include "enemy.h"
#include "human.h"
#include "elf.h"
#include "dwarf.h"
#include "elf.h"
#include "orcs.h"
#include "merchant.h"
#include "halfling.h"
#include "gold.h"
#include "smallgold.h"
#include "normalgold.h"
#include "merchanthoard.h"
#include "dragonhoard.h"
#include "potion.h"
#include "restorehealth.h"
#include "poisonhealth.h"
#include "boostatk.h"
#include "woundatk.h"
#include "boostdef.h"
#include "wounddef.h"
#include "dragon.h"
using namespace std;

class Floor
{
    protected:
    struct coordinates{
    int x; int y;
    };
    int canmove;
    vector<string> ldata;
    vector<coordinates> chamber1,chamber2,chamber3,chamber4,chamber5;
    vector<Enemy*> enemies;
    vector<Gold*> golds;
    vector<Dragon*> dragons;
    vector<Potion*> potions;

    public:
    Floor();
    ~Floor();
    void startLevel(vector<string> lv,string chamber);
    void startFloor(string file,string chamber);
    void printFloor();
    void moveplayer(string in,Player *player);
    char gettile(int xcor,int ycor);
    void setCanmove(int i);
    void moveplayerhelp(Player *player,int new_x,int new_y);
    void settile(int xcor,int ycor,char cha);
    void getCoordinates(int chambernum,int &playerx,int &playery);
    void startenemy();
    virtual void moveEnemy();
    void moveEnemyhelp(Enemy *enemy,int new_x,int new_y);
    void startGold(Player *player);
    void startPotion(Player *player);
    Potion *getPotion(int targetX,int targetY);
    virtual vector<Enemy*> enemyAround(int xcor, int ycor);
    void removeEnemy(Enemy* enemy, int xcor, int ycor);
    void addGold(Gold *gold, int xcor, int ycor);
    virtual Enemy* findEnemy(int xcor, int ycor,vector<Enemy*> enemyAround);
    void removeDragon(int xcor, int ycor,Player *player);
    virtual void clean();
    void setM();
};



#endif
