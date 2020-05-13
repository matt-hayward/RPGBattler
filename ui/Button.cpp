#include "Button.h"
#include "../Game.h"

#include <utility>

Button::Button(const olc::vi2d& position, const olc::vi2d& size, std::string id, std::string label, olc::Pixel colour, olc::Pixel hoverColour)
    : UiElement(position, size, std::move(id), "", std::move(label)), colour{colour}, hoverColour{hoverColour}
{}

void Button::Draw()
{
    SetSize();

    olc::vi2d pos = position, labelPos = labelPosition;

    if (parent != nullptr) {
        pos += parent->GetPosition();
    }

    labelPos = {pos.x + 8, pos.y + 8};

    pge->FillRect(pos, size, GetColour());
    pge->DrawString(labelPos, label, olc::WHITE, 1);
}

bool Button::isHovered()
{
    olc::vi2d mousePosition = {pge->GetMouseX(), pge->GetMouseY()};
    olc::vi2d pos = position;

    if (parent != nullptr) {
        pos += parent->GetPosition();
    }

    return mousePosition.x >= pos.x
        && mousePosition.x <= pos.x + size.x
        && mousePosition.y >= pos.y
        && mousePosition.y <= pos.y + size.y
        && !isDisabled;
}

bool Button::isClicked()
{
    return isHovered() && pge->GetMouse(0).bPressed;
}

olc::Pixel Button::GetColour()
{
    if (isDisabled) {
        return olc::VERY_DARK_GREY;
    }

    return isHovered() ? hoverColour : colour;
}

void Button::SetSize()
{
    int labelLength = label.size();
    size = {((labelLength * 8) + 16), 24};
}