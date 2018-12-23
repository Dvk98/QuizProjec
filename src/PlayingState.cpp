#include "PlayingState.hpp"
#include <iostream>

PlayingState::PlayingState(Game* game) : GameState(game), gui(game->window) //qpm(game->questionPackageManager)
{
    tgui::Theme theme{(game->rootPath / "Assets" / "Black.txt").string()};

    const auto width  = game->window.getSize().x;
    const auto height = game->window.getSize().y;

    if (!texture.loadFromFile(
            (game->rootPath / "Assets" / "Map_Bereinigt.png").string())) {
        std::cout << "Failed to Load map.png";
    }
    mMap.setTexture(texture);
    mMap.setPosition(width / 2, height / 2 * 0.9f);

    const auto mMapSize = mMap.getSize();

    auto xScale = width / mMapSize.x * 0.8f;
    auto yScale = height / mMapSize.y * 0.8f;

    mMap.setScale(xScale, yScale);

    for(const auto& questionPackage : game->questionPackageManager.mQuestionPackages)
    {
        if(questionPackage.isActive())
        {
            activeQuestionPackages.emplace_back(questionPackage);
        }
    }

}

void PlayingState::processInput(const sf::Event& event)
{
    gui.handleEvent(event);
}

void PlayingState::drawGui()
{
    gui.draw();
}

void PlayingState::update(sf::Time delta)
{
    sf::Time startingTimer = sf::seconds(0.0f);

    if(startingTimer < sf::seconds(5.0f))
    {
        startingTimer += delta;
    }
    else
    {
        //TODO Game Playing
    }

}

void PlayingState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mMap);
}

void PlayingState::load()
{
    //activeQuestionPackages
    /*for(const auto& questionPackage : qpm.mQuestionPackages)
    {
        if(questionPackage.isActive())
        {
            activeQuestionPackages.emplace_back(questionPackage);
        }
    }*/

}
