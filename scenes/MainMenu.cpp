#include "MainMenu.h"
#include "../Game.h"
#include "../ui/Button.h"
#include "../SaveManager.h"

#include <utility>
#include <string>

MainMenu::MainMenu(SceneManager* manager, std::string title)
    : Scene(manager, std::move(title))
{ }

MainMenu::~MainMenu() = default;

void MainMenu::Draw()
{
    ui.Draw();
    pge->DrawStringDecal({180, 100}, "RPG Battler", olc::WHITE, {2.0f, 2.0f});
    pge->DrawStringDecal({179, 99}, "RPG Battler", olc::Colours::PALE_DARK_RED, {2.0f, 2.0f});
}

bool MainMenu::OnUserUpdate(float fElapsedTime)
{
    if (ui.GetElement("newGameButton")->isClicked()) {
        manager->nextScene = SceneManager::SCENE::NEW_PLAYER;
        return true;
    }

    if (ui.GetElement("loadGameButton")->isClicked()) {
        manager->nextScene = SceneManager::SCENE::LOAD_GAME;
    }

    if (ui.GetElement("exitButton")->isClicked()) {
        return false;
    }

    Draw();
    return true;
}

bool MainMenu::OnUserLoad()
{
    // TODO: Disable 'Load Game' button if there are no save files
    ui.AddElement(new Button({210, 150}, {10,10}, "newGameButton", "New Game", olc::Colours::COBALT_BLUE, olc::Colours::DARK_COBALT_BLUE))
      .AddElement(new Button({210, 200}, {10, 10}, "loadGameButton", "Load Game", olc::Colours::PURPLE, olc::Colours::DARK_PURPLE))
      .AddElement(new Button({210, 250}, {10, 10}, "exitButton", "Exit Game", olc::Colours::ORANGE, olc::Colours::VERY_DARK_ORANGE));
    isLoaded = true;
    SaveManager::LoadSave(pge, "SALADIN");

    return true;
}

bool MainMenu::OnUserUnload()
{
    isLoaded = false;
    return true;
}
