// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

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