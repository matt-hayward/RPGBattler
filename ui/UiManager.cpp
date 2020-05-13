#include "UiManager.h"

UiManager &UiManager::AddElement(UiElement* element)
{
    elements[element->id] = element;

    return *this;
}

UiElement* UiManager::GetElement(const std::string& id)
{
    return elements[id];
}

void UiManager::Draw()
{
    for (auto e : elements) {
        e.second->Draw();
    }
}

void UiManager::Init()
{
    // TODO: Maybe get rid of this, as the manager is now intended to be more generic
}

void UiManager::Update()
{
    // TODO: Maybe get rid of this, as the manager is now intended to be more generic
}