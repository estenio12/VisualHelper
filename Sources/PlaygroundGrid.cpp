#include "../Includes/PlaygroundGrid.hpp"

PlaygroundGrid::PlaygroundGrid(tgui::CanvasSFML::Ptr Render, const sf::Vector2f& AnchorPosition):
    Render(Render), AnchorPosition(AnchorPosition)
{
    // # Call setup functions
    this->LoadLines();
}

PlaygroundGrid::~PlaygroundGrid()
{
    LineList.clear();
}

void PlaygroundGrid::LoadLines()
{
    this->BuildVerticalLines();
    this->BuildHorizontalLines();
}

void PlaygroundGrid::BuildVerticalLines()
{
    int NextLinePositionX = 0;

    for(int i = 0; i < MAX_TOTAL_LINE; i++)
    {
        sf::Vector2f TempPositionInit(NextLinePositionX, this->StartPosition.y);
        sf::Vector2f TempPositionFinal(0.6, 1000);
    
        sf::RectangleShape TempLine;
        TempLine.setPosition(TempPositionInit);
        TempLine.setSize(TempPositionFinal);
        TempLine.setFillColor(DEFAULT_GRID_COLOR);

        this->LineList.push_back
        (
            TempLine
        );

        NextLinePositionX += Cellspacing;
    }
}

void PlaygroundGrid::BuildHorizontalLines()
{
    int NextLinePositionY = StartPosition.y;

    for(int i = 0; i < MAX_TOTAL_LINE; i++)
    {
        sf::Vector2f TempPositionInit(this->StartPosition.y, NextLinePositionY);
        sf::Vector2f TempPositionFinal(SizeLine.x, 0.6);
    
        sf::RectangleShape TempLine;
        TempLine.setPosition(TempPositionInit);
        TempLine.setSize(TempPositionFinal);
        TempLine.setFillColor(DEFAULT_GRID_COLOR);

        this->LineList.push_back
        (
            TempLine
        );

        NextLinePositionY += Cellspacing;
    }
}

void PlaygroundGrid::RenderGrid()
{ 
    for(int i = 0; i < LineList.size(); i++)
    {
        // std::cout << (this->Render->getSize().x / MAX_TOTAL_LINE) << std::endl;
        // LineList[i].setPosition();
        Render->draw(LineList[i]);
    }
}