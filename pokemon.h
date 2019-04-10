//
// Auth: Alex Olds, Kevin Re
//

#ifndef POKECMD_POKEMON_H
#define POKECMD_POKEMON_H

#include <vector>

using namespace std;

class pokemon {

public:

    enum eleType{Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Water, Grass, Electric,
        Psychic, Ice, Dragon, Dark, Fairy};

    pokemon(char *, char *, pokemon::eleType, pokemon::eleType, int, double, double, int, char *, char *);

    char *getName() const;

    char *getDesc() const;

    eleType getType1() const;

    eleType getType2() const;

    int getEvolveLevel() const;

    double getHeight() const;

    double getWeight() const;

    int getNum() const;

    char *getAbility() const;

    char *getHiddenAbility() const;

private:

    char * name;
    char * desc;
    eleType type1;
    eleType type2;
    int evolveLevel;
    double height;
    double weight;
    int num;
    char * ability;
    char * hiddenAbility;

    vector<pokemon::eleType> getWeaknesses();

    vector<pokemon::eleType> getResistances();

    vector<pokemon::eleType> getImmunities();
};


#endif //POKECMD_POKEMON_H
