#include "LoadGame.h"
#include "../SaveManager.h"
#include "../ui/Button.h"

#include <utility>

LoadGame::LoadGame(SceneManager* manager, std::string title)
    : Scene(manager, std::move(title))
{ }

LoadGame::~LoadGame() = default;

void LoadGame::Draw()
{
    ui.Draw();

    pge->DrawStringDecal({10, 10}, "Select a save file to load...", olc::Colours::OFF_WHITE, {1.5f, 1.5f});
}

bool LoadGame::OnUserLoad()
{
    saves = SaveManager::ListSaves();

    int count = 1, x = 10, y = 50, inc = 40;

    for (auto& name : saves) {
        ui.AddElement(new Button({x, y}, {0,0}, name + "Button", name, olc::BLUE, olc::DARK_BLUE));
        y += inc;

        count++;
    }

    ui.AddElement(new Button({x, y + inc}, {0,0}, "cancelButton", "Cancel", olc::BLUE, olc::DARK_BLUE));

    return true;
}

bool LoadGame::OnUserUpdate(float fElapsedTime)
{
    Draw();

    for (auto& save : saves) {
        if (ui.GetElement(save + "Button")->isClicked()) {
            SaveManager::LoadSave(pge, save);
            manager->nextScene = SceneManager::SCENE::LOBBY;
        }
    }

    if (ui.GetElement("cancelButton")->isClicked()) {
        manager->nextScene = SceneManager::SCENE::MAIN_MENU;
    }

    return true;
}

bool LoadGame::OnUserUnload()
{
    return true;
}
