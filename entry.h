//
// Created by alex on 4/17/19.
//

#ifndef POKECMD_ENTRY_H
#define POKECMD_ENTRY_H

#include <iostream>
#include <vector>

using namespace std;

class entry {

protected:

    string name;
    virtual void print(ostream &) const {}

public:
    friend ostream &operator<<(ostream &out, const entry &entry) {
        entry.print(out);
        return out;
    }

    string getName(){
        return name;
    }
};


#endif //POKECMD_ENTRY_H
