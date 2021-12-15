#ifndef _DLCFLOOR_H_
#define _DLCFLOOR_H_
#include "floor.h"
#include "drx.h"
#include <vector>
#include <memory>
class DlcFloor: public Floor {
    DrX* doctorX = nullptr;
    public:
    DlcFloor();
    ~DlcFloor();
    void startDoctor();
    virtual void moveEnemy();
    virtual vector<Enemy*> enemyAround(int xcor, int ycor, int chambernum);
};

#endif