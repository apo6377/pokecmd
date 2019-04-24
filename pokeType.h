//
// Created by alex on 4/19/19.
//

#ifndef POKECMD_POKETYPE_H
#define POKECMD_POKETYPE_H

#include <string>

class pokeType {

public:

    enum eleType {
        Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Water, Grass, Electric,
        Psychic, Ice, Dragon, Dark, Fairy, NONE
    };

    static eleType toType(string str) {
        if (str == "Normal") {
            return Normal;
        } else if (str == "Fighting") {
            return Fighting;
        } else if (str == "Flying") {
            return Flying;
        } else if (str == "Poison") {
            return Poison;
        } else if (str == "Ground") {
            return Ground;
        } else if (str == "Rock") {
            return Rock;
        } else if (str == "Bug") {
            return Bug;
        } else if (str == "Ghost") {
            return Ghost;
        } else if (str == "Steel") {
            return Steel;
        } else if (str == "Fire") {
            return Fire;
        } else if (str == "Water") {
            return Water;
        } else if (str == "Grass") {
            return Grass;
        } else if (str == "Electric") {
            return Electric;
        } else if (str == "Psychic") {
            return Psychic;
        } else if (str == "Ice") {
            return Ice;
        } else if (str == "Dragon") {
            return Dragon;
        } else if (str == "Dark") {
            return Dark;
        } else if (str == "Fairy") {
            return Fairy;
        } else {
            return NONE;
        }
    }

    friend ostream &operator<<(ostream &out, const pokeType::eleType &type) {

        switch (type) {

            case Normal:
                out << "Normal";
                break;
            case Fighting:
                out << "Fighting";
                break;
            case Flying:
                out << "Flying";
                break;
            case Poison:
                out << "Poison";
                break;
            case Ground:
                out << "Ground";
                break;
            case Rock:
                out << "Rock";
                break;
            case Bug:
                out << "Bug";
                break;
            case Ghost:
                out << "Ghost";
                break;
            case Steel:
                out << "Steel";
                break;
            case Fire:
                out << "Fire";
                break;
            case Water:
                out << "Water";
                break;
            case Grass:
                out << "Grass";
                break;
            case Electric:
                out << "Electric";
                break;
            case Psychic:
                out << "Psychic";
                break;
            case Ice:
                out << "Ice";
                break;
            case Dragon:
                out << "Dragon";
                break;
            case Dark:
                out << "Dark";
                break;
            case Fairy:
                out << "Fairy";
                break;
            case NONE:
                break;
        }

        return out;
    }
};


#endif //POKECMD_POKETYPE_H
