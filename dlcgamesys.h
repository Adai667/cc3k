#ifndef DLC_GAMESYS
#define DLC_GAMESYS
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "shade.h"
#include "vampire.h"
#include "drow.h"
#include "troll.h"
#include "goblin.h"
#include "floor.h"
#include "dlcfloor.h"
#include<string>
using namespace std;
class DlcGamesys{
  DlcFloor floor1,floor2,floor3,floor4,floor5;
  Player *player;  
  bool end;
  bool re;
  public:
     DlcGamesys();
     void startfloors(string floorfile,string chamberfile);
     void initposition(Character *sub, char symbol,DlcFloor &floor);
     void initstair(Player *player,char symbol, DlcFloor &floor);
     void initenemy(DlcFloor &floor);
     void playgame(DlcFloor &floor,int level, bool init);
     DlcFloor& getfloor1();
     DlcFloor& getfloor2();
     DlcFloor& getfloor3();
     DlcFloor& getfloor4();
     DlcFloor& getfloor5();
     bool endgame();
     bool replay();
     void score();
     ~DlcGamesys();
};

#endif
