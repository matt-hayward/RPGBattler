#ifndef RPGBATTLER_GAME_H
#define RPGBATTLER_GAME_H

#include "pge/olcPixelGameEngine.h"
#include "pge/olcPGEX_AdditionalColours.h"
#include "scenes/SceneManager.h"
#include "Player.h"

class Game : public olc::PixelGameEngine
{
public:
    Game();

public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
    Player* GetPlayer();

public:
    Player player;

protected:
    SceneManager sceneManager;
};

#endif //RPGBATTLER_GAME_H
