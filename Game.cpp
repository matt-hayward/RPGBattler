#include "Game.h"

Game::Game()
{
    sAppName = "RPG Battler";
}

bool Game::OnUserCreate()
{
    return true;
}

bool Game::OnUserUpdate(float fElapsedTime)
{
    Clear(olc::Colours::PALE_DARK_GREEN);

    return true;
}
