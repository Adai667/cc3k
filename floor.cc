#include "floor.h"
#include <iostream>
#include<fstream>
#include <random>
#include <algorithm>
using namespace std;
Floor::Floor()
{
   canmove = 1;
}
void Floor::setCanmove(int i)
{
   canmove = i * canmove;
}
void Floor::startLevel(vector<string> lv,string chamber)
{
    for(auto &i : lv)
    {
       ldata.push_back(i);
    }
    ifstream mychamber (chamber);
    string line;
   if(mychamber.is_open())
   {
       int i = 0;
       while(getline(mychamber,line))
       {
          int j = 0;
          for( auto &k : line)
	  {
	     if(k == '1') {coordinates w{i,j};chamber1.push_back(w);}
	     if(k == '2') {coordinates w{i,j};chamber2.push_back(w);}
	     if(k == '3') {coordinates w{i,j};chamber3.push_back(w);}
	     if(k == '4') {coordinates w{i,j};chamber4.push_back(w);}
	     if(k == '5') {coordinates w{i,j};chamber5.push_back(w);}
	     j++;
	  }
	  i++;
       }
   }
   else cout << "Unbale to load the map" <<endl;


}
void Floor::startFloor(string file,string chamber)
{
   string line;
   ifstream myfile (file);
   if (myfile.is_open())
   {
      while (getline(myfile,line))
      {
         ldata.push_back(line);
      }
      myfile.close();
   }
   else {cout << "Unbale to load the map" <<endl;return;}
   ifstream mychamber (chamber);
   line = "";
   if(mychamber.is_open())
   {
       int i = 0;
       while(getline(mychamber,line))
       {
          int j = 0;
          for( auto &k : line)
	  {
	     if(k == '1') {coordinates w{i,j};chamber1.push_back(w);}
	     if(k == '2') {coordinates w{i,j};chamber2.push_back(w);}
	     if(k == '3') {coordinates w{i,j};chamber3.push_back(w);}
	     if(k == '4') {coordinates w{i,j};chamber4.push_back(w);}
	     if(k == '5') {coordinates w{i,j};chamber5.push_back(w);}
	     j++;
	  }
	  i++;
       }
   }
   else cout << "Unbale to load the map" <<endl;

}

void  Floor::getCoordinates(int chambernum,int &playerx,int &playery)
{
    random_device random_device;
    mt19937 engine{random_device()};
    if(chambernum == 1) {uniform_int_distribution<> dist(0,(chamber1.size() - 1));auto val = dist(engine);playerx = chamber1[val].y;playery = chamber1[val].x;}
    else if(chambernum == 2) {uniform_int_distribution<> dist(0,(chamber2.size() - 1));auto val = dist(engine);playerx = chamber2[val].y;playery = chamber2[val].x;}
    else if(chambernum == 3) {uniform_int_distribution<> dist(0,(chamber3.size() - 1));auto val = dist(engine);playerx = chamber3[val].y;playery = chamber3[val].x;}
    else if(chambernum == 4) {uniform_int_distribution<> dist(0,(chamber4.size() - 1));auto val = dist(engine);playerx = chamber4[val].y;playery = chamber4[val].x;}
    else  {uniform_int_distribution<> dist(0,(chamber5.size() - 1));auto val = dist(engine);playerx = chamber5[val].y;playery = chamber5[val].x;}
}

void Floor::printFloor()
{   cout << endl;
    for(auto &i : ldata)
    {
       cout << i <<endl;
    }
}

void Floor::moveplayer(string in, Player *player)
{
    int player_x,player_y;
    player->getPosition(player_x,player_y);
    if(in == "no") moveplayerhelp(player,player_x,player_y - 1); 
    if(in == "so") moveplayerhelp(player,player_x,player_y + 1);
    if(in == "we") moveplayerhelp(player,player_x - 1 ,player_y);
    if(in == "ea") moveplayerhelp(player,player_x + 1 ,player_y);
    if(in == "ne") moveplayerhelp(player,player_x + 1 ,player_y - 1);
    if(in == "nw") moveplayerhelp(player,player_x - 1 ,player_y - 1);
    if(in == "se") moveplayerhelp(player,player_x + 1 ,player_y + 1);
    if(in == "sw") moveplayerhelp(player,player_x - 1 ,player_y + 1);
}
char Floor::gettile(int xcor,int ycor)
{
    return ldata[ycor][xcor];
}
void Floor::settile(int xcor, int ycor,char cha)
{
     ldata[ycor][xcor] = cha;
}

