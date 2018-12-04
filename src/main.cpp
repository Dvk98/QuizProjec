#include "Game.hpp"

#include <iostream>
#include <stdexcept>

int main(int argc, char** argv)
{
    try {
        Game game{std::filesystem::path{argv[0]}.remove_filename()};
        game.run();
    }
    catch (std::exception& e) {
        std::cout << "\nEXCEPTION: " << e.what() << std::endl;
    }
}