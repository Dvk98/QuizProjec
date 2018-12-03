#include "QuestionPackageManager.hpp"
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

QuestionPackageManager::QuestionPackageManager()
{
}



void QuestionPackageManager::load()
{
	std::string path = "Assets/Questions";

	for (const auto & p : fs::directory_iterator(path))
	{
		QuestionPackage questionPackage(p.path().filename().string());
		questionPackage.load(p.path().string());
		mQuestionPackages.emplace_back(questionPackage);
	}
}

std::vector<QuestionPackage> QuestionPackageManager::getQPs()
{
	return mQuestionPackages;
}