void Floor::moveplayerhelp(Player *player,int new_x,int new_y)
{
   int player_x,player_y;
   player->getPosition(player_x,player_y);
   char t = gettile(new_x,new_y);
   if(t == '\\') {player->levelover = true;}
   if((t == '.')||(t == '+')||(t == '#')||(t == 'G'))
   {
//---------------------- Add new things here by Ellie (Remember to delete this line) ----------------------
   bool hasPicked = false; // check if we has picked any gold
   if (t == 'G') { // walks over a gold
      int goldX, goldY;
      Gold *target;
      for (auto &j : golds) {
         j->getPosn(goldX, goldY);
         if ( (goldX == new_x) && (goldY == new_y) ) {
            target = j;
            break;
         }
      }
      // if the gold is not protected, then we can pick it
      if (target->isProtected() == false) {target->beingPicked(); hasPicked = true;}
      else { cout << "You must slain its protector - The Great Dragon!" <<endl;}
   }
         player->setPosition(new_x,new_y);
	 settile(player_x,player_y,player->getPrevPosition());
	 settile(new_x,new_y,'@');
    if ( (t == 'G') && (hasPicked == true) ) { // we have picked the gold
      player->setPrevPosition('.');
   } else {
      player->setPrevPosition(t);
   }
//---------------------- Addings end here (Remember to delete this line) ----------------------
   }
}

void Floor::moveEnemy()
{
   random_device random_device;
   mt19937 engine{random_device()};
   if(canmove == -1) return;   
   for(auto &i : enemies)
   {
      int enemy_x,enemy_y,n;
      i->getPosition(enemy_x, enemy_y);i->getChambernumber(n);
      uniform_int_distribution<> dist(0,3);
      auto val = dist(engine);
      if(val == 0) moveEnemyhelp(i,enemy_x,enemy_y - 1);
      if(val == 1) moveEnemyhelp(i,enemy_x,enemy_y + 1);
      if(val == 2) moveEnemyhelp(i,enemy_x - 1,enemy_y);
      if(val == 3) moveEnemyhelp(i,enemy_x + 1,enemy_y);
      if(val == 4) {moveEnemyhelp(i,enemy_x,enemy_y - 1);moveEnemyhelp(i,enemy_x + 1,enemy_y);}
      if(val == 5) {moveEnemyhelp(i,enemy_x,enemy_y - 1);moveEnemyhelp(i,enemy_x - 1,enemy_y);}
      if(val == 6) {moveEnemyhelp(i,enemy_x,enemy_y + 1);moveEnemyhelp(i,enemy_x + 1,enemy_y);}
      if(val == 7) {moveEnemyhelp(i,enemy_x,enemy_y + 1);moveEnemyhelp(i,enemy_x - 1,enemy_y);}
   }
}
void Floor::moveEnemyhelp(Enemy *enemy, int new_x, int new_y)
{
    
   int enemy_x,enemy_y;char r;
   enemy->getPosition(enemy_x,enemy_y);
   enemy->getSymbol(r);
   char t = gettile(new_x,new_y);
   if((t == '.'))
   {
    enemy->setPosition(new_x,new_y);
	 settile(enemy_x,enemy_y,enemy->getPrevPosition());
	 settile(new_x,new_y,r);
	 enemy->setPrevPosition(t);
   }  
}

void Floor::startenemy()
{
   random_device random_device;
   mt19937 engine{random_device()};
   string EnemyIndex[1800];
   for(int m = 0; m < 1800; m++)
   {
      if(m < 400) EnemyIndex[m] = "Human";
      else if(m < 700) EnemyIndex[m] = "Dwarf";
      else if(m < 1200) EnemyIndex[m] = "Halfling";
      else if(m < 1400) EnemyIndex[m] = "Elf";
      else if(m < 1600) EnemyIndex[m] = "Orc";
      else EnemyIndex[m] = "Merchant";
   }
   
   for(int i = 0; i < 20; i++)
   {
      uniform_int_distribution<> dist(0,1799);
      auto num = dist(engine);
      if(EnemyIndex[num] ==  "Human") {Enemy *badguy = new Human{}; enemies.push_back(badguy);}
      if(EnemyIndex[num] ==  "Dwarf") {Enemy *badguy = new Dwarf{}; enemies.push_back(badguy);}
      if(EnemyIndex[num] ==  "Halfling"){ Enemy *badguy = new Halfling{}; enemies.push_back(badguy);}
      if(EnemyIndex[num] ==  "Elf"){ Enemy *badguy = new Elf{}; enemies.push_back(badguy);}
      if(EnemyIndex[num] ==  "Orc"){ Enemy *badguy = new Orcs{}; enemies.push_back(badguy);}
      if(EnemyIndex[num] ==  "Merchant") {Enemy *badguy = new Merchant{}; enemies.push_back(badguy);}
     
   }
   for( auto &j : enemies)
   {
      char r; j->getSymbol(r);
      while(true)
        {
          uniform_int_distribution<> dist(1,5);
          auto st = dist(engine);int enx,eny;
          getCoordinates(st,enx,eny);
          if(gettile(enx,eny) != '.') continue;
	  else {
	  j->setPosition(enx,eny);
	  j->setPrevPosition('.');
          j->setChambernumber(st); 
	  settile(enx,eny,r);
	  break;
	  }
         }
   }
   
}

