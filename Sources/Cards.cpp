#include "../Includes/Cards.hpp"

Cards::Cards(PinManager* PinMan):PinMan(PinMan){}

Cards::~Cards()
{
    InputPin.clear();
    OutputPin.clear();
}

void Cards::CreateInputPin(PinType Type)
{
    Pin::PINID NPID = PinMan->GetNewPinID();
    Pin* TmpPin = new Pin();
}