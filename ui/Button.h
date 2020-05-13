#ifndef RPGBATTLER_BUTTON_H
#define RPGBATTLER_BUTTON_H

#include "UiElement.h"
#include "../pge/olcPixelGameEngine.h"

class Button : public UiElement
{
public:
    Button(const olc::vi2d& position, const olc::vi2d& size, std::string id, std::string label, olc::Pixel colour, olc::Pixel hoverColour);
    ~Button() = default;

public:
    void Draw() override;
    void SetSize() override;
    bool isClicked() override;
    bool isHovered() override;

protected:
    olc::Pixel GetColour();

protected:
    olc::Pixel colour, hoverColour;
    olc::vi2d labelPosition;
};


#endif //RPGBATTLER_BUTTON_H
