#include "gamesys.h"
#include <string>
#include <vector>
#include <iostream>
#include <random>
#include <algorithm>
#include<fstream>
using namespace std;

const int NUM_OF_DIRECTIONS = 8;

Gamesys::Gamesys():end{false},re{false}{}
void Gamesys::startfloors(string floorfile,string chamberfile)
{
     if(floorfile != "floor.txt")
     {
        string line;
        ifstream mymap(floorfile);
        if(mymap.is_open())
	{
	    int i = 0;vector<string> level1,level2,level3,level4,level5;
	    while(getline(mymap,line))
	    {
	       if(i < 25) level1.push_back(line);
	       else if(i < 50) level2.push_back(line);
	       else if(i < 75) level3.push_back(line);
	       else if(i < 150) level4.push_back(line);
	       else level5.push_back(line);
	    }
	    floor1.startLevel(level1,chamberfile);
	    floor2.startLevel(level2,chamberfile);
	    floor3.startLevel(level3,chamberfile);
	    floor4.startLevel(level4,chamberfile);
	    floor5.startLevel(level5,chamberfile);
	}
	else
	{
	   cout << "Unbale to load the map" <<endl;
	}
     }
     else
     {
       floor1.startFloor(floorfile,chamberfile);
       floor2.startFloor(floorfile,chamberfile);
       floor3.startFloor(floorfile,chamberfile);
       floor4.startFloor(floorfile,chamberfile);
       floor5.startFloor(floorfile,chamberfile);
     }
}
Floor& Gamesys::getfloor1()
{
   return floor1;
}
Floor& Gamesys::getfloor2()
{
   return floor2;
}
Floor& Gamesys::getfloor3()
{
   return floor3;
}
Floor& Gamesys::getfloor4()
{
   return floor4;
}
Floor& Gamesys::getfloor5()
{
   return floor5;
}

