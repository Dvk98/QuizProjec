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

    void quit();

    void changeGameState(std::unique_ptr<GameState> state);

    const std::filesystem::path rootPath;
    QuestionPackageManager questionPackageManager;
    sf::RenderWindow window;

private:
    void processEvents();

    void update(sf::Time elapsedTime);

    void render();

    void updateStatistics(sf::Time elapsedTime);

    void load();

    static const sf::Time sTimePerFrame;

    std::unique_ptr<GameState> mCurrentState;
    sf::Font mFont;
    sf::Text mStatisticsText;
    sf::Time mStatisticsUpdateTime;
    std::size_t mStatisticsNumFrames;
};
