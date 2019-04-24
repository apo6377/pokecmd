//
// Auth: Alex Olds, Kevin Re
//

#ifndef POKECMD_POKEMON_H
#define POKECMD_POKEMON_H

#include "entry.h"
#include "pokeType.h"
#include <vector>
#include <iostream>

using namespace std;

class pokemon : public entry {

public:

    pokemon(int n, const string &nm, pokeType::eleType typ1, pokeType::eleType typ2, double hgt,
            double wgt, const string &abil1, const string &abil2, const string &hAbil);

    string getName() const;

    string getDesc() const;

    pokeType::eleType getType1() const;

    pokeType::eleType getType2() const;

    double getHeight() const;

    double getWeight() const;

    int getNum() const;

    string getAbility1() const;

    string getAbility2() const;

    string getHiddenAbility() const;

    vector<pokeType::eleType> getWeaknesses();

    vector<pokeType::eleType> getResistances();

    vector<pokeType::eleType> getImmunities();

    void print(ostream &os) const override;


private:

    string name;
    string desc;
    pokeType::eleType type1;
    pokeType::eleType type2;
    double height;
    double weight;
    int num;
    string ability1;
    string ability2;
    string hiddenAbility;
    vector<pokeType::eleType> weaknesses;
    vector<pokeType::eleType> resistances;
    vector<pokeType::eleType> immunities;

    void setWeaknesses();

    void setResistances();

    void setImmunities();
};


#endif //POKECMD_POKEMON_H
