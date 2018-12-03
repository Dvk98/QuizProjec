#include "PlayingState.hpp"
#include <iostream>

PlayingState::PlayingState(Game* game)
	: GameState(game)
	, gui(game->getWindow())
{

	tgui::Theme theme{ "Assets/Black.txt" };


	auto wide = game->getWindow().getSize().x;
	auto height = game->getWindow().getSize().y;

	if (!texture.loadFromFile("Assets/Map_Bereinigt.png"))
	{
		std::cout << ("Failed to Load map.png");
	}
	mMap.setTexture(texture);
	mMap.setPosition(wide / 2, height / 2);
	//mGameMap.setScale(0.25f, 0.25f);

}

void PlayingState::processInput(sf::Event event)
{
	gui.handleEvent(event);
}

void PlayingState::drawGui()
{
	gui.draw();
}

void PlayingState::update(sf::Time delta)
{

}

void PlayingState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
