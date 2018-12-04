#include "LobbyState.hpp"
#include <iostream>

LobbyState::LobbyState(Game* game) : GameState(game), gui(game->window)
{
    tgui::Theme theme{(game->rootPath / "Assets" / "Black.txt").string()};

    auto wide   = game->window.getSize().x;
    auto height = game->window.getSize().y;

    auto panel = tgui::ScrollablePanel::create();
    panel->setRenderer((theme.getRenderer("Panel")));
    panel->setSize("25%", "60%");
    panel->setPosition("62.5%", "12.5%");
    gui.add(panel, "PackageSelectPanel");

    int position = 0;
    for (auto qp : game->questionPackageManager.getQPs()) {
        auto checkbox = tgui::CheckBox::create();
        checkbox->setRenderer(theme.getRenderer("Checkbox"));
        checkbox->setText(qp.getName());
        checkbox->setSize("20%", "10%");
        checkbox->setPosition(0, std::to_string(position) + "%");
        panel->add(checkbox, qp.getName());
        position += 12;
    }

    auto bottomLayout = tgui::HorizontalLayout::create();
    bottomLayout->setPosition("5%", "80%");
    bottomLayout->setSize("90%", "10%");
    gui.add(bottomLayout);

    auto bStart = tgui::Button::create();
    bStart->setRenderer(theme.getRenderer("Button"));
    bStart->setText("Start");
    bStart->connect("pressed", [=]() {
        game->changeGameState(GameState::EState::Playing);
    });
    bottomLayout->add(bStart, "Start");

    auto bInvite = tgui::Button::create();
    bInvite->setRenderer(theme.getRenderer("Button"));
    bInvite->setText("Invite");
    bInvite->connect("pressed", [=]() {});
    bottomLayout->add(bInvite, "Invite");

    auto bBack = tgui::Button::create();
    bBack->setRenderer(theme.getRenderer("Button"));
    bBack->setText("Back");
    bBack->connect(
        "pressed", [=]() { game->changeGameState(GameState::EState::Menu); });
    bottomLayout->add(bBack, "Back");
}

void LobbyState::drawGui()
{
    gui.draw();
}

void LobbyState::processInput(sf::Event event)
{
    gui.handleEvent(event);
}

void LobbyState::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
}

void LobbyState::update(sf::Time delta)
{
    auto test = gui.getWidgetNames();
    for (auto i : test) {
        auto j = i.toAnsiString();
        std::cout << i.toAnsiString() << std::endl;
    }
}