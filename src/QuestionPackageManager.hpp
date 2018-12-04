#pragma once
#include "QuestionPackage.hpp"
#include <vector>

class QuestionPackageManager
{
public:
	QuestionPackageManager();
	void load();

	std::vector<QuestionPackage> getQPs();

private:
	std::vector<QuestionPackage> mQuestionPackages;

};