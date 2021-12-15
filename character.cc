#include "character.h"
Character::Character(double &hp,double &atk,double &def,string &race):HP{hp},Atk{atk},Def{def},Race{race},dead{false}{}
Character::~Character(){}
int Character::getChambernumber() {
   return chambernum;
}
void Character::setChambernumber(int n) {
   chambernum = n;
}
bool Character::isDead()
{
   return dead;
}
void Character::setDeath(bool d)
{
   dead = d;
}
void Character::setRace(string race)
{
   Race = race;
}
void Character::getRace(string &race)
{
   race = Race;
}
void Character::setHP(double hp)
{
   HP = hp;
}
void Character::getHP(double &hp)
{
   hp = HP;
}
void Character::setmaxHP(int maxhp)
{
   MaxHP = maxhp;
}
void Character::getmaxHP(int &maxhp)
{
   maxhp = MaxHP;
}
void Character::setAtk(double atk)
{
   Atk = atk;
}
//---------------------- Add new things here by Ellie (Remember to delete this line) ----------------------
void Character::getAtk(double &atk)
{
   atk = Atk + AtkEffect;
}
void Character::setDef(double def)
{
   Def = def;
}
void Character::getDef(double &def)
{
   def = Def + DefEffect;
}
void Character::setAtkEffect(int atkEff)
{
   AtkEffect = atkEff;
}
void Character::getAtkEffect(int &atkEff)
{
   atkEff = AtkEffect;
}
void Character::setDefEffect(int defEff)
{
   DefEffect = defEff;
}
void Character::getDefEffect(int &defEff)
{
   defEff = DefEffect;
}
//---------------------- Addings end here (Remember to delete this line) ----------------------
void Character::setAttackBonus(int ab)
{
   AttackBonus = ab;
}
void Character::getAttackBonus(int &ab)
{
   ab = AttackBonus;
}
void Character::setMissChance(double mc)
{
   MissChance = mc;
}
void Character::getMissChance(double &mc)
{
   mc = MissChance;
}
void Character::setPrevPosition(char cha)
{
   PrevPosition = cha;
}
char Character::getPrevPosition()
{
   return PrevPosition;
}
void Character::getPosition(int &xcor, int &ycor)
{
   xcor = x; ycor = y;
}
void Character::setPosition(int xcor, int ycor)
{
   x = xcor; y = ycor;
}
void Character::loseHP(double n) {
    if (n > 0) {
        HP -= n;
        if (HP < 0) {
            dead = true;
        }
    }
}
