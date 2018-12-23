#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>

class Game;

class GameState : public sf::Drawable
{
public:
#if 0
    enum class EState
    {
        TITLE,
        MENU,
        OPTIONS,
        LOBBY,
        PLAYING,
        RESULT,
        COUNT
    };
#endif

    explicit GameState(Game* game);

    virtual void processInput(const sf::Event& event) = 0;

    virtual void update(sf::Time delta) = 0;

    virtual void drawGui() = 0;

    virtual void load() = 0;

    Game* const pGame;
};

template<typename T>
void centerOrigin(T& drawable)
{
    const auto bounds{drawable.getLocalBounds()};
    drawable.setOrigin(bounds.width / 2.0f, bounds.height / 2.0f);
}
