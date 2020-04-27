#include "SceneManager.h"

SceneManager::SceneManager()
{
    scenes[SCENE::LOBBY] = new Scene(this, "Lobby Scene");
    scenes[SCENE::MAIN_MENU] = new Scene(this, "Main Menu Scene");
    scenes[SCENE::BATTLE] = new Scene(this, "Battle Scene");
    scenes[SCENE::SHOP] = new Scene(this, "Shop Scene");
}

SceneManager::~SceneManager() = default;

Scene* SceneManager::GetCurrentScene()
{
    // if next scene is set, and is different to the current scene, change the current scene
    if (nextScene != currentScene) {
        currentScene = nextScene;
    }

    return scenes[currentScene];
}
