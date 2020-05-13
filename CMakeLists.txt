cmake_minimum_required(VERSION 3.16)
project(RPGBattler)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPGBattler
    main.cpp
    pge/olcPixelGameEngine.cpp pge/olcPixelGameEngine.h pge/olcPGEX_Graphics2D.h pge/olcPGEX_AnimatedSprite.h pge/olcPGEX_AdditionalColours.h
    Game.cpp Game.h
    pge/HasPge.cpp pge/HasPge.h
    scenes/SceneManager.cpp scenes/SceneManager.h
    scenes/Scene.cpp scenes/Scene.h
    scenes/MainMenu.cpp scenes/MainMenu.h
    ui/UiElement.cpp ui/UiElement.h
    ui/UiManager.cpp ui/UiManager.h
    ui/Button.cpp ui/Button.h
    scenes/NewPlayer.cpp scenes/NewPlayer.h
    ui/Panel.cpp ui/Panel.h
    SaveManager.cpp SaveManager.h
    Player.cpp Player.h
    scenes/Lobby.cpp scenes/Lobby.h
    scenes/LoadGame.cpp scenes/LoadGame.h)
