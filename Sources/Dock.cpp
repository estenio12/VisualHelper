#include "../Includes/Dock.hpp"

Dock::Dock(tgui::Gui* Window, tgui::Theme& Theme):
    Window(Window), Theme(Theme)
{
    this->CreateComponent();
    this->LoadConfigurationPanel_Dock();
    this->LoadConfigurationBtn_BuildAndExecute();
    this->LoadConfigurationBtn_BuildOnly();
    this->LoadConfigurationBtn_AddOption();
    this->LoadConfigurationBtn_Help();

    this->AttachComponentToDock();
    this->LoadIcons();
}

Dock::~Dock(){}

void Dock::CreateComponent()
{
    Panel_Dock          = tgui::Panel::create();
    btn_BuildAndExecute = tgui::Button::create();
    btn_BuildOnly       = tgui::Button::create();
    btn_AddOption       = tgui::Button::create();
    btn_Help            = tgui::Button::create("?");

    Window->add(Panel_Dock);
}

void Dock::AttachComponentToDock()
{
    Panel_Dock->add(btn_BuildAndExecute);
    Panel_Dock->add(btn_BuildOnly);
    Panel_Dock->add(btn_AddOption);
    Panel_Dock->add(btn_Help);
}

void Dock::LoadIcons()
{
    this->LoadCompileAndRunIcon();
    this->LoadCompileIcon();
    this->LoadAddOptionIcon();
}

void Dock::UpdateComponent()
{
    // # Resize Panel_Dock to new window size width
    Panel_Dock->setSize(Window->getView().getWidth(),
                        INIT_DOCK_SIZE_HEIGHT);
    btn_Help->setPosition(Panel_Dock->getSize().x - 55,
                          DOCK_BUTTON_POSITION_Y);
}

void Dock::LoadConfigurationPanel_Dock()
{
    Panel_Dock->setPosition(this->PanelDock_Position);
    Panel_Dock->setSize(this->PanelDock_Size);
    Panel_Dock->setRenderer(this->Theme.getRenderer("Panel"));
}

void Dock::LoadConfigurationBtn_BuildAndExecute()
{
    btn_BuildAndExecute->setPosition(DOCK_BUTTON_POSITION_X,
                                     DOCK_BUTTON_POSITION_Y);
    btn_BuildAndExecute->setSize(DOCK_BUTTON_SIZE_WIDTH, 
                                 INIT_DOCK_SIZE_HEIGHT - 4);
    btn_BuildAndExecute->setRenderer(this->Theme.getRenderer("Button"));
}

void Dock::LoadConfigurationBtn_BuildOnly()
{
    btn_BuildOnly->setPosition(60,
                               DOCK_BUTTON_POSITION_Y);
    btn_BuildOnly->setSize(DOCK_BUTTON_SIZE_WIDTH, 
                           INIT_DOCK_SIZE_HEIGHT - 4);
    btn_BuildOnly->setRenderer(this->Theme.getRenderer("Button"));
}

void Dock::LoadConfigurationBtn_AddOption()
{
    btn_AddOption->setPosition(115,
                               DOCK_BUTTON_POSITION_Y);
    btn_AddOption->setSize(DOCK_BUTTON_SIZE_WIDTH, 
                           INIT_DOCK_SIZE_HEIGHT - 4);
    btn_AddOption->setRenderer(this->Theme.getRenderer("Button"));
}

void Dock::LoadConfigurationBtn_Help()
{
    btn_Help->setPosition(DOCK_BUTTON_POSITION_X, 
                          DOCK_BUTTON_POSITION_Y);
    btn_Help->setSize(DOCK_BUTTON_SIZE_WIDTH, 
                      INIT_DOCK_SIZE_HEIGHT - 4);
    btn_Help->setRenderer(this->Theme.getRenderer("Button"));
}

void Dock::LoadCompileAndRunIcon()
{
    tgui::Picture::Ptr Icon = tgui::Picture::create("./Setting/Assets.png");
    Icon->setRenderer(Theme.getRenderer("Icon-Play"));
    Icon->setSize(35, 45);
    Icon->setScale(0.4);

    tgui::Vector2f GetPosition = this->btn_BuildAndExecute->getPosition();
    tgui::Vector2f GetSize     = this->btn_BuildAndExecute->getSize();
    tgui::Vector2f IconPosition;

    IconPosition.x = GetPosition.x + (( GetSize.x / 3)); 
    IconPosition.y = GetPosition.y + (( GetSize.y / 4)); 

    Icon->setPosition(IconPosition);

    Panel_Dock->add(Icon);
}

void Dock::LoadCompileIcon()
{
    tgui::Picture::Ptr Icon = tgui::Picture::create("./Setting/Assets.png");
    Icon->setRenderer(Theme.getRenderer("Icon-Gear"));
    Icon->setSize(28, 30);
    Icon->setScale(0.6);

    tgui::Vector2f GetPosition = this->btn_BuildOnly->getPosition();
    tgui::Vector2f GetSize     = this->btn_BuildOnly->getSize();
    tgui::Vector2f IconPosition;

    IconPosition.x = GetPosition.x + (( GetSize.x / 3)); 
    IconPosition.y = GetPosition.y + (( GetSize.y / 4)); 

    Icon->setPosition(IconPosition);

    Panel_Dock->add(Icon);
}

void Dock::LoadAddOptionIcon()
{
    tgui::Picture::Ptr Icon = tgui::Picture::create("./Setting/Assets.png");
    Icon->setRenderer(Theme.getRenderer("Icon-Plus"));
    Icon->setSize(20, 20);
    Icon->setScale(0.9);

    tgui::Vector2f GetPosition = this->btn_AddOption->getPosition();
    tgui::Vector2f GetSize     = this->btn_AddOption->getSize();
    tgui::Vector2f IconPosition;

    IconPosition.x = GetPosition.x + (( GetSize.x / 3)); 
    IconPosition.y = GetPosition.y + (( GetSize.y / 4)); 

    Icon->setPosition(IconPosition);

    Panel_Dock->add(Icon);
}