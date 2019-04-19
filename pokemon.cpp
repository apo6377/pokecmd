#include <utility>

#include <utility>

//
// Auth: Alex Olds, Kevin Re
//

#include "pokemon.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pokemon::pokemon(string nm, string dsc, pokemon::eleType typ1, pokemon::eleType typ2, double hgt,
                 double wgt, int n, string abil1, string abil2, string hAbil) {
    name = std::move(nm);
    desc = std::move(dsc);
    type1 = typ1;
    type2 = typ2;
    height = hgt;
    weight = wgt;
    num = n;
    ability1 = std::move(abil1);
    ability2 = std::move(abil2);
    hiddenAbility = std::move(hAbil);

    setWeaknesses();
    setResistances();
    setImmunities();

    // find and remove conflicting weaknesses and resistances
    if (weaknesses.size() >= resistances.size()) {
        for (eleType &type : weaknesses) {
            if (find(resistances.begin(), resistances.end(), type) != resistances.end()) {

                weaknesses.erase(find(weaknesses.begin(), weaknesses.end(), type));
                resistances.erase(find(resistances.begin(), resistances.end(), type));
            }
        }
    }else{
        for (eleType &type : resistances) {
            if (find(weaknesses.begin(), weaknesses.end(), type) != weaknesses.end()) {

                weaknesses.erase(find(weaknesses.begin(), weaknesses.end(), type));
                resistances.erase(find(resistances.begin(), resistances.end(), type));
            }
        }
    }

    // find and remove extra weaknesses and resistances that are also immunities
    for(eleType &type : weaknesses){
        if (find(immunities.begin(), immunities.end(), type) != immunities.end()){
            weaknesses.erase(find(weaknesses.begin(), weaknesses.end(), type));
        }
    }

    for(eleType &type : resistances){
        if (find(immunities.begin(), immunities.end(), type) != immunities.end()){
            resistances.erase(find(resistances.begin(), resistances.end(), type));
        }
    }

}

string pokemon::getName() const {
    return name;
}

