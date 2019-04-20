/* Main I/O class
 * Auth: Alex Olds, Kevin Re
 */

#include <iostream>
#include "pokemon.h"
#include "pokeType.h"
#include "human.h"

using namespace std;

int main() {

    pokemon pika = pokemon("Pikachu", "the Electric Mouse Pokemon", pokeType::Electric, pokeType::Rock, 35, 43, 25, "Static", "-", "-");

    human oak = human("Samuel Oak", "Professor", "The Pokemon Professor");

    cout << pika;

    return 0;
}