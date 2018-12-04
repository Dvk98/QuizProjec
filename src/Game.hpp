#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <array>
#include "GameState.hpp"
#include "QuestionPackageManager.hpp"

class Game : private sf::NonCopyable
{
public:
    Game();

    ~Game();

    void run();

    sf::RenderWindow& getWindow();

    void changeGameState(GameState::EState gameState);

    QuestionPackageManager getQPM();

private:
    void processEvents();

    void update(sf::Time elapsedTime);

    void render();

    void updateStatistics(sf::Time elapsedTime);

    void load();

    static const sf::Time sTimePerFrame;

    sf::RenderWindow mWindow;
    QuestionPackageManager mQuestionPackageManager;
    GameState* mCurrentState{nullptr};

    std::array<GameState*, static_cast<std::size_t>(GameState::EState::Count)>
        mGameStates;

    sf::Font    mFont;
    sf::Text    mStatisticsText;
    sf::Time    mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};
