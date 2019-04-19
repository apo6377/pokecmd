/* Main I/O class
 * Auth: Alex Olds, Kevin Re
 */

#include <iostream>
#include "pokemon.h"
#include "human.h"

using namespace std;

int main() {

    pokemon pika = pokemon("Pikachu", "Electric Mouse Pokemon", pokemon::Electric, pokemon::Rock, 35, 43, 25, "Static", "-", "-");

    human oak = human("Samuel Oak", "Professor", "The Pokemon Professor");

    cout << pika;

    return 0;
}