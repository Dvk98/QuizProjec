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

    CollectionType questionPackages;

    Game* const pGame;

private:
};
