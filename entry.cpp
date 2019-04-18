//
// Created by alex on 4/17/19.
//

#include "entry.h"

ostream &operator<<(ostream &out, const entry &entry) {
    entry.print(out);
    return out;
}
