/* Main I/O class
 * Auth: Alex Olds, Kevin Re
 */

#include <iostream>
#include "pokemon.h"
#include "human.h"

int main() {

    pokemon pika = pokemon("Pikachu", "Electric Mouse Pokemon", pokemon::Electric, pokemon::Rock, 35, 43, 25, "Static", "-", "-");

    human oak = human("Samuel Oak", "Professor", "The Pokemon Professor");

    std::cout << "Hello, steve!" << std::endl;
    return 0;
}