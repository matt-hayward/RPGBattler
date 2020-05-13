#include "Panel.h"
#include "../Game.h"
#include <utility>

Panel::Panel(const olc::vi2d& position, const olc::vi2d& size, std::string id, olc::Pixel borderColour, olc::Pixel backgroundColour)
    : UiElement(position, size, std::move(id)), borderColour{borderColour}, backgroundColour{backgroundColour}
{}

void Panel::Draw()
{
    olc::vi2d pos = position;

    if (parent != nullptr) {
        pos += parent->GetPosition();
    }

    // TODO: Consider drawing to off-screen sprite to reduce per-pixel filling

    pge->DrawRect(pos, size, borderColour);
    pge->FillRect({ pos.x + 1, pos.y + 1 }, { size.x - 1, size.y - 1 }, backgroundColour);

    for (auto child : children) {
        child.second->Draw();
    }
}

UiElement *Panel::AddElement(UiElement *elem)
{
    elem->parent = this;
    children[elem->id] = elem;

    return this;
}

UiElement *Panel::GetChild(const std::string& id)
{
    return children[id];
}

Panel::~Panel() = default;
