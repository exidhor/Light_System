#include "VarConfig.h"
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;

int main(int argc, char* argv[]) {

    /* Code adapted from the SFML 2 "Window" example */

    cout << "Version " << GAME_VERSION_MAJOR << "." << GAME_VERSION_MINOR << "." << GAME_VERSION_PATCH << endl;

    sf::Window App(sf::VideoMode(800, 600), "myproject");

    while (App.isOpen()) {
        sf::Event Event;
        while (App.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                App.close();
        }
        App.display();
    }
}