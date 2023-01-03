#include "../Includes/Object2D.hpp"

void Object2D::CheckClicked(sf::Event& event)
{
    if(event.type == sf::Event::MouseButtonPressed && 
       event.type == sf::Mouse::Left)
    {
        if(this->BoundingBox.getGlobalBounds().contains
        (
            sf::Mouse::getPosition().x,
            sf::Mouse::getPosition().y
        ))
        {
            this->Clicked = true;
        }
    }

    if(event.type == sf::Event::MouseButtonReleased &&
       event.type == sf::Mouse::Left)
    {
        if(this->BoundingBox.getGlobalBounds().contains
        (
            sf::Mouse::getPosition().x,
            sf::Mouse::getPosition().y
        ))
        {
            this->Clicked = false;
        }
    }
}

void Object2D::SetObjectID(OBJID ObjID){this->ObjectID = ObjID;}

void Object2D::SetSize(sf::Vector2f Size)
{
    this->Size = Size;
    this->BoundingBox.setSize(Size);
}

void Object2D::SetPosition(sf::Vector2f Position)
{
    this->Position = Position;
    this->BoundingBox.setPosition(Position);
}

void Object2D::SetType(const TypeObject type){this->Type = type;}
