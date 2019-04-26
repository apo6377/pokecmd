#include <utility>

#include <utility>

//
// Auth: Alex Olds, Kevin Re
//

#include "pokemon.h"
#include "pokeType.h"
#include <iostream>
#include <vector>
#include <algorithm>

pokemon::pokemon(int n, const string &nm, pokeType::eleType typ1, pokeType::eleType typ2, double hgt,
                 double wgt, const string &abil1, const string &abil2, const string &hAbil) {
    name.assign(nm);
    type1 = typ1;
    type2 = typ2;
    height = hgt;
    weight = wgt;
    num = n;
    ability1.assign(abil1);
    ability2.assign(abil2);
    hiddenAbility.assign(hAbil);

    setWeaknesses();
    setResistances();
    setImmunities();

    // find and remove conflicting weaknesses and resistances

    for (pokeType::eleType &type : resistances) {
        if (find(weaknesses.begin(), weaknesses.end(), type) != weaknesses.end()) {

            weaknesses.erase(find(weaknesses.begin(), weaknesses.end(), type));
            resistances.erase(find(resistances.begin(), resistances.end(), type));
        }
    }

    // find and remove extra weaknesses and resistances that are also immunities
    for (pokeType::eleType &type : weaknesses) {
        if (find(immunities.begin(), immunities.end(), type) != immunities.end()) {
            weaknesses.erase(find(weaknesses.begin(), weaknesses.end(), type));
        }
    }

    for (pokeType::eleType &type : resistances) {
        if (find(immunities.begin(), immunities.end(), type) != immunities.end()) {
            resistances.erase(find(resistances.begin(), resistances.end(), type));
        }
    }

}

pokeType::eleType pokemon::getType1() const {
    return type1;
}

pokeType::eleType pokemon::getType2() const {
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

        case pokeType::Normal:

            weaknesses.push_back(pokeType::Fighting);
            break;
        case pokeType::Fighting:
            weaknesses.push_back(pokeType::Psychic);
            weaknesses.push_back(pokeType::Flying);
            weaknesses.push_back(pokeType::Fairy);
            break;
        case pokeType::Flying:
            weaknesses.push_back(pokeType::Electric);
            weaknesses.push_back(pokeType::Rock);
            weaknesses.push_back(pokeType::Ice);
            break;
        case pokeType::Poison:
            weaknesses.push_back(pokeType::Ground);
            weaknesses.push_back(pokeType::Psychic);
            break;
        case pokeType::Ground:
            weaknesses.push_back(pokeType::Water);
            weaknesses.push_back(pokeType::Grass);
            weaknesses.push_back(pokeType::Ice);
            break;
        case pokeType::Rock:
            weaknesses.push_back(pokeType::Water);
            weaknesses.push_back(pokeType::Grass);
            weaknesses.push_back(pokeType::Fighting);
            weaknesses.push_back(pokeType::Ground);
            weaknesses.push_back(pokeType::Steel);
            break;
        case pokeType::Bug:
            weaknesses.push_back(pokeType::Fire);
            weaknesses.push_back(pokeType::Flying);
            weaknesses.push_back(pokeType::Rock);
            break;
        case pokeType::Ghost:
            weaknesses.push_back(pokeType::Ghost);
            weaknesses.push_back(pokeType::Dark);
            break;
        case pokeType::Steel:
            weaknesses.push_back(pokeType::Fire);
            weaknesses.push_back(pokeType::Fighting);
            weaknesses.push_back(pokeType::Ground);
            break;
        case pokeType::Fire:
            weaknesses.push_back(pokeType::Water);
            weaknesses.push_back(pokeType::Ground);
            weaknesses.push_back(pokeType::Rock);
            break;
        case pokeType::Water:
            weaknesses.push_back(pokeType::Electric);
            weaknesses.push_back(pokeType::Grass);
            break;
        case pokeType::Grass:
            weaknesses.push_back(pokeType::Fire);
            weaknesses.push_back(pokeType::Ice);
            weaknesses.push_back(pokeType::Poison);
            weaknesses.push_back(pokeType::Flying);
            weaknesses.push_back(pokeType::Bug);
            break;
        case pokeType::Electric:
            weaknesses.push_back(pokeType::Ground);
            break;
        case pokeType::Psychic:
            weaknesses.push_back(pokeType::Bug);
            weaknesses.push_back(pokeType::Ghost);
            weaknesses.push_back(pokeType::Dark);
            break;
        case pokeType::Ice:
            weaknesses.push_back(pokeType::Fire);
            weaknesses.push_back(pokeType::Fighting);
            weaknesses.push_back(pokeType::Rock);
            weaknesses.push_back(pokeType::Steel);
            break;
        case pokeType::Dragon:
            weaknesses.push_back(pokeType::Dragon);
            weaknesses.push_back(pokeType::Ice);
            weaknesses.push_back(pokeType::Fairy);
            break;
        case pokeType::Dark:
            weaknesses.push_back(pokeType::Fighting);
            weaknesses.push_back(pokeType::Bug);
            weaknesses.push_back(pokeType::Fairy);
            break;
        case pokeType::Fairy:
            weaknesses.push_back(pokeType::Poison);
            weaknesses.push_back(pokeType::Steel);
            break;
        case pokeType::NONE:
            break;
    }

