#include "items.h"

Player *Items::getPlayer() { return player; }

string Items::getName() { return name; }

void Items::getPosn(int &xCor, int &yCor) {
    xCor = posnX;
    yCor = posnY;
}

void Items::setPosn(int xCor, int yCor) {
    posnX = xCor;
    posnY = yCor;
}

Items::Items(string name, Player *player)
    : name{ name }, posnX{ 0 }, posnY{ 0 }, player{ player } {}

Items::~Items() { player = nullptr; }
