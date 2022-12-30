// # #######################################
// # 
// # Software developed by Estenio Garcia
// # (C) Copyright All reserved!
// # 
// # #######################################

#pragma once

#include <SFML/Graphics.hpp>

class GridConf
{
    public:
        sf::Vector2f StartPosition;
        sf::Vector2f EndPosition;
        int Cellspace = 10;

    public:
        GridConf(const sf::Vector2f StartPosition,
                 const sf::Vector2f EndPosition,
                 const int Cellspace):
                 StartPosition(StartPosition),
                 EndPosition(EndPosition),
                 Cellspace(Cellspace){}
};