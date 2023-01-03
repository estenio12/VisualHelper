// # #######################################
// # 
// # Software developed by Estenio Garcia
// # LICENSE: MIT
// # 
// # #######################################

#pragma once

#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

class Dock
{
    private:
        tgui::Gui* Window;
        tgui::Theme Theme;
        tgui::Panel::Ptr Panel_Dock;
        tgui::Button::Ptr btn_BuildAndExecute;
        tgui::Button::Ptr btn_BuildOnly;
        tgui::Button::Ptr btn_AddOption;
        tgui::Button::Ptr btn_Help;

    private:
        const float INIT_DOCK_SIZE_WIDTH  = 100;
        const float INIT_DOCK_SIZE_HEIGHT = 40;
        const float INIT_DOCK_POSITION = 0;
        const float DOCK_BUTTON_POSITION_X = 5;
        const float DOCK_BUTTON_POSITION_Y = 2;
        const float DOCK_BUTTON_SIZE_WIDTH = 50;

        tgui::Vector2f PanelDock_Position{INIT_DOCK_POSITION,
                                          INIT_DOCK_POSITION};
        tgui::Vector2f PanelDock_Size{INIT_DOCK_SIZE_WIDTH,
                                      INIT_DOCK_SIZE_HEIGHT};

    public:
        Dock(tgui::Gui*, tgui::Theme& );
        ~Dock();

    private:
        void CreateComponent();
        void LoadConfigurationPanel_Dock();
        void LoadConfigurationBtn_BuildAndExecute();
        void LoadConfigurationBtn_BuildOnly();
        void LoadConfigurationBtn_AddOption();
        void LoadConfigurationBtn_Help();
        void AttachComponentToDock();
        void LoadIcons();
        void LoadCompileAndRunIcon();
        void LoadCompileIcon();
        void LoadAddOptionIcon();

    public:
        void UpdateComponent();
};