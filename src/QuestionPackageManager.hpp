#pragma once

#include <vector>
#include "QuestionPackage.hpp"

class Game;

class QuestionPackageManager
{
    using CollectionType = std::vector<QuestionPackage>;

public:
    explicit QuestionPackageManager(Game* game);

    void load();

    const CollectionType& getQPs() const;

    Game* const pGame;

private:
    CollectionType mQuestionPackages;
};
