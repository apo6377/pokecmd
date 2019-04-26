/* Main I/O class
 * Auth: Alex Olds, Kevin Re
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
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

    ifstream in("humandex.csv", ifstream::in);


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

                for(int i = 0; i < row.size(); i++){
                    std::replace(row[i].begin(), row[i].end(), '_', ' ');
                }

                human tmp = human(row[0], row[1], row[2], row[3], row[4]);

                h.push_back(tmp);
            } else {
                firstline = false;
            }
        }
    }
}

int main() {

    string input;
    bool err = false;
    bool quit = false;

    vector<pokemon> poke;
    vector<human> humans;

    getPokemon(poke);
    getHumans(humans);

    //human oak = human("Samuel Oak", "Professor", "The Pokemon Professor", "Pallet Town", "Kanto");
    //humans.push_back(oak);

    cout << "Welcome to the command line Pokedex!" << endl;


    // user control loops

    while (!quit) {
        cout << "Input 1 to browse Pokemon, 2 to browse humnans, 3 to battle pokemon: ";
        cin >> input;
        while (!(input == "null")) {
            if (input == "q") {
                input = "null";
                quit = true;
            }else if (input == "1") {
                int num = 0;
                while (!(input == "q")) {
                    if (!err) {
                        cout << "up: w, dn: s, quit: q" << endl;
                        cout << poke[num];
                        cout << ":";
                        cin >> input;
                    }
                    if (input == "q") {
                        err = false;
                        input = input;
                    } else if (input == "w") {
                        err = false;
                        num++;
                        if (num > 250) {
                            num = 0;
                        }
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    } else if (input == "s") {
                        err = false;
                        num--;
                        if (num < 0) {
                            num = 250;
                        }
                        cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
                    } else if (!(input == "q")) {
                        try {
                            num = stoi(input) - 1;
                            err = false;
                        } catch (invalid_argument &ex) {
                            err = true;
                            cout << "Invalid Command" << endl << ":";
                            cin >> input;
                        }
                    }
                }

                input = "null";

            } else if (input == "2") {
                int num = 0;
                while (!(input == "q")) {
                    cout << "up: w, dn: s, quit: q" << endl;
                    cout << "\n\n\n\n\n\n\n\n\n";
                    cout << humans[num];
                    cout << ":";
                    cin >> input;
                    if (input == "q") {
                        input = input;
                    } else if (input == "w") {
                        num++;
                        if (num > 27) {
                            num = 0;
                        }
                    } else if (input == "s") {
                        num--;
                        if (num < 0) {
                            num = 27;
                        }
                    } else if (!(input == "q")) {
                        input = input;
                    }
                }

                input = "null";
            } else if (input == "3") {
                string in;
                cout << "Enter the pokedex # of pokemon 1: ";
                cin >> in;
                pokemon poke1 = poke[stoi(in) - 1];
                cout << "Enter the pokedex # of pokemon 2: ";
                cin >> in;
                pokemon poke2 = poke[stoi(in) - 1];

                cout << "Pokemon 1: " << poke1.getName() << endl;
                cout << "Pokemon 2: " << poke2.getName() << endl;

                double poke1Score = (random() % 10) * poke1.getWeight() + poke1.getHeight();
                double poke2Score = (random() % 10) * poke2.getWeight() + poke2.getHeight();


                if (poke1Score > poke2Score) {
                    cout << poke1.getName() << " Wins!" << endl << endl;
                } else if (poke1Score < poke2Score) {
                    cout << poke2.getName() << " Wins!" << endl << endl;
                } else {
                    cout << "Tie!" << endl << endl;
                }

                input = "null";
            }
        }
    }

    return 0;
}