//TODO: add quad weaknesses

    switch (type2) {

        case pokeType::Normal:
            if (none_of(weaknesses.begin(), weaknesses.end(), [](int i) { return i == pokeType::Fighting; }))
                weaknesses.push_back(pokeType::Fighting);

            break;
        case pokeType::Fighting:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Psychic; }))
                weaknesses.push_back(pokeType::Psychic);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                weaknesses.push_back(pokeType::Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                weaknesses.push_back(pokeType::Fairy);

            break;
        case pokeType::Flying:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Electric; }))
                weaknesses.push_back(pokeType::Electric);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                weaknesses.push_back(pokeType::Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                weaknesses.push_back(pokeType::Ice);

            break;
        case pokeType::Poison:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                weaknesses.push_back(pokeType::Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Psychic; }))
                weaknesses.push_back(pokeType::Psychic);

            break;
        case pokeType::Ground:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Water; }))
                weaknesses.push_back(pokeType::Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                weaknesses.push_back(pokeType::Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                weaknesses.push_back(pokeType::Ice);

            break;
        case pokeType::Rock:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Water; }))
                weaknesses.push_back(pokeType::Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                weaknesses.push_back(pokeType::Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                weaknesses.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                weaknesses.push_back(pokeType::Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                weaknesses.push_back(pokeType::Steel);
            break;
        case pokeType::Bug:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                weaknesses.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                weaknesses.push_back(pokeType::Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                weaknesses.push_back(pokeType::Rock);
            break;
        case pokeType::Ghost:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ghost; }))
                weaknesses.push_back(pokeType::Ghost);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dark; }))
                weaknesses.push_back(pokeType::Dark);
            break;
        case pokeType::Steel:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                weaknesses.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                weaknesses.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                weaknesses.push_back(pokeType::Ground);

            break;
        case pokeType::Fire:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Water; }))
                weaknesses.push_back(pokeType::Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                weaknesses.push_back(pokeType::Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                weaknesses.push_back(pokeType::Rock);

            break;
        case pokeType::Water:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Electric; }))
                weaknesses.push_back(pokeType::Electric);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                weaknesses.push_back(pokeType::Grass);
            break;
        case pokeType::Grass:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                weaknesses.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                weaknesses.push_back(pokeType::Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Poison; }))
                weaknesses.push_back(pokeType::Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                weaknesses.push_back(pokeType::Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                weaknesses.push_back(pokeType::Bug);

            break;
        case pokeType::Electric:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                weaknesses.push_back(pokeType::Ground);
            break;
        case pokeType::Psychic:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                weaknesses.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ghost; }))
                weaknesses.push_back(pokeType::Ghost);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dark; }))
                weaknesses.push_back(pokeType::Dark);

            break;
        case pokeType::Ice:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                weaknesses.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                weaknesses.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                weaknesses.push_back(pokeType::Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                weaknesses.push_back(pokeType::Steel);

            break;
        case pokeType::Dragon:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dragon; }))
                weaknesses.push_back(pokeType::Dragon);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                weaknesses.push_back(pokeType::Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fairy; }))
                weaknesses.push_back(pokeType::Fairy);

            break;
        case pokeType::Dark:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                weaknesses.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                weaknesses.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fairy; }))
                weaknesses.push_back(pokeType::Fairy);

            break;
        case pokeType::Fairy:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Poison; }))
                weaknesses.push_back(pokeType::Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                weaknesses.push_back(pokeType::Steel);

            break;
        case pokeType::NONE:
            break;
    }
}

