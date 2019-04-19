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

    pokemon(string nm, string dsc, pokemon::eleType typ1, pokemon::eleType typ2, double hgt,
            double wgt, int n, string abil1, string abil2, string hAbil);

    string getName() const;

    string getDesc() const;

    eleType getType1() const;

    eleType getType2() const;

    double getHeight() const;

    double getWeight() const;

    int getNum() const;

    string getAbility1() const;

    string getAbility2() const;

    string getHiddenAbility() const;


    vector<pokemon::eleType> getWeaknesses();

    vector<pokemon::eleType> getResistances();

    vector<pokemon::eleType> getImmunities();

    void print(ostream &os) const override;


private:

    string name;
    string desc;
    eleType type1;
    eleType type2;
    double height;
    double weight;
    int num;
    string ability1;
    string ability2;
    string hiddenAbility;
    vector<pokemon::eleType> weaknesses;
    vector<pokemon::eleType> resistances;
    vector<pokemon::eleType> immunities;

    void setWeaknesses();
    void setResistances();
    void setImmunities();
};


#endif //POKECMD_POKEMON_H
