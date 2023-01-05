#include "../Includes/Pin.hpp"

Pin::Pin(){}

Pin::~Pin(){}

template<typename T> T Pin::GetData()
{
    switch (this->GetPinType())
    {
        case PinType::CHAR:
            return this->Data[0];

        case PinType::FLOAT:
            return static_cast<float>(this->Data);

        case PinType::INT:
            return static_cast<int>(this->Data);

        default:
            return this->Data;
            break;
    }
}

void UpdateObject()
{
    
}

void RenderObject()
{

}
