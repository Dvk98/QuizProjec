#include "MenuState.hpp"

#include "LobbyState.hpp"
#include "SFML/Network.hpp"

MenuState::MenuState(Game* game) : GameState(game), gui(game->window)
{
    tgui::Theme theme{(game->rootPath / "Assets" / "Black.txt").string()};

    const auto width{game->window.getSize().x};
    const auto height{game->window.getSize().y};

    auto layout{tgui::VerticalLayout::create()};
    layout->setSize("25%", "75%");
    layout->setPosition(0.125f * width, 0.125f * height);
    gui.add(layout);

    auto bMultiplayer{tgui::Button::create()};
    bMultiplayer->setRenderer(theme.getRenderer("Button"));
    bMultiplayer->setText("Multiplayer");
    bMultiplayer->connect("pressed", [=]() {
        game->changeGameState(std::make_unique<LobbyState>(pGame));
    });
    layout->add(bMultiplayer);

    layout->addSpace(0.3f);
    auto bOptions{tgui::Button::create()};
    bOptions->setRenderer(theme.getRenderer("Button"));
    bOptions->setText("Options");
    // button->connect("pressed", [=]() { child->hide(); });
    layout->add(bOptions);
    layout->addSpace(0.3f);

    auto bExit{tgui::Button::create()};
    bExit->setRenderer(theme.getRenderer("Button"));
    bExit->setText("Exit");
    bExit->connect("pressed", [=]() { game->quit(); });
    layout->add(bExit);
}

void MenuState::drawGui()
{
    gui.draw();
}

void MenuState::processInput(const sf::Event& event)
{
    gui.handleEvent(event);
}

void MenuState::update(sf::Time delta) {}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const {}

void MenuState::load() {}
