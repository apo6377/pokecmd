//
// Created by alex on 4/19/19.
//

#ifndef POKECMD_POKETYPE_H
#define POKECMD_POKETYPE_H

class pokeType {

public:

    enum eleType {
        Normal, Fighting, Flying, Poison, Ground, Rock, Bug, Ghost, Steel, Fire, Water, Grass, Electric,
        Psychic, Ice, Dragon, Dark, Fairy, NONE
    };

    friend ostream &operator<<(ostream &out, const pokeType::eleType &type) {

        switch (type){

            case Normal: out << "Normal"; break;
            case Fighting: out << "Fighting"; break;
            case Flying: out << "Flying"; break;
            case Poison: out << "Poison"; break;
            case Ground: out << "Ground"; break;
            case Rock: out << "Rock"; break;
            case Bug: out << "Bug"; break;
            case Ghost: out << "Ghost"; break;
            case Steel: out << "Steel"; break;
            case Fire: out << "Fire"; break;
            case Water: out << "Water"; break;
            case Grass: out << "Grass"; break;
            case Electric: out << "Electric"; break;
            case Psychic: out << "Psychic"; break;
            case Ice: out << "Ice"; break;
            case Dragon: out << "Dragon"; break;
            case Dark: out << "Dark"; break;
            case Fairy: out << "Fairy"; break;
            case NONE:break;
        }

        return out;
    }
};


#endif //POKECMD_POKETYPE_H
