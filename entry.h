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

    virtual void print(ostream &) const{}

public:
    friend ostream &operator<<(ostream &, const entry&);
};


#endif //POKECMD_ENTRY_H
