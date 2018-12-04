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
        mQuestionPackages.emplace_back(p.path().string())
            .load(p.path().string());
    }
}

std::vector<QuestionPackage> QuestionPackageManager::getQPs()
{
    return mQuestionPackages;
}