void Floor::clean()
{
    for(auto &v : enemies)
    {
      delete v;
    }
    for(auto &g : golds)
    {
      delete g;
    }
    for(auto &p : potions)
    {
      delete p;
    }
    for(auto &d : dragons)
    {
       delete d;
    }
}

Floor::~Floor(){Floor::clean();}

//---------------------- Add new things here by Ellie (Remember to delete this line) ----------------------
void Floor::startGold(Player *player)
{
   random_device random_device;
   mt19937 engine{random_device()};
   string GoldIndex[800];

   for(int m = 0; m < 800; m++)
   {
      if(m < 100) GoldIndex[m] = "DragonHoard";
      else if(m < 300) GoldIndex[m] = "SmallGold";
      else if(m < 800) GoldIndex[m] = "NormalGold";
   }
   
   for(int i = 0; i < 10; i++)
   {
      uniform_int_distribution<> dist(0,799);
      auto num = dist(engine);
      if(GoldIndex[num] ==  "DragonHoard") {
          Dragon *newDragon = new Dragon{};
	  dragons.push_back(newDragon);   
          Gold *dHoard = new DragonHoard{player, newDragon}; 
	  golds.push_back(dHoard);
      }
      if(GoldIndex[num] ==  "SmallGold") {Gold *sGold = new SmallGold{player}; golds.push_back(sGold);}
      if(GoldIndex[num] ==  "NormalGold") {Gold *nGold = new NormalGold{player}; golds.push_back(nGold);}
   }

   for (auto &g : golds) {
      char r = 'G';
      while(true) {
         uniform_int_distribution<> dist(1,5);
         auto st = dist(engine); int xCor,yCor;
         getCoordinates(st,xCor,yCor);
         if(gettile(xCor,yCor) != '.') continue;
         else {
	       g->setPosn(xCor,yCor);
               settile(xCor,yCor,r);
            if(g->isProtected())
	    {
	       Enemy *en ;
	       en = g->getProtector();
	       vector<int> around;
	       
	       if(gettile(xCor,yCor - 1) == '.') around.push_back(1);
	       if(gettile(xCor,yCor + 1) == '.') around.push_back(2);
	       if(gettile(xCor - 1,yCor) == '.') around.push_back(3);
	       if(gettile(xCor + 1,yCor) == '.') around.push_back(4);
               if(gettile(xCor + 1,yCor - 1) == '.') around.push_back(5);
	       if(gettile(xCor - 1,yCor - 1) == '.') around.push_back(6);
	       if(gettile(xCor + 1,yCor + 1) == '.') around.push_back(7);
	       if(gettile(xCor - 1,yCor + 1) == '.') around.push_back(8);
	       
	       uniform_int_distribution<> dist(0,around.size() - 1);
	       auto dir = dist(engine);

               if(around[dir] == 1){en->setPosition(xCor,yCor - 1);settile(xCor,yCor - 1,'D');} 
	       if(around[dir] == 2){en->setPosition(xCor,yCor + 1);settile(xCor,yCor + 1,'D');} 
	       if(around[dir] == 3){en->setPosition(xCor - 1,yCor);settile(xCor - 1,yCor,'D');} 
	       if(around[dir] == 4){en->setPosition(xCor + 1,yCor);settile(xCor + 1,yCor,'D');} 
	       if(around[dir] == 5){en->setPosition(xCor + 1,yCor - 1);settile(xCor + 1,yCor - 1,'D');} 
	       if(around[dir] == 6){en->setPosition(xCor - 1,yCor - 1);settile(xCor - 1,yCor - 1,'D');} 
	       if(around[dir] == 7){en->setPosition(xCor + 1,yCor + 1);settile(xCor + 1,yCor + 1,'D');} 
	       if(around[dir] == 8){en->setPosition(xCor - 1,yCor + 1);settile(xCor - 1,yCor + 1,'D');} 
              
           

                
            }
	    break;
	    
      }
   }
}
}
void Floor::startPotion(Player *player)
{
   random_device random_device;
   mt19937 engine{random_device()};
   string GoldIndex[600];

   for(int m = 0; m < 600; m++)
   {
      if(m < 100) GoldIndex[m] = "RH";
      else if(m < 200) GoldIndex[m] = "PH";
      else if(m < 300) GoldIndex[m] = "BA";
      else if(m < 400) GoldIndex[m] = "WA";
      else if(m < 500) GoldIndex[m] = "BD";
      else if(m < 600) GoldIndex[m] = "WD";
   }
   
   for(int i = 0; i < 10; i++)
   {
      uniform_int_distribution<> dist(0,599);
      auto num = dist(engine);
      if(GoldIndex[num] ==  "RH") {Potion *RH = new RestoreHealth{player}; potions.push_back(RH);}
      if(GoldIndex[num] ==  "PH") {Potion *PH = new PoisonHealth{player}; potions.push_back(PH);}
      if(GoldIndex[num] ==  "BA") {Potion *BA = new BoostAtk{player}; potions.push_back(BA);}
      if(GoldIndex[num] ==  "WA") {Potion *WA = new WoundAtk{player}; potions.push_back(WA);}
      if(GoldIndex[num] ==  "BD") {Potion *BD = new BoostDef{player}; potions.push_back(BD);}
      if(GoldIndex[num] ==  "WD") {Potion *WD = new WoundDef{player}; potions.push_back(WD);}
   }

   for (auto &p : potions) {
      char r = 'P';
      while(true) {
         uniform_int_distribution<> dist(1,5);
         auto st = dist(engine); int xCor,yCor;
         getCoordinates(st,xCor,yCor);
         if(gettile(xCor,yCor) != '.') continue;
         else {
            p->setPosn(xCor,yCor);
            settile(xCor,yCor,r);
            break;
         }
      }
   }
}

