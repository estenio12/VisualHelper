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
    
    public:
        Pin();
        ~Pin();

    public:
        void SetPinID(const PINID ID) { this->PinID = ID; }
        void SetPinType(const PinType type) { this->Type = type; }
        void SetName(std::string Name) { this->Name = Name; }
        void SetTypeIO(TYPEIO TypeIO) { this->TypeIO = TypeIO; }
        void SetData(std::string Data) { this->Data = Data; }

    public:
        PINID GetPinID() { return PinID; }
        PinType GetPinType() { return Type; }
        std::string GetName() { return Name; }
        TYPEIO GetTypeIO() { return TypeIO; }
        template<typename T> T GetData();

    public:
        void UpdateObject() override;
        void RenderObject() override;
};