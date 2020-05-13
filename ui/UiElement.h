#ifndef RPGBATTLER_UIELEMENT_H
#define RPGBATTLER_UIELEMENT_H

#include "../pge/HasPge.h"
#include "../pge/olcPixelGameEngine.h"

class Game;

class UiElement : public HasPge
{
public:
    UiElement(const olc::vi2d& position, const olc::vi2d& size, std::string id, std::string text = "", std::string label="");
    ~UiElement() = default;

public:
    virtual void Draw() = 0;
    virtual UiElement* AddElement(UiElement* elem) {return this;};
    virtual UiElement* GetChild(const std::string& id) {return nullptr;};
    virtual bool isClicked() {return false;};
    virtual bool isHovered() {return false;};
    virtual void SetSize();
    virtual olc::vi2d GetPosition();

public:
    std::string id, text, label;
    olc::vi2d position, size;
    UiElement* parent = nullptr;
    float currentValue = 0.0f, maxValue = 0.0f;
    bool isDisplayed = true, isDisabled = false;
};


#endif //RPGBATTLER_UIELEMENT_H
