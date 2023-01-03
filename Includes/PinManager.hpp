// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <utility>

#include "../Includes/Pin.hpp"

class PinManager
{
    private:
        uint64_t PINIDMANAGER = 1;
        Pin* NewConnectionOrigin;
        Pin* NewConnectionTarget;
        std::vector<std::pair<Pin*, Pin*>> PinConnections;
        sf::RenderWindow* Render;

    public:
        PinManager(sf::RenderWindow* );
        ~PinManager();

    private:
        void CommitConnection();
        sf::Color GetLineColorByType(PinType ) const;

    public:
        void RenderComponent();
        Pin::PINID GetNewPinID();
        void MakeConnection(Pin* );
        void CancelMakeConnection();
        void CutConnection(Pin* );

};