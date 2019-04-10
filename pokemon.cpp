//
// Auth: Alex Olds, Kevin Re
//

#include "pokemon.h"
#include <vector>

using namespace std;

pokemon::pokemon(char *nm, char *dsc, pokemon::eleType typ1, pokemon::eleType typ2, int evoLvl, double hgt,
                 double wgt, int n, char *abil, char *hAbil){
    name = nm;
    desc = dsc;
    type1 = typ1;
    type2 = typ2;
    evolveLevel = evoLvl;
    height = hgt;
    weight = wgt;
    num = n;
    ability = abil;
    hiddenAbility = hAbil;

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

int pokemon::getEvolveLevel() const {
    return evolveLevel;
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

char *pokemon::getAbility() const {
    return ability;
}

char *pokemon::getHiddenAbility() const {
    return hiddenAbility;
}

vector<pokemon::eleType> pokemon::getWeaknesses() {

    vector<eleType> weaknesses;

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
    }

    //TODO: check for duplicate weaknesses & add quad weaknesses

    switch (type2) {

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
    }

    return weaknesses;
}

vector<pokemon::eleType> pokemon::getResistances() {
    //TODO: Implement resistances
}

vector<pokemon::eleType> pokemon::getImmunities() {
    //TODO: Implement Immunities
}


