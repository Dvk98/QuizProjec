#pragma once
#include "Game.hpp"
#include "GameState.hpp"

class LobbyState : public GameState
{
public:
    explicit LobbyState(Game* game);

    void processInput(const sf::Event& event) final;

    void update(sf::Time delta) final;

    void draw(sf::RenderTarget& target, sf::RenderStates states) const final;

    void drawGui();

private:
    tgui::Gui gui;
};