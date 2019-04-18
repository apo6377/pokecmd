//
// Created by alex on 4/18/19.
//

#ifndef POKECMD_HUMAN_H
#define POKECMD_HUMAN_H

#include "entry.h"
#include "pokemon.h"
#include <iostream>

using namespace std;

class human: public entry {

public:


private:
    char * name;
    char * title;
    vector <pokemon> team;
    char * desc;

};


#endif //POKECMD_HUMAN_H
