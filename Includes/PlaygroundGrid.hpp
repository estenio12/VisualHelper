// # #######################################
// # 
// # Software developed by Estenio Garcia
// # (C) Copyright All reserved!
// # 
// # #######################################

#pragma once

#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>
#include <vector>

#include "../Includes/GridConf.hpp"

class PlaygroundGrid
{
    private:
        const float GRID_POSITION  = 0;
        const int MAX_TOTAL_LINE   = 5000;
        const int Cellspacing      = 20;
        float GRID_SIZE_WIDTH  = 1920;
        float GRID_SIZE_HEIGHT = 1080;
        std::vector<sf::RectangleShape> LineList;
        tgui::CanvasSFML::Ptr Render;

        sf::Vector2f StartPosition{GRID_POSITION,
                                   GRID_POSITION};
        sf::Vector2f SizeLine{GRID_SIZE_WIDTH,
                              GRID_SIZE_WIDTH};
        sf::Vector2f AnchorPosition;
        
        sf::Color DEFAULT_GRID_COLOR = sf::Color(60, 60, 60);

    public:
        PlaygroundGrid(tgui::CanvasSFML::Ptr, const sf::Vector2f& );
        ~PlaygroundGrid();

    private:
        void LoadLines();
        void BuildHorizontalLines();
        void BuildVerticalLines();

    public:
        void RenderGrid();
};