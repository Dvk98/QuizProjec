#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class Game;

class GameState : public sf::Drawable
{
public:
	
	enum class EState
	{
		Title,
		Menu,
		Options,
		Lobby,
		Playing,
		Result,
		Count
	};
	
	GameState(Game* game);
		
	virtual void processInput(sf::Event event)=0;
	virtual void update(sf::Time delta)=0;
	virtual void drawGui() = 0;

public:
	const Game* pGame;
};

template <typename T>
void centerOrigin(T& drawable)
{
	sf::FloatRect bound = drawable.getLocalBounds();
	drawable.setOrigin(bound.width / 2, bound.height / 2);
}