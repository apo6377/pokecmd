//
// Created by alex on 4/18/19.
//

#ifndef POKECMD_HUMAN_H
#define POKECMD_HUMAN_H

#include "entry.h"
#include "pokemon.h"
#include <iostream>

using namespace std;

class human : public entry {

public:

    human(string nm, string title, string desc);

    human(string nm, string title, string loc, string reg, string desc);

    string getTitle() const;

    const vector<pokemon> &getTeam() const;

    string getDesc() const;

    void print(ostream &os) const override;


private:
    string title;
    vector<pokemon> team;
    string desc;
    string location;
    string region;

};


#endif //POKECMD_HUMAN_H
