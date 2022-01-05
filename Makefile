CXX = g++
CXXFLAGS = -std=c++14 -g 
EXEC = cc3k
OBJECTS = main.o gamesys.o floor.o player.o character.o shade.o vampire.o drow.o troll.o goblin.o enemy.o human.o elf.o dwarf.o halfling.o orcs.o merchant.o items.o gold.o smallgold.o normalgold.o merchanthoard.o dragonhoard.o  potion.o restorehealth.o poisonhealth.o boostatk.o woundatk.o boostdef.o wounddef.o dragon.o drx.o dlcfloor.o dlcgamesys.o
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}
-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
