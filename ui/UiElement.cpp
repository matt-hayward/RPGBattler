#include "UiElement.h"
#include "../Game.h"

#include <utility>

UiElement::UiElement(const olc::vi2d& position, const olc::vi2d& size, std::string id, std::string text, std::string label)
    : position{position}, size{size}, id{std::move(id)}, text{std::move(text)}, label{std::move(label)}
{}

olc::vi2d UiElement::GetPosition()
{
    return parent == nullptr ? position : position + parent->position;
}

void UiElement::SetSize()
{

}
