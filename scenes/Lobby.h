#ifndef RPGBATTLER_LOBBY_H
#define RPGBATTLER_LOBBY_H

#include "Scene.h"

class Lobby : public Scene
{
public:
    Lobby(SceneManager* manager, std::string title);
    ~Lobby();

public:
    void Draw() override;
    bool OnUserLoad() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserUnload() override;
};


#endif //RPGBATTLER_LOBBY_H
