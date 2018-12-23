#pragma once
#include "Game.hpp"
#include "GameState.hpp"

class MenuState : public GameState
{
public:
    explicit MenuState(Game* game);

    void processInput(const sf::Event& event) final;

    void update(sf::Time delta) final;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

    void drawGui();

    void load();

private:
    tgui::Gui gui;
};