bool Gamesys::endgame()
{
   return end;
}
void Gamesys::score()
{
   if(end || re) return;
}
bool Gamesys::replay()
{
   return re;
}
void Gamesys::playgame(Floor &floor,int level, bool init)
{
   // init player
   string playerrace;bool notset = init;double hp,atk,def; int gold;int playerx, playery;
   
   while(notset)
   {
      cout << endl << "[ Available Races: s(Shade), d(Drow), v(Vampire), g(Goblin), t(Troll) ]" << endl;
      cout << "Please choose a race to play (Press z for default race Shade):";
      if(cin >> playerrace)
      {
        if(playerrace == "s") {hp = 125;atk = 25;def = 25;Shade *me = new Shade{hp,atk,def};player = me;notset = false;}
        if(playerrace == "v") {hp = 50;atk = 25;def = 25;Vampire *me = new Vampire{hp,atk,def};player = me;notset = false;}
        if(playerrace == "d") {hp = 150;atk = 25;def = 15;Drow *me = new Drow{hp,atk,def};player = me;notset = false;}
        if(playerrace == "t") {hp = 120;atk = 25;def = 15;Troll *me = new Troll{hp,atk,def};player = me;notset = false;}
        if(playerrace == "g") {hp = 110;atk = 200;def = 20;Goblin *me = new Goblin{hp,atk,def};player = me;notset = false;}
        if(playerrace == "z") {hp = 125;atk = 25;def = 25;Shade *me = new Shade{hp,atk,def};player = me;notset = false;}
      }
      else
      {
        if(cin.eof()) {cout << endl<< "[ Abort the game (exiting) ]" << endl; exit(1);}
        else {cin.clear();cin.ignore();}
      }
   }
    cout<<endl;
   
   player->levelover = false;
   player->getGold(gold);player->getHP(hp);player->getAtk(atk);player->getDef(def);player->getRace(playerrace);
   initposition(player,'@',floor);
   // init stair
   initstair(player,'\\',floor);
   //n init enemies
   initenemy(floor); 
   //start the game
   bool isdone = false;
   while(isdone != true)
   {
      if((player->levelover) && (level == 5))
      {
         double sc;
         player->getGold(gold);
         if((playerrace == "z") || (playerrace == "s")) {
            sc = (gold*100)*1.5;
         } else {
            sc = gold * 100;
            }
	 cout << "You win !!!"<<endl;
         cout <<"Your score is :" <<sc<<endl;
         string again;
         cout <<"Do you want to play again?(press r for replay) :";
	 cin >> again;
         if(again == "r") {re = true;end = false; return;}
	 else {end = true;return;}
      }
      if(player->levelover) return;
      player->getPosition(playerx,playery);
      // notification will be shown if the player is beside an already-learned potion
      vector<char> tiles;
      vector<Potion*> potions;
      vector<string> directions {"no", "so", "we", "ea", "ne", "nw", "se", "sw"};
      vector<pair<int,int>> coordinates { {playerx, playery - 1}, {playerx, playery + 1},
                                          {playerx - 1, playery}, {playerx + 1, playery},
                                          {playerx + 1, playery - 1}, {playerx - 1, playery - 1},
                                          {playerx + 1, playery + 1}, {playerx - 1, playery + 1} };
      for (int i = 0; i < NUM_OF_DIRECTIONS; ++i) {
         tiles.push_back( floor.gettile(coordinates[i].first, coordinates[i].second) );
         potions.push_back( floor.getPotion(coordinates[i].first, coordinates[i].second) );
      }
      for (int j = 0; j < NUM_OF_DIRECTIONS; ++j) {
         if (tiles[j] == 'P') {
            Potion *potion = potions[j];
            string potionName = potion->getName();
            if ( player->haveLearnPotion(potionName) ) {
               cout << endl << "< Potion " << potionName << " is on your \"" << directions[j] << "\" side! >" << endl;
            }
         }
      }

      floor.printFloor();
      player->getGold(gold);player->getHP(hp);player->getAtk(atk);player->getDef(def);player->getRace(playerrace);
      cout<<"Race: "<<playerrace<<" "<<"Gold: "<<gold<<" Level: "<<level<<endl;
      player->getHP(hp);
      cout<<"HP: "<<hp<<endl;
      cout<<"Atk: "<<atk<<endl;
      cout<<"Def: "<<def<<endl;
      cout<<"Action:";
      vector<Enemy*> targets = floor.enemyAround(playerx, playery);
      sort(targets.begin(),targets.end());
      targets.erase(unique(targets.begin(),targets.end()),targets.end());
      for(auto &e: targets)
      {
         if(e->getHostile())
	 {
	     e->attack(player);
	 }
         else continue;
      }

      player->getHP(hp);
      if(hp <= 0) {
                      double sc;
		      if((playerrace == "z") || (playerrace == "s")) sc = (gold*100)*1.5;
                      else {sc=gold*100;}
                      cout << "You Lose!" << endl;
		      string again;
		      cout <<"Do you want to play again?(press r for replay) :";
		      cin >> again;
		      if(again == "r") {re = true;end = false; return;}
		      else {end = true;return;}
		  }


      string in;
      if(! (cin >> in))
      {
         if(cin.eof()) {cout<<endl;break;}
      }
      else if (in == "r") {re = true;end = false;return;}
      else if (in == "q") {
         cout << "You Lose!" << endl;
	 end = true;
         return;
      }
      else 
      {
         int px = playerx; int py = playery;
         if ( (in == "no") || (in == "so") || (in == "we") || (in == "ea") ||
              (in == "ne") || (in == "nw") || (in == "se") || (in == "sw") )
         {
            floor.moveplayer(in,player);
         }
       if (in == "f") {floor.setCanmove(-1);}
       if ( (in == "a"))
	 {
	    cin >> in;
	    int enemyX = playerx; int enemyY = playery;
	    Enemy *targetEnemy = nullptr; 
	    if (in == "no"){targetEnemy = floor.findEnemy(enemyX,enemyY - 1,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
            if (in == "so"){targetEnemy = floor.findEnemy(enemyX,enemyY + 1,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
	    if (in == "we"){targetEnemy = floor.findEnemy(enemyX - 1,enemyY,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}                
	    if (in == "ea"){targetEnemy = floor.findEnemy(enemyX + 1,enemyY,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
	    if (in == "ne"){targetEnemy = floor.findEnemy(enemyX + 1,enemyY - 1,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
	    if (in == "nw"){targetEnemy = floor.findEnemy(enemyX - 1,enemyY - 1,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
	    if (in == "se"){targetEnemy = floor.findEnemy(enemyX + 1,enemyY + 1,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
	    if (in == "sw"){targetEnemy = floor.findEnemy(enemyX - 1,enemyY + 1,targets); if(targetEnemy != nullptr) player->attack(targetEnemy);}
	 if (targetEnemy == nullptr) continue;    
	 floor.setM(); //set all Merchants hostile 
         
	 if (targetEnemy->isDead()) 
	 {
            string enemyRace;
            targetEnemy->getRace(enemyRace);
            int enemyX, enemyY;
            targetEnemy->getPosition(enemyX, enemyY);
            if (enemyRace == "Merchant") 
	    {
               floor.removeEnemy(targetEnemy, enemyX, enemyY);
               Gold *newGold = new MerchantHoard(player);
	       newGold->setPosn(enemyX,enemyY);
               floor.addGold(newGold, enemyX, enemyY);
            } 
	    else if (enemyRace == "Human") 
	    {
               floor.removeEnemy(targetEnemy, enemyX, enemyY);
               Gold *new1 = new NormalGold(player);
	       new1->setPosn(enemyX,enemyY);
               floor.addGold(new1, enemyX, enemyY);
               Gold *new2 = new NormalGold(player);
	       new2->setPosn(enemyX,enemyY);
               floor.addGold(new2, enemyX, enemyY);
	    } 
	    else if (enemyRace == "Dragon") 
	    {
                floor.removeDragon(enemyX, enemyY,player);
            } 
	    else {
               random_device random_device;
               mt19937 engine{random_device()};
               uniform_int_distribution<> dist(1,2);
               auto val = dist(engine);
               int gold;
               player->getGold(gold);
               if (val == 1) {
                  player->setGold(gold + 1);
                  cout << endl<< "[ Picked Treasure: Small Gold ]" << endl;
               } else {
                  player->setGold(gold + 2);
                  cout << endl<< "[ Picked Treasure: Normal Gold ]" << endl;
               }
	       floor.removeEnemy(targetEnemy, enemyX, enemyY);
            }

	    if(playerrace == "Goblin")
	    {
	       player->getGold(gold);
	       player->setGold(gold + 5);
	       cout <<"steal 5 glod from "<<enemyRace;
	    }
          } 
	 }
         if ( (in == "u") )
         {
            cin >> in;
            int potionX = playerx, potionY = playery;
            char t;
            if (in == "no") potionY -= 1;
            else if (in == "so") potionY += 1;
            else if (in == "we") potionX -= 1;
            else if (in == "ea") potionX += 1;
            else if (in == "ne") {potionX += 1; potionY -= 1;}
            else if (in == "nw") {potionX -= 1; potionY -= 1;}
            else if (in == "se") {potionX += 1; potionY += 1;}
            else if (in == "sw") {potionX -= 1; potionY += 1;}
            t = floor.gettile(potionX, potionY);
            if (t == 'P') { // if the potion is approachable
               Potion *target = floor.getPotion(potionX, potionY);
               target->beingUsed();
               floor.settile(potionX, potionY, '.');
               player->getHP(hp); player->getAtk(atk); player->getDef(def); // update after using potion
            } else {
               cout << endl<< "< The Potion is not approachable >" << endl;
            }
         }
         if(playerrace == "Troll")
	 {
	    double playerHP;
	    player->getHP(playerHP);double m = playerHP;
	    int n; player->getmaxHP(n);
	    if((playerHP + 5)>=n) {player->setHP(n);cout<<"PC regains "<< n - m <<" HP.";}
	    else 
	    {
	        player->setHP(playerHP + 5);
	        cout << "PC regains 5 HP.";
	    }
	 }
         player->getPosition(playerx,playery);
         if((px != playerx)||(py != playery))
         {
            floor.moveEnemy();
         }
      }
   }
  
}

void Gamesys::initposition(Character *subject, char symbol,Floor &floor)
{
   int subposx,subposy;
   random_device random_device;
   mt19937 engine{random_device()};
   uniform_int_distribution<> dist(1,5);
   auto val = dist(engine);
   subject->setChambernumber(val);
   floor.getCoordinates(val,subposx,subposy);
   subject->setPosition(subposx,subposy);
   subject->setPrevPosition('.');
   floor.settile(subposx,subposy,symbol);
}

void Gamesys::initstair(Player *player,char symbol, Floor &floor)
{
   while(true)
   {
     random_device random_device;
     mt19937 engine{random_device()};
     uniform_int_distribution<> dist(1,5);
     auto st = dist(engine);int stairx,stairy;
     if (st == player->getChambernumber()) continue;
     floor.getCoordinates(st,stairx,stairy);
     floor.settile(stairx,stairy,'\\');
     break;
   }
}

void Gamesys::initenemy(Floor &floor)
{
   floor.startPotion(player);
   floor.startGold(player);
   floor.startenemy();
}
Gamesys::~Gamesys()
{
   if (player != nullptr) delete player;
}
