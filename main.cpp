/* Main I/O class
 * Auth: Alex Olds, Kevin Re
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "pokemon.h"
#include "pokeType.h"
#include "human.h"

using namespace std;

void getPokemon(vector<pokemon> &p) {

    string temp, line, word;

    bool firstline = true;

    vector<string> row;


    row.resize(0);

    ifstream in("pokedex.csv", ifstream::in);


    if (!in.is_open()) {
        cout << "Error opening pokedex.csv" << endl;
        exit(EXIT_FAILURE);
    } else {
        while (in >> temp) {
            if (!firstline) {
                stringstream s(temp);
                row.clear();
                getline(in, line);

                while (getline(s, word, ',')) {
                    row.push_back(word);
                }

                pokemon tmp = pokemon(stoi(row[0]), row[1], pokeType::toType(row[2]), pokeType::toType(row[3]),
                                      stod(row[4]), stod(row[5]), row[6], row[7], row[8]);

                p.push_back(tmp);
            } else {
                firstline = false;
            }
        }
    }

}

void getHumans(vector<human> &h) {

    string temp, line, word;

    bool firstline = true;

    vector<string> row;


    row.resize(0);

    ifstream in("humans.csv", ifstream::in);


    if (!in.is_open()) {
        cout << "Error opening humans.csv" << endl;
        exit(EXIT_FAILURE);
    } else {
        while (in >> temp) {
            if (!firstline) {
                stringstream s(temp);
                row.clear();
                getline(in, line);

                while (getline(s, word, ',')) {
                    row.push_back(word);
                }

                human tmp = human(row[0], row[1], row[2]);

                h.push_back(tmp);
            } else {
                firstline = false;
            }
        }
    }
}

int main() {

    string input;
    int list;

    vector<pokemon> poke;
    vector<human> humans;

    getPokemon(poke);

    human oak = human("Samuel Oak", "Professor", "The Pokemon Professor");
    humans.push_back(oak);

    cout << "Welcome to the command line Pokedex!" << endl;
    cout << "Input 1 to browse Pokemon, 2 to browse humnans: ";

    while (!(input == "null")) {
        cin >> input;
        if (input == "1") {
            int num = 0;
            while (!(input == "q")) {
                cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                cout << "up: w, dn: s, quit: q" << endl;
                cout << poke[num];
                cout << ":";
                cin >> input;
                if (input == "q") {
                    input = input;
                } else if (input == "w") {
                    num++;
                    if (num > 250) {
                        num = 0;
                    }
                } else if (input == "s") {
                    num--;
                    if (num < 0) {
                        num = 250;
                    }
                } else if (!(input == "q")) {
                    input = input;
                } else if ((stoi(input) < 0) || (stoi(input) > 251)) {
                    num = stoi(input) - 1;
                }
            }

            input = "null";

        } else if (input == "2") {

        }
    }

    return 0;
}