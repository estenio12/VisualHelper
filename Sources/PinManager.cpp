#include "../Includes/PinManager.hpp"

PinManager::PinManager(sf::RenderWindow* Render):Render(Render){}

PinManager::~PinManager()
{
    PinConnections.clear();
}

void PinManager::CancelMakeConnection()
{
    this->NewConnectionOrigin = nullptr;
}

void PinManager::MakeConnection(Pin* PinTarget)
{
    if(this->NewConnectionOrigin == nullptr)
    {
        this->NewConnectionOrigin = PinTarget;
    }
    else
    {
        this->NewConnectionTarget = PinTarget;;
        this->CommitConnection();
    }
}

void PinManager::CommitConnection()
{
    this->PinConnections.push_back
    (
        std::make_pair(this->NewConnectionOrigin,
                       this->NewConnectionTarget)
    );

    this->NewConnectionOrigin = nullptr;
    this->NewConnectionTarget = nullptr;
}

Pin::PINID PinManager::GetNewPinID()
{
    return std::to_string(++PINIDMANAGER);
}

void PinManager::CutConnection(Pin* PinTarget)
{
    for(int i = 0; i < PinConnections.size(); i++)
    {
        if(PinConnections[i].first->GetPinID() == PinTarget->GetPinID() ||
           PinConnections[i].second->GetPinID() == PinTarget->GetPinID())
        {
            PinConnections.erase(PinConnections.begin() + i);
        }
    }
}

sf::Color PinManager::GetLineColorByType(PinType Type) const
{
    switch (Type)
    {
        case PinType::CHAR:
            return TypeColor::CHAR;
            break;

        case PinType::FLOAT:
            return TypeColor::FLOAT;
            break;

        case PinType::INT:
            return TypeColor::INT;
            break;

        case PinType::STRING:
            return TypeColor::STRING;
            break;
    }

    return sf::Color::White;
}

void PinManager::RenderComponent()
{
    for(int i = 0; i < PinConnections.size(); i++)
    {
        sf::Vertex TempLine[2]
        {
            PinConnections[i].first->GetPosition(),
            PinConnections[i].second->GetPosition()
        };

        sf::Color TypeColor = 
            this->GetLineColorByType(
                PinConnections[i].first->GetPinType());
        
        TempLine[0].color = TypeColor;
        TempLine[1].color = TypeColor;

        Render->draw(TempLine, 2, sf::Lines);
    }
}