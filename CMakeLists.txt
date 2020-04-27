cmake_minimum_required(VERSION 3.16)
project(RPGBattler)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPGBattler
    main.cpp
    olcPixelGameEngine.cpp olcPixelGameEngine.h olcPGEX_Graphics2D.h olcPGEX_AnimatedSprite.h olcPGEX_AdditionalColours.h
        Game.cpp Game.h)
