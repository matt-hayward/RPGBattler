#include "NewPlayer.h"
#include "../Game.h"
#include "../ui/Panel.h"
#include "../ui/Button.h"
#include "../SaveManager.h"
#include <iostream>

NewPlayer::NewPlayer(SceneManager* manager, std::string title)
    : Scene(manager, std::move(title))
{ }

NewPlayer::~NewPlayer() = default;

void NewPlayer::Draw()
{
    ui.Draw();
    pge->DrawStringDecal({10, 10}, "Enter your character name...", olc::Colours::OFF_WHITE);
    pge->DrawStringDecal({10, 40}, playerName, olc::Colours::OFF_WHITE, {1.5f, 1.5f});
}

bool NewPlayer::OnUserUpdate(float fElapsedTime)
{
    ui.GetElement("continueButton")->isDisabled = playerName.empty();

    Draw();

    UiElement* panel = ui.GetElement("keyboardPanel");

    for (auto& c : characters) {
        if (panel->GetChild(std::string(1, c) + "Button")->isClicked()) {
            playerName.append(std::string(1, c));
            break;
        }
    }

    if (panel->GetChild("backspaceButton")->isClicked()) {
        playerName = playerName.substr(0, playerName.size()  - 1);
    }

    if (ui.GetElement("continueButton")->isClicked()) {
        pge->player.name = playerName;

        if (SaveManager::CreateSave(pge)) {
            manager->nextScene = SceneManager::SCENE::LOBBY;
        }
    }

    if (ui.GetElement("cancelButton")->isClicked()) {
        manager->nextScene = SceneManager::SCENE::MAIN_MENU;
    }

    return true;
}

bool NewPlayer::OnUserLoad()
{
    CreateKeyboard();

    ui.AddElement(new Button({420, 300}, {0,0}, "continueButton", "Continue", olc::BLUE, olc::DARK_BLUE));
    ui.AddElement(new Button({10, 300}, {0,0}, "cancelButton", "Cancel", olc::BLUE, olc::DARK_BLUE));

    return true;
}

bool NewPlayer::OnUserUnload()
{
    playerName = "";
    return true;
}

void NewPlayer::CreateKeyboard()
{
    ui.AddElement(new Panel({10, 75}, {pge->ScreenWidth() - 20, 200}, "keyboardPanel", olc::GREY, olc::WHITE));

    UiElement* panel = ui.GetElement("keyboardPanel");

    int count = 0, x = 10, y = 10, inc = 40;

    for (auto& c : characters) {
        panel->AddElement(new Button({x, y}, {0,0}, std::string(1, c) + "Button", std::string(1, c), olc::BLUE, olc::DARK_BLUE));
        count++;
        x += inc;

        if (count % 10 == 0) {
            y += inc;
            x = 10;
        }
    }

    x += (inc * 2);

    panel->AddElement(new Button({x, y}, {0,0}, "backspaceButton", "BKSP", olc::BLUE, olc::DARK_BLUE));
}
