// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "../Includes/Pin.hpp"
#include "../Includes/PinManager.hpp"
#include "../Includes/Object2D.hpp"
#include "../Helpers/DataDefinions.hpp"

class Cards : public Object2D
{
    private:
        PinManager* PinMan;
        std::vector<Pin*> InputPin;
        std::vector<Pin*> OutputPin;
        sf::RectangleShape TitleBarBox;
        sf::Text TitleTextDisplay;
        std::string CardName;

    public:
        Cards(PinManager* );
        ~Cards();

    protected:
        void CreateInputPin(PinType );
        void CreateOutputPin(PinType );
        void UpdateObject(float deltatime, sf::Event ) override;
        void RenderObject(sf::RenderWindow* ) override;

    public:
        Pin* GetOutputPin(Pin::PINID PinID);
        Pin* GetInputPin(Pin::PINID PinID);
        std::string GetName() { return this->CardName; }

    public:
        void SetName(std::string Name){ this->CardName = Name; }
        virtual void UpdateComponent(float deltatime, sf::Event ) = 0;
        virtual void RenderComponent(sf::RenderWindow* ) = 0;
};