#pragma once
#include <SFML/Graphics.hpp>

class GameMap : public sf::Drawable
{
public:
	GameMap();
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	void setTexture(sf::Texture& texture);
	void setScale(float x, float y);
	void setPosition(float x, float y);


private:
	sf::Sprite mSprite;
};