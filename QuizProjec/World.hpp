#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>

class World : private sf::NonCopyable, public sf::Drawable
{
public:
	World();
	void update(sf::Time elapsedTime);
	
private:
	void draw(sf::RenderTarget& target, sf::RenderStates states);

};