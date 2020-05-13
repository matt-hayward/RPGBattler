#include "SaveManager.h"

#include <filesystem>

bool SaveManager::CreateSave(Game* pge)
{
    std::ofstream saveFile;
    saveFile.open(pge->GetPlayer()->name + "_save.txt");

    if (saveFile.is_open()) {
        saveFile << pge->GetPlayer()->name << std::endl;
        saveFile.close();

        return true;
    }

    return false;
}

std::vector<std::string> SaveManager::ListSaves()
{
    std::vector<std::string> saves;
    std::string search = "_save.txt";

    std::string path = std::filesystem::current_path().string();

    for (auto& file : std::filesystem::directory_iterator(path)) {
        std::string fileName = file.path().filename().string();

        if (fileName.find(search) != std::string::npos) {
            size_t split = fileName.find(search);
            std::string saveName = fileName.substr(0, split);

            saves.push_back(saveName);
        }
    }

    return saves;
}

bool SaveManager::LoadSave(Game *pge, const std::string& name)
{
    std::array<std::string, 1> fields = {"name"};
    std::vector<std::string> saveFields;
    std::string fileName = name + "_save.txt";

    std::ifstream file(fileName);
    std::string line;

    while (std::getline(file, line))
    {
        saveFields.push_back(line);
    }

    file.close();

    int count = 0;
    for (auto& field : saveFields) {
        switch (count) {
            case 0:
                pge->player.name = field;
                break;
        }

        count++;

        if (count >= fields.size()) {
            break;
        }
    }

    return true;
}