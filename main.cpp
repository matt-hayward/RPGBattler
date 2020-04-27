#include "Game.h"

int main()
{
    Game game;

    if (game.Construct(512, 364, 2, 2)) game.Start();
}