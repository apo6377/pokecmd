//
// Auth: Alex Olds, Kevin Re
//

#ifndef POKECMD_POKEMON_H
#define POKECMD_POKEMON_H

#include "entry.h"
#include <vector>
#include <iostream>

using namespace std;

class pokemon: public entry {

public:

    enum eleType{Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Water, Grass, Electric,
        Psychic, Ice, Dragon, Dark, Fairy, NONE};

    pokemon(char *, char *, pokemon::eleType, pokemon::eleType, double, double, int, char *, char *, char *);

    char *getName() const;

    char *getDesc() const;

    eleType getType1() const;

    eleType getType2() const;

    double getHeight() const;

    double getWeight() const;

    int getNum() const;

    char *getAbility1() const;

    char *getAbility2() const;

    char *getHiddenAbility() const;


    vector<pokemon::eleType> getWeaknesses();

    vector<pokemon::eleType> getResistances();

    vector<pokemon::eleType> getImmunities();

    void print(ostream &os) const override;


private:

    char * name;
    char * desc;
    eleType type1;
    eleType type2;
    double height;
    double weight;
    int num;
    char * ability1;
    char * ability2;
    char * hiddenAbility;
    vector<pokemon::eleType> weaknesses;
    vector<pokemon::eleType> resistances;
    vector<pokemon::eleType> immunities;

    void setWeaknesses();
    void setResistances();
    void setImmunities();
};


#endif //POKECMD_POKEMON_H
