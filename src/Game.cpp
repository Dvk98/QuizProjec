#include "Game.hpp"
#include <SFML/Window/Event.hpp>
#include <iostream>
#include <string>
#include "LobbyState.hpp"
#include "MenuState.hpp"
#include "PlayingState.hpp"
#include "StringHelpers.hpp"
#include "TGUI/TGUI.hpp"
#include "Utils.hpp"

using namespace std::string_literals;

const sf::Time Game::sTimePerFrame = sf::seconds(1.f / 60.f);

Game::Game(const std::filesystem::path& rootPath)
    : rootPath(rootPath)
    , questionPackageManager(this)
    , window(sf::VideoMode(800, 600), "World", sf::Style::Close)
    , mFont()
    , mStatisticsText()
    , mStatisticsUpdateTime()
    , mStatisticsNumFrames(0)
{
    mFont.loadFromFile((rootPath / "Assets" / "arial.ttf").string());
    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10);

    questionPackageManager.load();

    mGameStates[static_cast<std::size_t>(GameState::EState::MENU)] =
        std::make_unique<MenuState>(this);
    mGameStates[static_cast<std::size_t>(GameState::EState::LOBBY)] =
        std::make_unique<LobbyState>(this);
    mGameStates[static_cast<std::size_t>(GameState::EState::PLAYING)] =
        std::make_unique<PlayingState>(this);

    changeGameState(GameState::EState::MENU);
}

void Game::run()
{
    sf::Clock clock;
    sf::Time  timeSinceLastUpdate = sf::Time::Zero;
    load();

    while (window.isOpen()) {
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;

        while (timeSinceLastUpdate > sTimePerFrame) {
            timeSinceLastUpdate -= sTimePerFrame;
            processEvents();
            update(sTimePerFrame);
        }

        updateStatistics(elapsedTime);
        render();
    }
}

void Game::quit()
{
    window.close();
}

void Game::processEvents()
{
    for (sf::Event event; window.pollEvent(event);) {
        mCurrentState->processInput(event);
    }
}

void Game::update(sf::Time elapsedTime)
{
    mCurrentState->update(elapsedTime);
}

void Game::render()
{
    window.clear();
    window.draw(*mCurrentState);
    mCurrentState->drawGui();
    window.setView(window.getDefaultView());
    window.draw(mStatisticsText);
    window.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
    mStatisticsUpdateTime += elapsedTime;
    mStatisticsNumFrames += 10;

    if (mStatisticsUpdateTime >= sf::seconds(0.1f)) {
        mStatisticsText.setString(
            "Frames / Second = "s + std::to_string(mStatisticsNumFrames) +
            "\n" + "Time / Update = "s +
            std::to_string(
                mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) +
            "us\n" + "Koordinaten = "s +
            toString(sf::Mouse::getPosition(window)));

        mStatisticsUpdateTime -= sf::seconds(0.1f);
        mStatisticsNumFrames = 0;
    }
}

void Game::load() {}

void Game::changeGameState(GameState::EState gameState)
{
    mCurrentState = mGameStates[static_cast<std::size_t>(gameState)].get();
    mCurrentState->load();
}
