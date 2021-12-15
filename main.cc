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
      bool init = true;
      cout << "Please choose difficulty: e(Easy), n(Normal by default)" << endl;
      char difficulty;
      if (cin >> difficulty) {
        if (difficulty == 'e') {
          cout << "Dr.Secret teleports you to the fifth floor! " << endl;
          gamesys.playgame(gamesys.getfloor5(),5, init);
        } else {
          gamesys.playgame(gamesys.getfloor1(),1, init);
        }
        init = false;
      } else {
        cin.clear();
        cin.ignore();
        gamesys.playgame(gamesys.getfloor1(),1, init);
        init = false;
      }
      if(gamesys.endgame()){gamesys.score();break;}
      else 
        {  
	   if(gamesys.replay()) continue;
           gamesys.playgame(gamesys.getfloor2(),2, init);
           if(gamesys.endgame()){gamesys.score();break;}
             else
             {
                if(gamesys.replay()) continue;
		gamesys.playgame(gamesys.getfloor3(),3, init);
		if(gamesys.endgame()){gamesys.score();break;}
		else
		{
		    if(gamesys.replay()) continue;
		    gamesys.playgame(gamesys.getfloor4(),4, init);
		    if(gamesys.endgame()){gamesys.score();break;}
		    else
		    {
		        if(gamesys.replay()) continue;
			gamesys.playgame(gamesys.getfloor5(),5, init);
		        if(gamesys.endgame()){gamesys.score();break;}
		    }
		}
             }
        }
     }
    return 0;
}
