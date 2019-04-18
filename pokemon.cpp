//
// Auth: Alex Olds, Kevin Re
//

#include "pokemon.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pokemon::pokemon(char *nm, char *dsc, pokemon::eleType typ1, pokemon::eleType typ2, double hgt,
                 double wgt, int n, char *abil1, char *abil2, char *hAbil) {
    name = nm;
    desc = dsc;
    type1 = typ1;
    type2 = typ2;
    height = hgt;
    weight = wgt;
    num = n;
    ability1 = abil1;
    ability2 = abil2;
    hiddenAbility = hAbil;

    setWeaknesses();
    setResistances();
    setImmunities();


}

char *pokemon::getName() const {
    return name;
}

char *pokemon::getDesc() const {
    return desc;
}

pokemon::eleType pokemon::getType1() const {
    return type1;
}

pokemon::eleType pokemon::getType2() const {
    return type2;
}

double pokemon::getHeight() const {
    return height;
}

double pokemon::getWeight() const {
    return weight;
}

int pokemon::getNum() const {
    return num;
}

char *pokemon::getAbility1() const {
    return ability1;
}

char *pokemon::getAbility2() const {
    return ability2;
}

char *pokemon::getHiddenAbility() const {
    return hiddenAbility;
}

void pokemon::setWeaknesses() {
    weaknesses.resize(0);

    switch (type1) {

        case Normal:

            weaknesses.push_back(Fighting);
            break;
        case Fighting:
            weaknesses.push_back(Psychic);
            weaknesses.push_back(Flying);
            weaknesses.push_back(Fairy);
            break;
        case Flying:
            weaknesses.push_back(Electric);
            weaknesses.push_back(Rock);
            weaknesses.push_back(Ice);
            break;
        case Poison:
            weaknesses.push_back(Ground);
            weaknesses.push_back(Psychic);
            break;
        case Ground:
            weaknesses.push_back(Water);
            weaknesses.push_back(Grass);
            weaknesses.push_back(Ice);
            break;
        case Rock:
            weaknesses.push_back(Water);
            weaknesses.push_back(Grass);
            weaknesses.push_back(Fighting);
            weaknesses.push_back(Ground);
            weaknesses.push_back(Steel);
            break;
        case Bug:
            weaknesses.push_back(Fire);
            weaknesses.push_back(Flying);
            weaknesses.push_back(Rock);
            break;
        case Ghost:
            weaknesses.push_back(Ghost);
            weaknesses.push_back(Dark);
            break;
        case Steel:
            weaknesses.push_back(Fire);
            weaknesses.push_back(Fighting);
            weaknesses.push_back(Ground);
            break;
        case Fire:
            weaknesses.push_back(Water);
            weaknesses.push_back(Ground);
            weaknesses.push_back(Rock);
            break;
        case Water:
            weaknesses.push_back(Electric);
            weaknesses.push_back(Grass);
            break;
        case Grass:
            weaknesses.push_back(Fire);
            weaknesses.push_back(Ice);
            weaknesses.push_back(Poison);
            weaknesses.push_back(Flying);
            weaknesses.push_back(Bug);
            break;
        case Electric:
            weaknesses.push_back(Ground);
            break;
        case Psychic:
            weaknesses.push_back(Bug);
            weaknesses.push_back(Ghost);
            weaknesses.push_back(Dark);
            break;
        case Ice:
            weaknesses.push_back(Fire);
            weaknesses.push_back(Fighting);
            weaknesses.push_back(Rock);
            weaknesses.push_back(Steel);
            break;
        case Dragon:
            weaknesses.push_back(Dragon);
            weaknesses.push_back(Ice);
            weaknesses.push_back(Fairy);
            break;
        case Dark:
            weaknesses.push_back(Fighting);
            weaknesses.push_back(Bug);
            weaknesses.push_back(Fairy);
            break;
        case Fairy:
            weaknesses.push_back(Poison);
            weaknesses.push_back(Steel);
            break;
        case NONE:
            break;
    }

//TODO: add quad weaknesses

    switch (type2) {

        case Normal:
            if (none_of(weaknesses.begin(), weaknesses.end(), [](int i) { return i == Fighting; }))
                weaknesses.push_back(Fighting);

            break;
        case Fighting:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Psychic; }))
                weaknesses.push_back(Psychic);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                weaknesses.push_back(Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                weaknesses.push_back(Fairy);

            break;
        case Flying:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Electric; }))
                weaknesses.push_back(Electric);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                weaknesses.push_back(Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                weaknesses.push_back(Ice);

            break;
        case Poison:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                weaknesses.push_back(Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Psychic; }))
                weaknesses.push_back(Psychic);

            break;
        case Ground:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Water; }))
                weaknesses.push_back(Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                weaknesses.push_back(Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                weaknesses.push_back(Ice);

            break;
        case Rock:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Water; }))
                weaknesses.push_back(Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                weaknesses.push_back(Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                weaknesses.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                weaknesses.push_back(Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                weaknesses.push_back(Steel);
            break;
        case Bug:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                weaknesses.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                weaknesses.push_back(Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                weaknesses.push_back(Rock);
            break;
        case Ghost:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ghost; }))
                weaknesses.push_back(Ghost);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dark; }))
                weaknesses.push_back(Dark);
            break;
        case Steel:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                weaknesses.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                weaknesses.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                weaknesses.push_back(Ground);

            break;
        case Fire:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Water; }))
                weaknesses.push_back(Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                weaknesses.push_back(Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                weaknesses.push_back(Rock);

            break;
        case Water:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Electric; }))
                weaknesses.push_back(Electric);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                weaknesses.push_back(Grass);
            break;
        case Grass:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                weaknesses.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                weaknesses.push_back(Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Poison; }))
                weaknesses.push_back(Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                weaknesses.push_back(Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                weaknesses.push_back(Bug);

            break;
        case Electric:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                weaknesses.push_back(Ground);
            break;
        case Psychic:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                weaknesses.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ghost; }))
                weaknesses.push_back(Ghost);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dark; }))
                weaknesses.push_back(Dark);

            break;
        case Ice:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                weaknesses.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                weaknesses.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                weaknesses.push_back(Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                weaknesses.push_back(Steel);

            break;
        case Dragon:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dragon; }))
                weaknesses.push_back(Dragon);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                weaknesses.push_back(Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fairy; }))
                weaknesses.push_back(Fairy);

            break;
        case Dark:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                weaknesses.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                weaknesses.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fairy; }))
                weaknesses.push_back(Fairy);

            break;
        case Fairy:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Poison; }))
                weaknesses.push_back(Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                weaknesses.push_back(Steel);

            break;
        case NONE:
            break;
    }
}

vector<pokemon::eleType> pokemon::getWeaknesses() {
    return weaknesses;
}

void pokemon::setResistances() {

}

vector<pokemon::eleType> pokemon::getResistances() {

    resistances.resize(0);
    //TODO: Implement Resistances

    return resistances;
}

void pokemon::setImmunities() {

}

vector<pokemon::eleType> pokemon::getImmunities() {

    immunities.resize(0);
    //TODO: Implement Immunities

    return immunities;
}

void pokemon::print(ostream &os) const {
    entry::print(os);
}


