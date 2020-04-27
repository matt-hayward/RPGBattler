#ifndef RPGBATTLER_GAME_H
#define RPGBATTLER_GAME_H

#include "olcPixelGameEngine.h"
#include "olcPGEX_AdditionalColours.h"

class Game : public olc::PixelGameEngine
{
public:
    Game();

public:
    bool OnUserCreate() override;
    bool OnUserUpdate(float fElapsedTime) override;
};

#endif //RPGBATTLER_GAME_H
