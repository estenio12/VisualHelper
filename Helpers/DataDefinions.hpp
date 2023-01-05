// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

#include <SFML/Graphics.hpp>

enum TypeObject
{
    INT,
    FLOAT,
    CHAR,
    STRING,
    FUNCTION,
    PIN
};

enum PinType
{
    INT,
    FLOAT,
    CHAR,
    STRING,
    CALL
};

namespace TypeColor
{
    static sf::Color CHAR = sf::Color(188, 170, 77);
    static sf::Color FLOAT = sf::Color(59, 170, 29);
    static sf::Color INT = sf::Color(92, 206, 189);
    static sf::Color STRING = sf::Color(206, 92, 185);
}

namespace Config
{
    static sf::Font GetFontRegular()
    {
        sf::Font font;
        font.loadFromFile("../Resources/Font/UbuntuMono-R.ttf");

        return font;
    }

    static float FONT_SIZE = 12;
    static sf::Color DefaultTextColor = sf::Color::White;
    static sf::Color DefaultBgCardColor = sf::Color(67, 67, 67, 90);
    static sf::Color DefaultBorderCardColor = sf::Color(20, 20, 20);

    // # 
    static float DefaultPinRadius = 10.f;
}