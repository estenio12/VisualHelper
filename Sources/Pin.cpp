#include "../Includes/Pin.hpp"

Pin::Pin()
{
    this->PinShape.setRadius(Config::DefaultPinRadius);
    this->PinShape.setPosition(this->GetPosition());
    this->PinShape.setFillColor(Config::DefaultPinUnconnectedColor);
    this->PinShape.setOutlineThickness(3);

    this->PinName.setFont(Config::GetFontRegular());
    this->PinName.setCharacterSize(Config::FONT_SIZE);
    this->PinName.setFillColor(Config::DefaultTextColor);
}

Pin::~Pin(){}

template<typename T> T Pin::GetData() const
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

void Pin::UpdateObject()
{
    if(this->IsConnected)
    {
        this->PinShape.setFillColor(this->PinColor);
    }
    else
    {
        this->PinShape.setFillColor(Config::DefaultPinUnconnectedColor);
    }
}

void Pin::RenderObject()
{
    this->Render->draw(this->PinShape);
}

void Pin::SetPinType(const PinType type)
{
    this->Type = type;

    switch (type)
    {
        case PinType::CHAR:
            this->PinShape.setOutlineColor(TypeColor::CHAR);
            this->PinColor = TypeColor::CHAR;
            break;

        case PinType::FLOAT:
            this->PinShape.setOutlineColor(TypeColor::FLOAT);
            this->PinColor = TypeColor::FLOAT;
            break;

        case PinType::INT:
            this->PinShape.setOutlineColor(TypeColor::INT);
            this->PinColor = TypeColor::INT;
            break;

        case PinType::STRING:
            this->PinShape.setOutlineColor(TypeColor::STRING);
            this->PinColor = TypeColor::STRING;
            break;
    }
}

void Pin::RenderPinName()
{
    if(this->TypeIO == TYPEIO::INPUT)
    {
        this->PinName.setPosition(
            this->GetPosition().x + PINNAME_POSITION_FACTOR,
            this->GetPosition().y
            );
    }
    else
    {
        this->PinName.setPosition(
            (this->GetPosition().x + this->GetSize().x) - 
            (this->Name.size() * Config::FONT_SIZE),
            this->GetPosition().y
            );
    }

    this->Render->draw(this->PinName);
}
