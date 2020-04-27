#include "Scene.h"
#include "Game.h"
#include "SceneManager.h"

#include <utility>

Scene::Scene(SceneManager* manager, std::string title)
    : manager{manager}, title{std::move(title)}
{}

Scene::~Scene() = default;

void Scene::Draw()
{

}

bool Scene::OnUserUpdate(float fElapsedTime)
{
    pge->DrawString({10, 10}, title);

    if (pge->GetKey(olc::L).bPressed) {
        manager->nextScene = SceneManager::SCENE::LOBBY;
    }

    if (pge->GetKey(olc::S).bPressed) {
        manager->nextScene = SceneManager::SCENE::SHOP;
    }

    if (pge->GetKey(olc::B).bPressed) {
        manager->nextScene = SceneManager::SCENE::BATTLE;
    }

    if (pge->GetKey(olc::M).bPressed) {
        manager->nextScene = SceneManager::SCENE::MAIN_MENU;
    }

    return true;
}