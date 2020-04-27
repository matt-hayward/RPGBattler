#ifndef RPGBATTLER_SCENE_H
#define RPGBATTLER_SCENE_H

#include <string>
#include "HasPge.h"

class SceneManager;

class Scene : public HasPge
{
public:
    Scene(SceneManager*, std::string);
    ~Scene();

public:
    void Draw();
    bool OnUserUpdate(float);

public:
    std::string title;
    SceneManager* manager;
};


#endif //RPGBATTLER_SCENE_H
