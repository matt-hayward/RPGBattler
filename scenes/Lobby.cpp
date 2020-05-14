#include "Lobby.h"
#include "../Game.h"
#include "../ui/Button.h"
#include "../ui/Panel.h"

#include <utility>

Lobby::Lobby(SceneManager *manager, std::string title)
    : Scene(manager, std::move(title))
{ }

void Lobby::Draw()
{
    ui.Draw();
    pge->DrawStringDecal({10, 10}, "Lobby for " + pge->player.name, olc::Colours::OFF_WHITE);
}

bool Lobby::OnUserLoad()
{
    ui.AddElement(new Button({10, pge->ScreenHeight() - 140}, {0,0}, "goToBattleButton", "Go To Battle", olc::Colours::COBALT_BLUE, olc::Colours::DARK_COBALT_BLUE))
      .AddElement(new Button({130, pge->ScreenHeight() - 140}, {0,0}, "goToShopButton", "Go To Shop", olc::Colours::COBALT_BLUE, olc::Colours::DARK_COBALT_BLUE))
      .AddElement(new Panel({10, pge->ScreenHeight() - 110}, {pge->ScreenWidth() - 20, 100}, "dialogPanel", olc::WHITE, olc::Colours::VERY_DARK_CORNFLOWER_BLUE));

    isLoaded = true;
    return true;
}

bool Lobby::OnUserUpdate(float fElapsedTime)
{
    Draw();

    if (ui.GetElement("goToBattleButton")->isClicked()) {
        manager->nextScene = SceneManager::SCENE::BATTLE;
    }

    if (ui.GetElement("goToShopButton")->isClicked()) {
        manager->nextScene = SceneManager::SCENE::SHOP;
    }

    return true;
}

bool Lobby::OnUserUnload()
{
    return true;
}

Lobby::~Lobby() = default;