Potion *Floor::getPotion(int targetX, int targetY) {
   int xCor, yCor;
   for (auto &p : potions) {
      p->getPosn(xCor, yCor);
      if ( (xCor == targetX) && (yCor == targetY) ) {
         return p;
      }
   }
   return nullptr; // gives nullptr if the target potion does not exist
}
//---------------------- Addings end here (Remember to delete this line) ----------------------
vector<Enemy*> Floor::enemyAround(int xcor, int ycor) {
   vector<Enemy*> ans; 
   for (int i = xcor - 1; i <= xcor + 1; i++) {
      for (int j = ycor - 1; j <= ycor + 1; j++) {
         if (i < 0 || j < 0 || ((i == xcor) && (j == ycor))) {
            continue;
         }
         for (auto &e: enemies) {
            int X, Y;
            e->getPosition(X,Y);
            if ((X == i) && (Y == j)) {
               ans.push_back(e);
            }
         }
	 for (auto &d: dragons)
	 {
	    int X, Y;
	    d->getPosition(X,Y);
	    if ((X == i) && (Y == j))
	    {
	       if(!d->isDead()) ans.push_back(d);
	    }
	 }
	 for(auto &g : golds)
	 {
	     int X, Y;Enemy *en;
	     g->getPosn(X,Y);
	     if ((X == i) && (Y == j))
	     {
	         en = g->getProtector();
	         if((g->isProtected())&&(en != nullptr))
		 {
		    ans.push_back(en);
		 }
	     }
	 }
         
      }
   }
   return ans;
}
Enemy* Floor::findEnemy(int xcor, int ycor, vector<Enemy*> enemyAround)
{
    for(auto &i : enemyAround)
    {
        int x, y;
	i->getPosition(x,y);
        if ((xcor == x) && (ycor == y)) return i;
    }
    return nullptr;
}

void Floor::removeEnemy(Enemy* enemy, int xcor, int ycor)
{
   int j =0;
   for(auto &i : enemies)
   {
      int x, y;
      i->getPosition(x,y);
      if ((xcor == x) && (ycor == y)) 
      {
         delete i; 
	 enemies.erase(enemies.begin() + j);
         settile(xcor, ycor, '.');
      }
      j++;
   }
}
void Floor::removeDragon(int xcor, int ycor,Player *player)
{
     for (auto &g: golds)
   {
       Enemy *en = g->getProtector();
       int X, Y;
       if(en != nullptr)
         {
            en->getPosition(X,Y);
            if ((X == xcor) && (Y == ycor))
            {
            bool a = false;
	    g->setProtected(a);
            }
	 }
   }
   settile(xcor, ycor, '.');
}



void Floor::addGold(Gold *gold, int xcor, int ycor) {
   golds.push_back(gold);
   settile(xcor, ycor, 'G');
}

void Floor::setM()
{
    char s;
    for(auto &i : enemies)
    {
        i->getSymbol(s);
	if(s == 'M') i->becomeHostile();
    }
}
