#ifndef CHARACTER_H
#define CHARACTER_H
#include<string>
using namespace std;
class Character
{
    int x,y;
    double HP;
    int MaxHP;
    double Atk;
    double Def;
//---------------------- Add new things here by Ellie (Remember to delete this line) ----------------------
    int AtkEffect = 0;
    int DefEffect = 0;
//---------------------- Addings end here (Remember to delete this line) ----------------------
    int AttackBonus;
    double MissChance;
    char PrevPosition;
    char NewPosition;
    string Race;
    bool dead;

    public:
       Character(double &hp,double &atk,double &def,string &race);
       bool isDead();
       void setDeath(bool d);
       void setRace(string race); void getRace(string &race);
       void setHP(double hp); void getHP(double &hp);
       void setmaxHP(int maxhp); void getmaxHP(int &maxhp);
       void setAtk(double atk); void getAtk(double &atk);
       void setDef(double def); void getDef(double &def);
//---------------------- Add new things here by Ellie (Remember to delete this line) ----------------------
       void setAtkEffect(int atk); void getAtkEffect(int &atk);
       void setDefEffect(int def); void getDefEffect(int &def);
//---------------------- Addings end here (Remember to delete this line) ----------------------
       void setAttackBonus(int ab); void getAttackBonus(int &ab);
       void setMissChance(double mc); void getMissChance(double &mc);
       void setPrevPosition(char cha); char getPrevPosition();
       void getPosition(int &xcor, int &ycor);void setPosition(int xcor, int ycor);
       void loseHP(double n);
       virtual ~Character() = 0;
};


#endif
