#pragma once
#pragma once
#include "GameState.hpp"
#include "GameMap.hpp"
#include "Game.hpp"

class PlayingState : public GameState
{
public:
	PlayingState(Game* game);

	void processInput(sf::Event event);
	void update(sf::Time delta);
	void draw(sf::RenderTarget& target, sf::RenderStates states) const final;
	void drawGui();

private:
	tgui::Gui gui;
	GameMap mMap;
	sf::Texture texture;

};