#ifndef RPGBATTLER_SAVEMANAGER_H
#define RPGBATTLER_SAVEMANAGER_H

#include "Game.h"

class SaveManager
{
public:
    static bool CreateSave(Game* pge);
    static std::vector<std::string> ListSaves();
    static bool LoadSave(Game* pge, const std::string& name);
};


#endif //RPGBATTLER_SAVEMANAGER_H
