#include<iostream>
#include <fstream>
#include<string>
#include "gamesys.h"
using namespace std;

int main(int argc, char *argv[])
{
    string defaultFile = "floor.txt";
    string defaultChamber = "floorbase.txt";
     while(true)
    {     
      Gamesys gamesys;
      if(argc == 2) {string ChooseFile = argv[1];gamesys.startfloors(ChooseFile,defaultChamber);} 
      else gamesys.startfloors(defaultFile,defaultChamber);
      gamesys.playgame(gamesys.getfloor1(),1);
      if(gamesys.endgame()){gamesys.score();break;}
      else 
        {  
	   if(gamesys.replay()) continue;
           gamesys.playgame(gamesys.getfloor2(),2);
           if(gamesys.endgame()){gamesys.score();break;}
             else
             {
                if(gamesys.replay()) continue;
		gamesys.playgame(gamesys.getfloor3(),3);
		if(gamesys.endgame()){gamesys.score();break;}
		else
		{
		    if(gamesys.replay()) continue;
		    gamesys.playgame(gamesys.getfloor4(),4);
		    if(gamesys.endgame()){gamesys.score();break;}
		    else
		    {
		        if(gamesys.replay()) continue;
			gamesys.playgame(gamesys.getfloor5(),5);
		        if(gamesys.endgame()){gamesys.score();break;}
		    }
		}
             }
        }
     }
    return 0;
}
