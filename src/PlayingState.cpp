#include "PlayingState.hpp"
#include <iostream>

PlayingState::PlayingState(Game* game) : GameState(game), gui(game->getWindow())
{
    tgui::Theme theme{(game->rootPath / "Assets" / "Black.txt").string()};

    const auto width  = game->getWindow().getSize().x;
    const auto height = game->getWindow().getSize().y;

    if (!texture.loadFromFile(
            (game->rootPath / "Assets" / "Map_Bereinigt.png").string())) {
        std::cout << "Failed to Load map.png";
    }
    mMap.setTexture(texture);
    mMap.setPosition(width / 2, height / 2);
    // mGameMap.setScale(0.25f, 0.25f);
}

void PlayingState::processInput(sf::Event event)
{
    gui.handleEvent(event);
}

void PlayingState::drawGui()
{
    gui.draw();
}

void PlayingState::update(sf::Time delta) {}

void PlayingState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}
