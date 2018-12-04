#pragma once

#include <vector>
#include "QuestionPackage.hpp"

class Game;

class QuestionPackageManager
{
public:
    explicit QuestionPackageManager(Game*game);

    void load();

    Game* const pGame;
	std::vector<QuestionPackage> getQPs();

private:
    std::vector<QuestionPackage> mQuestionPackages;
};