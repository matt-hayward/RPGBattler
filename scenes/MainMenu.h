#ifndef RPGBATTLER_MAINMENU_H
#define RPGBATTLER_MAINMENU_H

#include "Scene.h"

class MainMenu : public Scene
{
public:
    MainMenu(SceneManager *unnamed, std::string unnamed1);
    ~MainMenu();

public:
    void Draw() override;
    bool OnUserLoad() override;
    bool OnUserUpdate(float fElapsedTime) override;
    bool OnUserUnload() override;
};


#endif //RPGBATTLER_MAINMENU_H
