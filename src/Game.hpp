#pragma once
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include <array>
#include "QuestionPackageManager.hpp"

class Game : private sf::NonCopyable
{
	public:
								Game();
								~Game();

		void					run();

		sf::RenderWindow& getWindow();
		void changeGameState(GameState::State gameState);

		QuestionPackageManager getQPM();

	private:
		void					processEvents();
		void					update(sf::Time elapsedTime);
		void					render();

		void					updateStatistics(sf::Time elapsedTime);	
		void					load();

	private:
		static const sf::Time	TimePerFrame;

		sf::RenderWindow		mWindow;
		QuestionPackageManager mQuestionPackageManager;

		GameState* m_currentState{nullptr};

		std::array<GameState*, static_cast<std::size_t>(GameState::State::Count)> mGameStates;

	  	sf::Font				mFont;
		sf::Text				mStatisticsText;
		sf::Time				mStatisticsUpdateTime;
		std::size_t				mStatisticsNumFrames;
};

