#ifndef RPGBATTLER_NEWPLAYER_H
#define RPGBATTLER_NEWPLAYER_H

#include "Scene.h"

class NewPlayer : public Scene
{
public:
    NewPlayer(SceneManager* manager, std::string title);
    ~NewPlayer();

public:
    void Draw() override;
    bool OnUserLoad() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserUnload() override;

protected:
    void CreateKeyboard();

public:
    std::string playerName = "";
    std::string characters = "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ";
};


#endif //RPGBATTLER_NEWPLAYER_H
