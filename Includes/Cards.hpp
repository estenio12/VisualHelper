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
        sf::RectangleShape BackgroundCard;
        sf::Text TitleTextDisplay;
        std::string CardName;

    private:
        const float MAX_SIZE_HEIGHT_TITLEBAR = 20;

    public:
        Cards(PinManager* );
        ~Cards();

    private:
        void UpdateTitleBarBounds();
        void UpdateTitleBarText();
        void UpdateBackgroundCard();
        void UpdatePinListInput();
        void UpdatePinListOutput();
        void RenderTitleBar();
        void RenderTitleBarText();
        void RenderBackgroundCard();

    protected:
        // # @param 1 = Type of pin (float, int, etc...)
        // # @param 2 = Name of pin
        // # @param 3 = Type IO (decide what side will appear)
        void CreatePin(PinType, std::string, Pin::TYPEIO );
        void UpdateObject() override;
        void RenderObject() override;

    public:
        Pin* GetOutputPin(Pin::PINID PinID);
        Pin* GetInputPin(Pin::PINID PinID);
        std::string GetName() const { return this->CardName; }

    public:
        void SetName(std::string Name){ this->CardName = Name; }
        void SetTitleBarColor(sf::Color );
        virtual void UpdateComponent() = 0;
        virtual void RenderComponent() = 0;
};