#pragma once
#include <SFML/Graphics.hpp>

class GameMap : public sf::Drawable
{
public:
    void setTexture(sf::Texture& texture);

    void setScale(float x, float y);

    void setPosition(float x, float y);

    sf::Vector2f getSize() const;

private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;

    sf::Sprite mSprite;
};