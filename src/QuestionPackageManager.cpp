#include "QuestionPackageManager.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

QuestionPackageManager::QuestionPackageManager() {}

void QuestionPackageManager::load(const std::filesystem::path& rootPath)
{
    for (const auto& p :
         fs::directory_iterator(rootPath / "Assets" / "Questions")) {
        mQuestionPackages.emplace_back(p.path().string())
            .load(p.path().string());
    }
}

std::vector<QuestionPackage> QuestionPackageManager::getQPs()
{
    return mQuestionPackages;
}