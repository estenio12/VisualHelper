// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

#include <string>
#include <cstdint>

#include "../Helpers/DataDefinions.hpp"
#include "../Includes/Object2D.hpp"

class Pin : public Object2D
{
    public:
        using PINID = std::string;
        enum TYPEIO
        {
            OUTPUT,
            INPUT
        };

    private:
        PINID PinID;
        PinType Type;
        std::string Name;
        TYPEIO TypeIO;
        std::string Data;
        sf::CircleShape PinShape;
        sf::Color PinColor;
        bool IsConnected = false;
        sf::Text PinName;

    private:
        const float PINNAME_POSITION_FACTOR = 10;
    
    public:
        Pin();
        ~Pin();

    private:
        void RenderPinName();

    public:
        void SetPinID(const PINID ID) { this->PinID = ID; }
        void SetPinType(const PinType type);
        void SetName(std::string Name) { this->Name = Name; }
        void SetTypeIO(TYPEIO TypeIO) { this->TypeIO = TypeIO; }
        void SetData(std::string Data) { this->Data = Data; }
        void SetConnected(bool flag){ this->IsConnected = flag; }

    public:
        PINID GetPinID() { return PinID; }
        PinType GetPinType() const { return Type; }
        std::string GetName() const { return Name; }
        TYPEIO GetTypeIO() const { return TypeIO; }
        template<typename T> T GetData() const;

    public:
        void UpdateObject() override;
        void RenderObject() override;
};