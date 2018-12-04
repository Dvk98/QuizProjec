#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <array>
#include <filesystem>
#include "GameState.hpp"
#include "QuestionPackageManager.hpp"

class Game : private sf::NonCopyable
{
public:
    explicit Game(const std::filesystem::path& rootPath);


    void run();

    void changeGameState(GameState::EState gameState);

    const std::filesystem::path rootPath;
    QuestionPackageManager      questionPackageManager;
    sf::RenderWindow            window;

private:
    void processEvents();

    void update(sf::Time elapsedTime);

    void render();

    void updateStatistics(sf::Time elapsedTime);

    void load();

    static const sf::Time sTimePerFrame;

    GameState* mCurrentState{nullptr};

    std::array<std::unique_ptr<GameState>, static_cast<std::size_t>(GameState::EState::Count)>
        mGameStates;

    sf::Font    mFont;
    sf::Text    mStatisticsText;
    sf::Time    mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};