vector<pokeType::eleType> pokemon::getWeaknesses() {
    return weaknesses;
}

void pokemon::setResistances() {
    resistances.resize(0);

    switch (type1) {

        case pokeType::Normal:
            break;
        case pokeType::Fighting:
            resistances.push_back(pokeType::Rock);
            resistances.push_back(pokeType::Bug);
            resistances.push_back(pokeType::Dark);
            break;
        case pokeType::Flying:
            resistances.push_back(pokeType::Electric);
            resistances.push_back(pokeType::Rock);
            resistances.push_back(pokeType::Ice);
            break;
        case pokeType::Poison:
            resistances.push_back(pokeType::Fighting);
            resistances.push_back(pokeType::Poison);
            resistances.push_back(pokeType::Bug);
            resistances.push_back(pokeType::Fairy);
            break;
        case pokeType::Ground:
            resistances.push_back(pokeType::Poison);
            resistances.push_back(pokeType::Rock);
            break;
        case pokeType::Rock:
            resistances.push_back(pokeType::Normal);
            resistances.push_back(pokeType::Flying);
            resistances.push_back(pokeType::Poison);
            resistances.push_back(pokeType::Fire);
            break;
        case pokeType::Bug:
            resistances.push_back(pokeType::Fighting);
            resistances.push_back(pokeType::Ground);
            resistances.push_back(pokeType::Grass);
            break;
        case pokeType::Ghost:
            resistances.push_back(pokeType::Poison);
            resistances.push_back(pokeType::Bug);
            break;
        case pokeType::Steel:
            resistances.push_back(pokeType::Normal);
            resistances.push_back(pokeType::Flying);
            resistances.push_back(pokeType::Rock);
            resistances.push_back(pokeType::Bug);
            resistances.push_back(pokeType::Steel);
            resistances.push_back(pokeType::Grass);
            resistances.push_back(pokeType::Psychic);
            resistances.push_back(pokeType::Ice);
            resistances.push_back(pokeType::Dragon);
            resistances.push_back(pokeType::Fairy);
            break;
        case pokeType::Fire:
            resistances.push_back(pokeType::Bug);
            resistances.push_back(pokeType::Steel);
            resistances.push_back(pokeType::Fire);
            resistances.push_back(pokeType::Grass);
            resistances.push_back(pokeType::Ice);
            resistances.push_back(pokeType::Fairy);
            break;
        case pokeType::Water:
            resistances.push_back(pokeType::Steel);
            resistances.push_back(pokeType::Fire);
            resistances.push_back(pokeType::Water);
            resistances.push_back(pokeType::Ice);
            break;
        case pokeType::Grass:
            resistances.push_back(pokeType::Ground);
            resistances.push_back(pokeType::Water);
            resistances.push_back(pokeType::Grass);
            resistances.push_back(pokeType::Electric);
            break;
        case pokeType::Electric:
            resistances.push_back(pokeType::Flying);
            resistances.push_back(pokeType::Steel);
            resistances.push_back(pokeType::Electric);
            break;
        case pokeType::Psychic:
            resistances.push_back(pokeType::Fighting);
            resistances.push_back(pokeType::Psychic);
            break;
        case pokeType::Ice:
            resistances.push_back(pokeType::Ice);
            break;
        case pokeType::Dragon:
            resistances.push_back(pokeType::Fire);
            resistances.push_back(pokeType::Water);
            resistances.push_back(pokeType::Grass);
            resistances.push_back(pokeType::Electric);
            break;
        case pokeType::Dark:
            resistances.push_back(pokeType::Ghost);
            resistances.push_back(pokeType::Dark);
            break;
        case pokeType::Fairy:
            resistances.push_back(pokeType::Fighting);
            resistances.push_back(pokeType::Bug);
            resistances.push_back(pokeType::Dark);
            break;
        case pokeType::NONE:
            break;
    }

    switch (type2) {

        case pokeType::Normal:
            break;
        case pokeType::Fighting:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                resistances.push_back(pokeType::Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                resistances.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dark; }))
                resistances.push_back(pokeType::Dark);
            break;
        case pokeType::Flying:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Electric; }))
                resistances.push_back(pokeType::Electric);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                resistances.push_back(pokeType::Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                resistances.push_back(pokeType::Ice);
            break;
        case pokeType::Poison:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                resistances.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Poison; }))
                resistances.push_back(pokeType::Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                resistances.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fairy; }))
                resistances.push_back(pokeType::Fairy);
            break;
        case pokeType::Ground:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Poison; }))
                resistances.push_back(pokeType::Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                resistances.push_back(pokeType::Rock);
            break;
        case pokeType::Rock:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Normal; }))
                resistances.push_back(pokeType::Normal);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                resistances.push_back(pokeType::Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Poison; }))
                resistances.push_back(pokeType::Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                resistances.push_back(pokeType::Fire);
            break;
        case pokeType::Bug:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                resistances.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                resistances.push_back(pokeType::Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                resistances.push_back(pokeType::Grass);
            break;
        case pokeType::Ghost:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Poison; }))
                resistances.push_back(pokeType::Poison);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                resistances.push_back(pokeType::Bug);
            break;
        case pokeType::Steel:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Normal; }))
                resistances.push_back(pokeType::Normal);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                resistances.push_back(pokeType::Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Rock; }))
                resistances.push_back(pokeType::Rock);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                resistances.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                resistances.push_back(pokeType::Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                resistances.push_back(pokeType::Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Psychic; }))
                resistances.push_back(pokeType::Psychic);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                resistances.push_back(pokeType::Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dragon; }))
                resistances.push_back(pokeType::Dragon);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fairy; }))
                resistances.push_back(pokeType::Fairy);
            break;
        case pokeType::Fire:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                resistances.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                resistances.push_back(pokeType::Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                resistances.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                resistances.push_back(pokeType::Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                resistances.push_back(pokeType::Ice);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fairy; }))
                resistances.push_back(pokeType::Fairy);
            break;
        case pokeType::Water:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                resistances.push_back(pokeType::Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                resistances.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Water; }))
                resistances.push_back(pokeType::Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                resistances.push_back(pokeType::Ice);
            break;
        case pokeType::Grass:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ground; }))
                resistances.push_back(pokeType::Ground);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Water; }))
                resistances.push_back(pokeType::Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                resistances.push_back(pokeType::Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Electric; }))
                resistances.push_back(pokeType::Electric);
            break;
        case pokeType::Electric:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Flying; }))
                resistances.push_back(pokeType::Flying);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Steel; }))
                resistances.push_back(pokeType::Steel);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Electric; }))
                resistances.push_back(pokeType::Electric);
            break;
        case pokeType::Psychic:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                resistances.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Psychic; }))
                resistances.push_back(pokeType::Psychic);
            break;
        case pokeType::Ice:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ice; }))
                resistances.push_back(pokeType::Ice);
            break;
        case pokeType::Dragon:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fire; }))
                resistances.push_back(pokeType::Fire);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Water; }))
                resistances.push_back(pokeType::Water);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Grass; }))
                resistances.push_back(pokeType::Grass);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Electric; }))
                resistances.push_back(pokeType::Electric);
            break;
        case pokeType::Dark:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Ghost; }))
                resistances.push_back(pokeType::Ghost);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dark; }))
                resistances.push_back(pokeType::Dark);
            break;
        case pokeType::Fairy:
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Fighting; }))
                resistances.push_back(pokeType::Fighting);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Bug; }))
                resistances.push_back(pokeType::Bug);
            if (none_of(weaknesses.begin(), weaknesses.end(),
                        [](int i) { return i == pokeType::Dark; }))
                resistances.push_back(pokeType::Dark);
            break;
        case pokeType::NONE:
            break;
    }

}

