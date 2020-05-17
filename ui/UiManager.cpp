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