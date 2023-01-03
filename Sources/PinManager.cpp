#include "../Includes/PinManager.hpp"

PinManager::PinManager(){}

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
    Pin::PINID NID = std::to_string(++PINIDMANAGER);
    return NID;
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
