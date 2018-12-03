#pragma once
#include "GameState.hpp"
#include "Game.hpp"

class LobbyState : public GameState
{
public:
	LobbyState(Game* game);

	void processInput(sf::Event event);
	void update(sf::Time delta);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	void drawGui();

private:
	tgui::Gui gui;
};