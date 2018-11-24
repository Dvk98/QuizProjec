#include "Game.hpp"
#include "StringHelpers.hpp"
#include <iostream>
#include <SFML/Window/Event.hpp>
#include <string>
#include "Utils.hpp"

using namespace std::string_literals;


const sf::Time Game::TimePerFrame = sf::seconds(1.f/60.f);

Game::Game()
: mWindow(sf::VideoMode(2044, 1730), "World", sf::Style::Close)
, mFont()
, mStatisticsText()
, mStatisticsUpdateTime()
, mStatisticsNumFrames(0)
{
	mFont.loadFromFile("Assets/arial.ttf");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	load();
	sf::Sprite globMap(mMap);
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
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;

			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;

			case sf::Event::Closed:
				mWindow.close();
				break;
		}
	}
}

void Game::update(sf::Time elapsedTime)
{
	//mWorld.update(elapsedTime);
}

void Game::render()
{
	//std::cout << "Delta X " << (mWindow.getSize().x - mGameMap.getSize().x) / 2.0f << "|" << "Delta Y " << (mWindow.getSize().y - mGameMap.getSize().y) / 2 << std::endl;
	mWindow.clear();
	mWindow.draw(mGameMap);

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

void Game::handlePlayerInput(sf::Keyboard::Key, bool)
{
}

void Game::load()
{
	if (!mMap.loadFromFile("Assets/Map_Bereinigt.png"))
	{
		std::cout << ("Failed to Load map.png");
	}
	mGameMap.setTexture(mMap);
	mGameMap.setPosition(mWindow.getSize().x / 2, mWindow.getSize().y / 2);
	//mGameMap.setScale(0.25f, 0.25f);
	std::cout << mWindow.getSize().x / 2 << " " << mWindow.getSize().y / 2;
}
