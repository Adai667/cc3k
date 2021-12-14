#include "potion.h"
#include <iostream>

void Potion::beingUsed() {
    string potionName = getName();
    if ( (potionName == "RH") || (potionName == "PH") ) {
        double newHP = 0;
        int maxHP = 0;
        getPlayer()->getmaxHP( maxHP );
        getPlayer()->getHP( newHP );
        newHP += effectPoints;
        if (newHP < 0) newHP = 0;
        if ( (newHP > maxHP) && (maxHP != -1) ) newHP = maxHP;
        getPlayer()->setHP( newHP );
    }
    else if ( (potionName == "BA") || (potionName == "WA") ) {
        double prePlainAtk = 0;
        int preAtkEff = 0;
        int newAtkEff = 0;
        getPlayer()->getAtk( prePlainAtk );
        getPlayer()->getAtkEffect( preAtkEff );
        prePlainAtk -= preAtkEff;
        newAtkEff = preAtkEff + effectPoints;
        if ( (-1 * newAtkEff) > prePlainAtk ) newAtkEff = -1 * prePlainAtk;
        getPlayer()->setAtkEffect( newAtkEff );
    }
    else if ( (potionName == "BD") || (potionName == "WD") ) {
        double prePlainDef = 0;
        int preDefEff = 0;
        int newDefEff = 0;
        getPlayer()->getDef( prePlainDef );
        getPlayer()->getDefEffect( preDefEff );
        prePlainDef -= preDefEff;
        newDefEff = preDefEff + effectPoints;
        if ( (-1 * newDefEff) > prePlainDef ) newDefEff = -1 * prePlainDef;
        getPlayer()->setDefEffect( newDefEff );
    }
    cout << endl << "[ Used Potion: " << potionName << " ]" << endl;
    bool haveLearned = getPlayer()->haveLearnPotion(potionName);
    if (haveLearned) cout << "< " << effect << " >" << endl;
    if (!haveLearned) {
        cout << "< You found a new type of Potion! >" << endl;
        getPlayer()->learnNewPotion(potionName);
    }
}

Potion::Potion(string name, Player *player, string effect, int effectPoints)
    : Items{ name, player }, effect{ effect }, effectPoints{ effectPoints } {}
