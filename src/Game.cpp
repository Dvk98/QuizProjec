#include "Game.hpp"
#include "StringHelpers.hpp"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <string>
#include "Utils.hpp"
#include "TGUI/TGUI.hpp"
#include "MenuState.hpp"
#include "LobbyState.hpp"
#include "PlayingState.hpp"

using namespace std::string_literals;


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode(800, 600), "World", sf::Style::Close)
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{

	mFont.loadFromFile("Assets/arial.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);

	mQuestionPackageManager.load();

	mGameStates[static_cast<std::size_t>(GameState::State::Menu)] = new MenuState(this);
	mGameStates[static_cast<std::size_t>(GameState::State::Lobby)] = new LobbyState(this);
	mGameStates[static_cast<std::size_t>(GameState::State::Playing)] = new PlayingState(this);

	changeGameState(GameState::State::Menu);
}

Game::~Game()
{
	for (GameState* gameState : mGameStates)
	{
		delete gameState;
	}
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	load();
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			update(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		m_currentState->processInput(event);
	}
}

void Game::update(sf::Time elapsedTime)
{
	m_currentState->update(elapsedTime);
}

void Game::render()
{
	mWindow.clear();
	mWindow.draw(*m_currentState);
	m_currentState->drawGui();
	mWindow.setView(mWindow.getDefaultView());
	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 10;

	if (mStatisticsUpdateTime >= sf::seconds(0.1f))
	{
		mStatisticsText.setString(
			"Frames / Second = "s + std::to_string(mStatisticsNumFrames) + "\n" +
			"Time / Update = "s + std::to_string(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us\n" + 
			"Koordinaten = "s + toString(sf::Mouse::getPosition(mWindow)));
							 
		mStatisticsUpdateTime -= sf::seconds(0.1f);
		mStatisticsNumFrames = 0;
	}
}

void Game::load()
{

}

void Game::changeGameState(GameState::State gameState)
{
	m_currentState = mGameStates[static_cast<std::size_t>(gameState)];
}

sf::RenderWindow& Game::getWindow()
{
	return mWindow;
}

QuestionPackageManager Game::getQPM()
{
	return mQuestionPackageManager;
}