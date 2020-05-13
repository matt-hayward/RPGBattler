#ifndef RPGBATTLER_SCENE_H
#define RPGBATTLER_SCENE_H

#include <string>
#include "../pge/HasPge.h"
#include "../ui/UiManager.h"

class SceneManager;

class Scene : public HasPge
{
public:
    Scene(SceneManager*, std::string);
    ~Scene();

public:
    virtual void Draw();
    virtual bool OnUserLoad();
    virtual bool OnUserUpdate(float);
    virtual bool OnUserUnload();

public:
    std::string title;
    SceneManager* manager;
    UiManager ui;
    bool isLoaded = false;
};


#endif //RPGBATTLER_SCENE_H
