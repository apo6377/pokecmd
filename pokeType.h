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

    friend ostream &operator<<(ostream &out, const pokeType &type) {

    }
};


#endif //POKECMD_POKETYPE_H
