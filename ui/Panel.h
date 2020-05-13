#ifndef RPGBATTLER_PANEL_H
#define RPGBATTLER_PANEL_H

#include "UiElement.h"
#include "../Game.h"

class Panel : public UiElement
{
public:
    Panel(const olc::vi2d& position, const olc::vi2d& size, std::string id, olc::Pixel borderColour, olc::Pixel backgroundColour);
    ~Panel();

public:
    void Draw() override;
    UiElement* AddElement(UiElement* elem) override;
    UiElement* GetChild(const std::string& id) override;

protected:
    olc::Pixel borderColour, backgroundColour;
    std::map<std::string, UiElement*> children;
};


#endif //RPGBATTLER_PANEL_H
