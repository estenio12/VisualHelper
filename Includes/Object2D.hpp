// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

#include <string>
#include <SFML/Graphics.hpp>

#include "../Helpers/DataDefinions.hpp"

class Object2D
{
    public:
        using OBJID = std::string;

    private:
        OBJID ObjectID;
        TypeObject Type;
        sf::Vector2f Position;
        sf::Vector2f Size;
        sf::RectangleShape BoundingBox;
        bool Clicked = false;

    public:
        virtual void UpdateObject(float deltatime, sf::Event event) = 0;
        virtual void RenderObject(sf::RenderWindow* ) = 0;
        void CheckClicked(sf::Event& );

    public:
        sf::Vector2f GetPosition() const {return Position;};
        sf::Vector2f GetSize() const {return Size;};
        sf::FloatRect GetBoundingBox() const {return BoundingBox.getGlobalBounds();};
        bool IsClicked() {return Clicked;}
        TypeObject GetType() const {return Type;};
        std::string GetObjectID() {return ObjectID;};

    public:
        void SetPosition(sf::Vector2f );
        void SetSize(sf::Vector2f );
        void SetType(TypeObject );
        void SetObjectID(OBJID );

}; 