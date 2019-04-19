#include <utility>

#include <utility>

#include <utility>

#include <utility>

#include <utility>

//
// Created by alex on 4/18/19.
//

#include "human.h"

using namespace std;

human::human(string nm, string titl, string des) {
    name = std::move(nm);
    title = std::move(titl);
    desc = std::move(des);
}

human::human(string nm, string titl, vector<pokemon> poke, string des) {
    name = std::move(nm);
    title = std::move(titl);
    team = move(poke);
    desc = std::move(des);
}

string human::getName() const {
    return name;
}

string human::getTitle() const {
    return title;
}

const vector<pokemon> &human::getTeam() const {
    return team;
}

string human::getDesc() const {
    return desc;
}

void human::print(ostream &os) const {
    //TODO: implement print
}