vector<pokeType::eleType> pokemon::getResistances() {
    return resistances;
}

void pokemon::setImmunities() {
    immunities.resize(0);

    switch (type1) {
        case pokeType::Normal:
            immunities.push_back(pokeType::Ghost);
            break;
        case pokeType::Flying:
            immunities.push_back(pokeType::Ground);
            break;
        case pokeType::Ground:
            immunities.push_back(pokeType::Electric);
            break;
        case pokeType::Ghost:
            immunities.push_back(pokeType::Normal);
            immunities.push_back(pokeType::Fighting);
            break;
        case pokeType::Steel:
            immunities.push_back(pokeType::Poison);
            break;
        case pokeType::Dark:
            immunities.push_back(pokeType::Psychic);
            break;
        case pokeType::Fairy:
            immunities.push_back(pokeType::Dragon);
            break;
        default:
            break;
    }

    switch (type2) {
        case pokeType::Normal:
            immunities.push_back(pokeType::Ghost);
            break;
        case pokeType::Flying:
            immunities.push_back(pokeType::Ground);
            break;
        case pokeType::Ground:
            immunities.push_back(pokeType::Electric);
            break;
        case pokeType::Ghost:
            immunities.push_back(pokeType::Normal);
            immunities.push_back(pokeType::Fighting);
            break;
        case pokeType::Steel:
            immunities.push_back(pokeType::Poison);
            break;
        case pokeType::Dark:
            immunities.push_back(pokeType::Psychic);
            break;
        case pokeType::Fairy:
            immunities.push_back(pokeType::Dragon);
            break;
        default:
            break;
    }

    if (immunities.empty()) {
        immunities.push_back(pokeType::NONE);
    }
}

vector<pokeType::eleType> pokemon::getImmunities() {
    return immunities;
}

void pokemon::print(ostream &os) const {
    os << "#" << num << "   " << name << endl;
    os << type1 << "    " << type2 << endl;
    os << endl << "Ability 1: " << ability1 << endl;
    os << "Ability 2: " << ability2 << endl;
    os << "Hidden Ability: " << hiddenAbility << endl;
    os << "Height: " << height << " Meters" << endl;
    os << "Weight: " << weight << " Kilograms" << endl;
    os << endl << "Weaknesses: ";
    for (pokeType::eleType weakness : weaknesses){
        if (weakness != weaknesses[weaknesses.size()-1]) {
            os << weakness << ", ";
        }else{
            os << weakness << endl;
        }
    }
    os << "Resistances: ";
    for (pokeType::eleType resistance : resistances){
        if (resistance != resistances[resistances.size()-1]) {
            os << resistance << ", ";
        }else{
            os << resistance << endl;
        }
    }
    os << "Immunities: ";
    for (pokeType::eleType immunity : immunities){
        if (immunity != immunities[immunities.size()-1]) {
            os << immunity << ", ";
        }else{
            os << immunity << endl;
        }
    }
}