#ifndef RPGBATTLER_LOADGAME_H
#define RPGBATTLER_LOADGAME_H

#include "Scene.h"

class LoadGame : public Scene
{
public:
    LoadGame(SceneManager* manager, std::string title);
    ~LoadGame();

public:
    void Draw() override;
    bool OnUserLoad() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserUnload() override;

protected:
    std::vector<std::string> saves;
};


#endif //RPGBATTLER_LOADGAME_H
