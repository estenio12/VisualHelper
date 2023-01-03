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

    public:
        PinManager();
        ~PinManager();

    private:
        void CommitConnection();

    public:
        void RenderComponent(sf::RenderWindow& );
        Pin::PINID GetNewPinID();
        void MakeConnection(Pin* );
        void CancelMakeConnection();
        void CutConnection(Pin* );

};