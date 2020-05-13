#include "Lobby.h"
#include "../Game.h"

#include <utility>

Lobby::Lobby(SceneManager *manager, std::string title)
    : Scene(manager, std::move(title))
{ }

void Lobby::Draw()
{
    ui.Draw();
    pge->DrawStringDecal({10, 10}, pge->player.name + " Lobby", olc::Colours::OFF_WHITE);
}

bool Lobby::OnUserLoad()
{
    return true;
}

bool Lobby::OnUserUpdate(float fElapsedTime)
{
    Draw();
    return true;
}

bool Lobby::OnUserUnload()
{
    return true;
}

Lobby::~Lobby() = default;
