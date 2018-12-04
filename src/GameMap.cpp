#include "GameMap.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

GameMap::GameMap() {}

void GameMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite);
}

void GameMap::setTexture(sf::Texture& texture)
{
    mSprite.setTexture(texture);
    // mSprite.setPosition(200.0, 200.0);
}

void GameMap::setScale(float x, float y)
{
    mSprite.setScale(x, y);
}

void GameMap::setPosition(float x, float y)
{
    std::cout << mSprite.getOrigin().x << " " << mSprite.getOrigin().y
              << std::endl;
    auto bounds = mSprite.getGlobalBounds();
    std::cout << bounds.width << " " << bounds.height << std::endl;
    mSprite.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
    std::cout << mSprite.getOrigin().x << " " << mSprite.getOrigin().y
              << std::endl;
    mSprite.setPosition(x, y);
}

sf::Vector2f GameMap::getSize()
{
    return sf::Vector2f(
        mSprite.getGlobalBounds().width, mSprite.getGlobalBounds().height);
}