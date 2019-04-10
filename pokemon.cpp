//
// Created by alex on 4/10/19.
//

#include "pokemon.h"
#include "pokeType.h"
#include <vector>

using namespace std;

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

    switch (type1) {

        case Normal: break;
        case Fighting:break;
        case Flying:break;
        case Poison:break;
        case Ground:break;
        case Rock:break;
        case Bug:break;
        case Ghost:break;
        case Steel:break;
        case Fire:break;
        case Water:break;
        case Grass:break;
        case Electric:break;
        case Psychic:break;
        case Ice:break;
        case Dragon:break;
        case Dark:break;
        case Fairy:break;
    }
}

vector<pokemon::eleType> pokemon::getResistances() {

}

vector<pokemon::eleType> pokemon::getImmunities() {

}
