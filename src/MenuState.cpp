#include "MenuState.hpp"

MenuState::MenuState(Game* game) : GameState(game), gui(game->getWindow())
{
    tgui::Theme theme{"Assets/Black.txt"};

    auto wide   = game->getWindow().getSize().x;
    auto height = game->getWindow().getSize().y;

    auto layout = tgui::VerticalLayout::create();
    layout->setSize("25%", "75%");
    layout->setPosition(0.125f * wide, 0.125f * height);
    gui.add(layout);

    auto bMultiplayer = tgui::Button::create();
    bMultiplayer->setRenderer(theme.getRenderer("Button"));
    bMultiplayer->setText("Multiplayer");
    bMultiplayer->connect(
        "pressed", [=]() { game->changeGameState(GameState::EState::Lobby); });
    layout->add(bMultiplayer);

    layout->addSpace(0.6f);
    auto bOptions = tgui::Button::create();
    bOptions->setRenderer(theme.getRenderer("Button"));
    bOptions->setText("Options");
    // button->connect("pressed", [=]() { child->hide(); });
    layout->add(bOptions);
    layout->addSpace(0.6f);

    auto bExit = tgui::Button::create();
    bExit->setRenderer(theme.getRenderer("Button"));
    bExit->setText("Exit");
    // button->connect("pressed", [=]() { child->hide(); });
    layout->add(bExit);
}

void MenuState::processInput(sf::Event event)
{
    gui.handleEvent(event);
}

void MenuState::drawGui()
{
    gui.draw();
}

void MenuState::update(sf::Time delta) {}

void MenuState::draw(sf::RenderTarget& target, sf::RenderStates states) const {}
