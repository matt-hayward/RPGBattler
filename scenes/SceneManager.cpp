#include "SceneManager.h"
#include "MainMenu.h"
#include "NewPlayer.h"
#include "Lobby.h"
#include "LoadGame.h"

SceneManager::SceneManager()
{
    scenes[SCENE::LOBBY] = new Lobby(this, "Lobby Scene");
    scenes[SCENE::MAIN_MENU] = new MainMenu(this, "Main Menu Scene");
    scenes[SCENE::NEW_PLAYER] = new NewPlayer(this, "New Player Scene");
    scenes[SCENE::LOAD_GAME] = new LoadGame(this, "Load Game Scene");
    scenes[SCENE::BATTLE] = new Scene(this, "Battle Scene");
    scenes[SCENE::SHOP] = new Scene(this, "Shop Scene");
}

SceneManager::~SceneManager() = default;

Scene* SceneManager::GetCurrentScene()
{
    // if next scene is set, and is different to the current scene, change the current scene
    if (nextScene != currentScene) {
        scenes[currentScene]->OnUserUnload();
        currentScene = nextScene;
    }

    if (!scenes[currentScene]->isLoaded) {
        scenes[currentScene]->OnUserLoad();
    }

    return scenes[currentScene];
}
