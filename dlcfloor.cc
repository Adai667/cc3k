#include "dlcfloor.h"
#include <random>
#include <vector>

DlcFloor::DlcFloor():Floor{} {}
DlcFloor::~DlcFloor(){DlcFloor::clean();}

void DlcFloor::startDoctor() {
    random_device random_device;
    mt19937 engine{random_device()};
    char r = 'X';
    doctorX = new DrX();
    while(true) {
        uniform_int_distribution<> dist(1,5);
        auto st = dist(engine);int enx,eny;
        getCoordinates(st,enx,eny);
        if(gettile(enx,eny) != '.') continue;
	    else {
	        doctorX->setPosition(enx,eny);
	        doctorX->setPrevPosition('.');
            doctorX->setChambernumber(st); 
	        settile(enx,eny,r);
	        break;
	    }
    }
}

void DlcFloor::moveEnemy() {
   random_device random_device;
   mt19937 engine{random_device()};
   if(canmove == -1) return;   
   for(auto &i : enemies)
   {
      int enemy_x,enemy_y,n;
      i->getPosition(enemy_x, enemy_y);i->getChambernumber(n);
      uniform_int_distribution<> dist(0,7);
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
   while(true) {
          uniform_int_distribution<> dist(1,5);
          auto st = dist(engine);int enx,eny;
          getCoordinates(st,enx,eny);
          if(gettile(enx,eny) != '.') continue;
	  else {
          int enemy_x,enemy_y;char r;
          doctorX->getPosition(enemy_x,enemy_y);
          settile(enemy_x,enemy_y,doctorX->getPrevPosition());
          doctorX->setPosition(enx,eny);
          doctorX->setPrevPosition('.');
          doctorX->setChambernumber(st); 
          settile(enx,eny,'X');
          break;
        }
    }
}

vector<Enemy*> DlcFloor::enemyAround(int xcor, int ycor, int chambernum) {
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
   int n;
   doctorX->getChambernumber(n);
   if (n == chambernum) {
       ans.push_back(doctorX);
   }
   return ans;
}

void DlcFloor::clean() {
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
    delete doctorX;
}