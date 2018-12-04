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
    , mWindow(sf::VideoMode(800, 600), "World", sf::Style::Close)
    , mFont()
    , mStatisticsText()
    , mStatisticsUpdateTime()
    , mStatisticsNumFrames(0)
{
    mFont.loadFromFile((rootPath / "Assets" / "arial.ttf").string());
    mStatisticsText.setFont(mFont);
    mStatisticsText.setPosition(5.f, 5.f);
    mStatisticsText.setCharacterSize(10);

    mQuestionPackageManager.load(rootPath);

    mGameStates[static_cast<std::size_t>(GameState::EState::Menu)] =
        new MenuState(this);
    mGameStates[static_cast<std::size_t>(GameState::EState::Lobby)] =
        new LobbyState(this);
    mGameStates[static_cast<std::size_t>(GameState::EState::Playing)] =
        new PlayingState(this);

    changeGameState(GameState::EState::Menu);
}

Game::~Game()
{
    for (GameState* gameState : mGameStates) {
        delete gameState;
    }
}

void Game::run()
{
    sf::Clock clock;
    sf::Time  timeSinceLastUpdate = sf::Time::Zero;
    load();
    while (mWindow.isOpen()) {
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

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event)) {
        mCurrentState->processInput(event);
    }
}

void Game::update(sf::Time elapsedTime)
{
    mCurrentState->update(elapsedTime);
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(*mCurrentState);
    mCurrentState->drawGui();
    mWindow.setView(mWindow.getDefaultView());
    mWindow.draw(mStatisticsText);
    mWindow.display();
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
            toString(sf::Mouse::getPosition(mWindow)));

        mStatisticsUpdateTime -= sf::seconds(0.1f);
        mStatisticsNumFrames = 0;
    }
}

void Game::load() {}

void Game::changeGameState(GameState::EState gameState)
{
    mCurrentState = mGameStates[static_cast<std::size_t>(gameState)];
}

sf::RenderWindow& Game::getWindow()
{
    return mWindow;
}

QuestionPackageManager Game::getQPM()
{
    return mQuestionPackageManager;
}