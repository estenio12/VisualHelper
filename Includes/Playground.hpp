// # #######################################
// # 
// # Software developed by Estenio Garcia
// # (C) Copyright All reserved!
// # 
// # #######################################

#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "../Includes/PlaygroundGrid.hpp"

class Playground
{
    private:
        tgui::Gui* UIManager;
        tgui::Panel::Ptr Viewport;
        tgui::Theme Theme;
        tgui::CanvasSFML::Ptr RenderCanvas;
        tgui::Button::Ptr Button_MoveViewport_Left;
        tgui::Button::Ptr Button_MoveViewport_Right;
        tgui::Button::Ptr Button_MoveViewport_Top;
        tgui::Button::Ptr Button_MoveViewport_Down;

        PlaygroundGrid* Grid;
        sf::Event* WindowEvent;
        sf::RectangleShape CameraAnchor;
        sf::View Camera;

        sf::RectangleShape Debug;

    private:
        const float INIT_SIZE = 300;
        const float INIT_POSITION = 0;
        const float VIEWPORT_POSITION_Y = 40;
        const int VIEWPORT_BUTTON_SIZE = 50;
        const float VIEWPORT_MOVE_SPEED = 5;

    public:
        Playground(tgui::Gui*, sf::Event*, tgui::Theme& );
        ~Playground();

    private:
        void LoadRenderCanvas();
        void LoadViewport();
        void LoadGrid();
        void LoadCamera();
        void LoadViewportButtons();
        void ViewportRendering();
        void ViewportMove();
        void ViewportComponentResize();

    private:
        void ViewportMoveToRight();
        void ViewportMoveToLeft();
        void ViewportMoveToTop();
        void ViewportMoveToDown();

    public:
        void UpdateComponent();
        
};