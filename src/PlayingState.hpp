#pragma once
#include "Game.hpp"
#include "GameMap.hpp"
#include "GameState.hpp"
#include "QuestionPackageManager.hpp"
#include <vector>

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
    tgui::Gui   gui;
    GameMap     mMap;
    sf::Texture texture;
    //QuestionPackageManager& qpm;
    std::vector<QuestionPackage*> activeQuestionPackages;
    std::vector<Question> gameQuestions;
};
