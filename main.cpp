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

vector <pokemon> poke;

void getPokemon() {

    string temp, line, word;

    vector<string> row;

    row.resize(0);

    ifstream in;

    in.open("./pokedex.csv", ios::in);

    if (!in.is_open()) {
        cout << "Error opening pokedex.csv" << endl;
        exit(EXIT_FAILURE);
    } else {
        stringstream s(line);
        row.clear();
        getline(in, line);

        while (getline(s, word, ',')) {
            row.push_back(word);
        }

        pokemon tmp = pokemon(row[1], pokeType::toType(row[2]), pokeType::toType(row[3]), stod(row[4]), stod(row[5]),
                              stoi(row[0]), row[6], row[7], row[8]);

        poke.push_back(tmp);
    }

}

int main() {

    poke.resize(0);

    getPokemon();

    //poke = getPokemon();


    //pokemon pika = pokemon("Pikachu", pokeType::Electric, pokeType::Rock, 35, 43, 25, "Static", "-", "-");

    human oak = human("Samuel Oak", "Professor", "The Pokemon Professor");


    return 0;
}