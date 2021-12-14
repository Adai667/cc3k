#ifndef GAMESYS
#define GAMESYS
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "floor.h"
#include<string>
using namespace std;
class Gamesys
{
  Floor floor1,floor2,floor3,floor4,floor5;
  Player *player;  
  bool end;
  bool re;
  public:
     Gamesys();
     void startfloors(string floorfile,string chamberfile);
     void initposition(Character *sub, char symbol,Floor &floor);
     void initstair(Player *player,char symbol, Floor &floor);
     void initenemy(Floor &floor);
     void playgame(Floor &floor,int level);
     Floor& getfloor1();
     Floor& getfloor2();
     Floor& getfloor3();
     Floor& getfloor4();
     Floor& getfloor5();
     bool endgame();
     bool replay();
     void score();
     ~Gamesys();
};

#endif
