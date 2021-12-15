#include<iostream>
#include <fstream>
#include<string>
#include "gamesys.h"
#include "dlcgamesys.h"
using namespace std;
 
int main(int argc, char *argv[])
{
    string defaultFile = "floor.txt";
    string defaultChamber = "floorbase.txt";
     while(true)
    {     
      Gamesys gamesys1;
      DlcGamesys gamesys2;
        if (argc == 2 && string(argv[1]) == "dlc") {
        cout << "You won a DLC!" << endl;
        cout << "Be careful of Dr.X, you are on the list of assassination." << endl;
         gamesys2.startfloors(defaultFile,defaultChamber);
         bool init = true;
      cout << "Please choose difficulty: e(Easy), n(Normal by default)" << endl;
      char difficulty;
      if (cin >> difficulty) {
        if (difficulty == 'e') {
          cout << "Dr.Secret teleports you to the fifth floor! " << endl;
          gamesys2.playgame(gamesys2.getfloor5(),5, init);
        } else {
          gamesys2.playgame(gamesys2.getfloor1(),1, init);
        }
        init = false;
      } else {
        cin.clear();
        cin.ignore();
        gamesys2.playgame(gamesys2.getfloor1(),1, init);
        init = false;
      }
      if(gamesys2.endgame()){gamesys2.score();break;}
      else 
        {  
	   if(gamesys2.replay()) continue;
           gamesys2.playgame(gamesys2.getfloor2(),2, init);
           if(gamesys2.endgame()){gamesys2.score();break;}
             else
             {
                if(gamesys2.replay()) continue;
		gamesys2.playgame(gamesys2.getfloor3(),3, init);
		if(gamesys2.endgame()){gamesys2.score();break;}
		else
		{
		    if(gamesys2.replay()) continue;
		    gamesys2.playgame(gamesys2.getfloor4(),4, init);
		    if(gamesys2.endgame()){gamesys2.score();break;}
		    else
		    {
		        if(gamesys2.replay()) continue;
			gamesys2.playgame(gamesys2.getfloor5(),5, init);
		        if(gamesys2.endgame()){gamesys2.score();break;}
		    }
		}
             }
        }
      } else {
      if(argc == 2) {
          string ChooseFile = argv[1];gamesys1.startfloors(ChooseFile,defaultChamber);
      } else gamesys1.startfloors(defaultFile,defaultChamber);
      bool init = true;
      cout << "Please choose difficulty: e(Easy), n(Normal by default)" << endl;
      char difficulty;
      if (cin >> difficulty) {
        if (difficulty == 'e') {
          cout << "Dr.Secret teleports you to the fifth floor! " << endl;
          gamesys1.playgame(gamesys1.getfloor5(),5, init);
        } else {
          gamesys1.playgame(gamesys1.getfloor1(),1, init);
        }
        init = false;
      } else {
        cin.clear();
        cin.ignore();
        gamesys1.playgame(gamesys1.getfloor1(),1, init);
        init = false;
      }
      if(gamesys1.endgame()){gamesys1.score();break;}
      else 
        {  
	   if(gamesys1.replay()) continue;
           gamesys1.playgame(gamesys1.getfloor2(),2, init);
           if(gamesys1.endgame()){gamesys1.score();break;}
             else
             {
                if(gamesys1.replay()) continue;
		gamesys1.playgame(gamesys1.getfloor3(),3, init);
		if(gamesys1.endgame()){gamesys1.score();break;}
		else
		{
		    if(gamesys1.replay()) continue;
		    gamesys1.playgame(gamesys1.getfloor4(),4, init);
		    if(gamesys1.endgame()){gamesys1.score();break;}
		    else
		    {
		        if(gamesys1.replay()) continue;
			gamesys1.playgame(gamesys1.getfloor5(),5, init);
		        if(gamesys1.endgame()){gamesys1.score();break;}
		    }
		}
             }
        }
     }
    }
    return 0;
}
