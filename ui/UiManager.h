#ifndef RPGBATTLER_UIMANAGER_H
#define RPGBATTLER_UIMANAGER_H

#include "../pge/HasPge.h"
#include "UiElement.h"

class UiManager : public HasPge
{
public:
    UiManager() = default;
    ~UiManager() = default;

public:
    UiManager& AddElement(UiElement* element);
    UiElement* GetElement(const std::string& id);
    void Draw();
    void Init();
    void Update();

protected:
    std::map<std::string, UiElement*> elements;
};


#endif //RPGBATTLER_UIMANAGER_H
