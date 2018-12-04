#include "Game.hpp"

#include <iostream>
#include <stdexcept>

int main()
{
    try {
        Game game;
        game.run();
    }
    catch (std::exception& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}