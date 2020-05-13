#ifndef RPGBATTLER_SCENEMANAGER_H
#define RPGBATTLER_SCENEMANAGER_H

#include <map>
#include "../pge/HasPge.h"
#include "Scene.h"

class SceneManager : public HasPge
{
public:
    SceneManager();
    ~SceneManager();

public:
    Scene* GetCurrentScene();

public:
    enum class SCENE {
        MAIN_MENU, NEW_PLAYER, LOAD_GAME, LOBBY, SHOP, BATTLE
    };
    SCENE nextScene = SCENE::MAIN_MENU;

protected:
    std::map<SCENE, Scene*> scenes;
    SCENE currentScene = SCENE::MAIN_MENU;
};


#endif //RPGBATTLER_SCENEMANAGER_H