string pokemon::getDesc() const {
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

string pokemon::getAbility1() const {
    return ability1;
}

string pokemon::getAbility2() const {
    return ability2;
}

string pokemon::getHiddenAbility() const {
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
    resistances.resize(0);

    switch (type1) {

        case Normal:
            break;
        case Fighting:
            resistances.push_back(Rock);
            resistances.push_back(Bug);
            resistances.push_back(Dark);
            break;
        case Flying:
            resistances.push_back(Electric);
            resistances.push_back(Rock);
            resistances.push_back(Ice);
            break;
        case Poison:
            resistances.push_back(Fighting);
            resistances.push_back(Poison);
            resistances.push_back(Bug);
            resistances.push_back(Fairy);
            break;
        case Ground:
            resistances.push_back(Poison);
            resistances.push_back(Rock);
            break;
        case Rock:
            resistances.push_back(Normal);
            resistances.push_back(Flying);
            resistances.push_back(Poison);
            resistances.push_back(Fire);
            break;
        case Bug:
            resistances.push_back(Fighting);
            resistances.push_back(Ground);
            resistances.push_back(Grass);
            break;
        case Ghost:
            resistances.push_back(Poison);
            resistances.push_back(Bug);
            break;
        case Steel:
            resistances.push_back(Normal);
            resistances.push_back(Flying);
            resistances.push_back(Rock);
            resistances.push_back(Bug);
            resistances.push_back(Steel);
            resistances.push_back(Grass);
            resistances.push_back(Psychic);
            resistances.push_back(Ice);
            resistances.push_back(Dragon);
            resistances.push_back(Fairy);
            break;
        case Fire:
            resistances.push_back(Bug);
            resistances.push_back(Steel);
            resistances.push_back(Fire);
            resistances.push_back(Grass);
            resistances.push_back(Ice);
            resistances.push_back(Fairy);
            break;
        case Water:
            resistances.push_back(Steel);
            resistances.push_back(Fire);
            resistances.push_back(Water);
            resistances.push_back(Ice);
            break;
        case Grass:
            resistances.push_back(Ground);
            resistances.push_back(Water);
            resistances.push_back(Grass);
            resistances.push_back(Electric);
            break;
        case Electric:
            resistances.push_back(Flying);
            resistances.push_back(Steel);
            resistances.push_back(Electric);
            break;
        case Psychic:
            resistances.push_back(Fighting);
            resistances.push_back(Psychic);
            break;
        case Ice:
            resistances.push_back(Ice);
            break;
        case Dragon:
            resistances.push_back(Fire);
            resistances.push_back(Water);
            resistances.push_back(Grass);
            resistances.push_back(Electric);
            break;
        case Dark:
            resistances.push_back(Ghost);
            resistances.push_back(Dark);
            break;
        case Fairy:
            resistances.push_back(Fighting);
            resistances.push_back(Bug);
            resistances.push_back(Dark);
            break;
        case NONE:
            break;
    }

    switch (type2) {

        case Normal:
            break;
        case Fighting:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                resistances.push_back(Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                resistances.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dark; }))
                resistances.push_back(Dark);
            break;
        case Flying:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Electric; }))
                resistances.push_back(Electric);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                resistances.push_back(Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                resistances.push_back(Ice);
            break;
        case Poison:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                resistances.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Poison; }))
                resistances.push_back(Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                resistances.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fairy; }))
                resistances.push_back(Fairy);
            break;
        case Ground:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Poison; }))
                resistances.push_back(Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                resistances.push_back(Rock);
            break;
        case Rock:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Normal; }))
                resistances.push_back(Normal);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                resistances.push_back(Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Poison; }))
                resistances.push_back(Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                resistances.push_back(Fire);
            break;
        case Bug:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                resistances.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                resistances.push_back(Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                resistances.push_back(Grass);
            break;
        case Ghost:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Poison; }))
                resistances.push_back(Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                resistances.push_back(Bug);
            break;
        case Steel:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Normal; }))
                resistances.push_back(Normal);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                resistances.push_back(Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Rock; }))
                resistances.push_back(Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                resistances.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                resistances.push_back(Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                resistances.push_back(Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Psychic; }))
                resistances.push_back(Psychic);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                resistances.push_back(Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dragon; }))
                resistances.push_back(Dragon);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fairy; }))
                resistances.push_back(Fairy);
            break;
        case Fire:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                resistances.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                resistances.push_back(Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                resistances.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                resistances.push_back(Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                resistances.push_back(Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fairy; }))
                resistances.push_back(Fairy);
            break;
        case Water:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                resistances.push_back(Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                resistances.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Water; }))
                resistances.push_back(Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                resistances.push_back(Ice);
            break;
        case Grass:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ground; }))
                resistances.push_back(Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Water; }))
                resistances.push_back(Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                resistances.push_back(Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Electric; }))
                resistances.push_back(Electric);
            break;
        case Electric:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Flying; }))
                resistances.push_back(Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Steel; }))
                resistances.push_back(Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Electric; }))
                resistances.push_back(Electric);
            break;
        case Psychic:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                resistances.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Psychic; }))
                resistances.push_back(Psychic);
            break;
        case Ice:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ice; }))
                resistances.push_back(Ice);
            break;
        case Dragon:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fire; }))
                resistances.push_back(Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Water; }))
                resistances.push_back(Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Grass; }))
                resistances.push_back(Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Electric; }))
                resistances.push_back(Electric);
            break;
        case Dark:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Ghost; }))
                resistances.push_back(Ghost);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dark; }))
                resistances.push_back(Dark);
            break;
        case Fairy:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Fighting; }))
                resistances.push_back(Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Bug; }))
                resistances.push_back(Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == Dark; }))
                resistances.push_back(Dark);
            break;
        case NONE:
            break;
    }

}

vector<pokemon::eleType> pokemon::getResistances() {
    return resistances;
}

void pokemon::setImmunities() {
    immunities.resize(0);

    switch (type1) {
        case Normal:
            immunities.push_back(Ghost);
            break;
        case Flying:
            immunities.push_back(Ground);
            break;
        case Ground:
            immunities.push_back(Electric);
            break;
        case Ghost:
            immunities.push_back(Normal);
            immunities.push_back(Fighting);
            break;
        case Steel:
            immunities.push_back(Poison);
            break;
        case Dark:
            immunities.push_back(Psychic);
            break;
        case Fairy:
            immunities.push_back(Dragon);
            break;
        default:
            break;
    }

    switch (type2) {
        case Normal:
            immunities.push_back(Ghost);
            break;
        case Flying:
            immunities.push_back(Ground);
            break;
        case Ground:
            immunities.push_back(Electric);
            break;
        case Ghost:
            immunities.push_back(Normal);
            immunities.push_back(Fighting);
            break;
        case Steel:
            immunities.push_back(Poison);
            break;
        case Dark:
            immunities.push_back(Psychic);
            break;
        case Fairy:
            immunities.push_back(Dragon);
            break;
        default:
            break;
    }

    if (immunities.empty()) {
        immunities.push_back(NONE);
    }
}

vector<pokemon::eleType> pokemon::getImmunities() {
    return immunities;
}

void pokemon::print(ostream &os) const {
    //TODO: implement print
}


