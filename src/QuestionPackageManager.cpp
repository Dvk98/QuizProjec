#include "QuestionPackageManager.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include "Game.hpp"

namespace fs = std::filesystem;

QuestionPackageManager::QuestionPackageManager(Game* game) : pGame(game) {}

void QuestionPackageManager::load()
{
    for (const auto& p :
         fs::directory_iterator(pGame->rootPath / "Assets" / "Questions")) {
        if (p.path().extension() == ".json") {
            questionPackages.emplace_back(p.path());
        }
    }
}
