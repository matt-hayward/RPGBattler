#include "Game.h"

Game::Game()
{
    sAppName = "RPG Battler";
}

bool Game::OnUserCreate()
{
    HasPge::pge = this;
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    Clear(olc::Pixel(53, 64, 72));

    return sceneManager.GetCurrentScene()->OnUserUpdate(fElapsedTime);
}
