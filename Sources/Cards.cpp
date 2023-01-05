#include "../Includes/Cards.hpp"

Cards::Cards(PinManager* PinMan):PinMan(PinMan)
{
    this->TitleTextDisplay.setFont(Config::GetFontRegular());
    this->TitleTextDisplay.setCharacterSize(Config::FONT_SIZE);
    this->TitleTextDisplay.setFillColor(Config::DefaultTextColor);
    
    this->BackgroundCard.setFillColor(Config::DefaultBgCardColor);
    this->BackgroundCard.setOutlineColor(Config::DefaultBorderCardColor);
}

Cards::~Cards()
{
    InputPin.clear();
    OutputPin.clear();
}

void Cards::CreatePin(PinType Type, std::string Name, Pin::TYPEIO typeio)
{
    Pin::PINID NPID = PinMan->GetNewPinID();
    Pin* TmpPin = new Pin();
    TmpPin->SetPinType(Type);
    TmpPin->SetPinID(NPID);
    TmpPin->SetName(Name);
    TmpPin->SetTypeIO(typeio);

    if(typeio == Pin::TYPEIO::INPUT)
    {
        this->InputPin.push_back(TmpPin);
    }
    else
    {
        this->OutputPin.push_back(TmpPin);
    }
}

Pin* Cards::GetOutputPin(Pin::PINID PinID)
{
    for(int i = 0; i < OutputPin.size(); i++)
    {
        if(OutputPin[i]->GetPinID() == PinID)
        {
            return OutputPin[i];
        }
    }

    return nullptr;
}

Pin* Cards::GetInputPin(Pin::PINID PinID)
{
    for(int i = 0; i < InputPin.size(); i++)
    {
        if(InputPin[i]->GetPinID() == PinID)
        {
            return InputPin[i];
        }
    }

    return nullptr;
}

void Cards::UpdateObject()
{
    this->UpdateTitleBarBounds();
    this->UpdateTitleBarText();
    this->UpdateBackgroundCard();
    this->UpdatePinListInput();
    this->UpdatePinListOutput();
    this->UpdateComponent();
}

void Cards::RenderObject()
{
    this->RenderTitleBar();
    this->RenderTitleBarText();
    this->RenderBackgroundCard();
    this->RenderComponent();
}

void Cards::UpdateTitleBarBounds()
{
    this->TitleBarBox.setPosition(this->GetPosition());
    this->TitleBarBox.setSize(sf::Vector2f(this->GetSize().x,
                              (this->GetSize().y * MAX_SIZE_HEIGHT_TITLEBAR) / 100 ));
}

void Cards::UpdateTitleBarText()
{
    this->TitleTextDisplay.setPosition(this->GetPosition().x + 10,
                                       this->GetPosition().y + 5);
    this->TitleTextDisplay.setString(this->CardName);
}

void Cards::SetTitleBarColor(sf::Color NewColor)
{
    this->TitleBarBox.setFillColor(NewColor);
}

void Cards::RenderTitleBar()
{
    this->Render->draw(this->TitleBarBox);
}

void Cards::RenderTitleBarText()
{
    this->Render->draw(this->TitleTextDisplay);
}

void Cards::UpdateBackgroundCard()
{
    float GetDiffPosY = (this->GetSize().y * MAX_SIZE_HEIGHT_TITLEBAR) / 100 ;
    this->BackgroundCard.setPosition(this->GetPosition().x,
                                     this->GetPosition().y + GetDiffPosY);
    this->BackgroundCard.setSize(sf::Vector2f(this->GetSize().x,
                                 this->GetSize().y - GetDiffPosY));
}

void Cards::RenderBackgroundCard()
{
    this->Render->draw(this->BackgroundCard);
}

void Cards::UpdatePinListInput()
{
    int length = (this->BackgroundCard.getPosition().y + 
                  this->BackgroundCard.getSize().y) / 
                  this->InputPin.size();
    
    for(int i = 0; i < this->InputPin.size(); i++)
    {
        this->InputPin[i]->SetPosition(sf::Vector2f(
            this->BackgroundCard.getPosition().x - (Config::DefaultPinRadius / 2),
            (this->BackgroundCard.getPosition().y + length) - (Config::DefaultPinRadius / 2)));
    }
}

void Cards::UpdatePinListOutput()
{
    int length = (this->BackgroundCard.getPosition().y + 
                  this->BackgroundCard.getSize().y) / 
                  this->InputPin.size();
    
    for(int i = 0; i < this->InputPin.size(); i++)
    {
        this->InputPin[i]->SetPosition(sf::Vector2f(
            (this->BackgroundCard.getPosition().x + this->BackgroundCard.getSize().x ) - (Config::DefaultPinRadius / 2),
            (this->BackgroundCard.getPosition().y + length) - (Config::DefaultPinRadius / 2)));
    }
}


