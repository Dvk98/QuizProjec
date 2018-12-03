#pragma once
#include "GameState.hpp"
#include "Game.hpp"

class MenuState : public GameState 
{
public:
	MenuState(Game* game);

	void processInput(sf::Event event);
	void update(sf::Time delta);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	void drawGui();

private:
	tgui::Gui gui;
};