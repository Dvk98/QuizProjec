#pragma once
#include <vector>
#include "Game.hpp"
#include "GameMap.hpp"
#include "GameState.hpp"
#include "QuestionPackageManager.hpp"

class PlayingState : public GameState
{
public:
    explicit PlayingState(Game* game);

    void processInput(const sf::Event& event) final;

    void update(sf::Time delta) final;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

    void drawGui();

    void load();

private:
    tgui::Gui mGui;
    GameMap mMap;
    sf::Texture mTexture;
    std::vector<QuestionPackage*> mActiveQuestionPackages;
    std::vector<Question> mGameQuestions;
};
