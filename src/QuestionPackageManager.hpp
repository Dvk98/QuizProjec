#pragma once
#include "QuestionPackage.hpp"
#include <vector>

class QuestionPackageManager
{
public:
    QuestionPackageManager();

    void load(const std::filesystem::path& rootPath);

	std::vector<QuestionPackage> getQPs();

private:
	std::vector<QuestionPackage> mQuestionPackages;

};