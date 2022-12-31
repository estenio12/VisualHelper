#include "../Includes/Playground.hpp"

Playground::Playground(tgui::Gui* UIManager,
                       sf::Event* WindowEvent,
                       tgui::Theme& Theme ):
    UIManager(UIManager),
    WindowEvent(WindowEvent),
    Theme(Theme)
{
    this->LoadViewport();
    this->LoadRenderCanvas();
    this->LoadGrid();
    this->LoadCamera();
    this->LoadViewportButtons();

    Debug.setPosition(sf::Vector2f(100, 100));
    Debug.setSize(sf::Vector2f(10, 10));
    Debug.setFillColor(sf::Color::Red);
}

Playground::~Playground(){}

void Playground::UpdateComponent()
{
    // # Resize viewport with window
    Viewport->setSize(UIManager->getView().getWidth(),
                      UIManager->getView().getHeight() - VIEWPORT_POSITION_Y);
    RenderCanvas->setSize(Viewport->getSize().x,
                          Viewport->getSize().y);
    Camera.setSize(Viewport->getSize().x,
                   Viewport->getSize().y);
    

    // # Call function
    this->ViewportMove();
    this->ViewportRendering();
    this->ViewportComponentResize();
    this->AdjustGridOffsetBackward();
    this->AdjustGridOffsetForward();
}

void Playground::ViewportRendering()
{
    RenderCanvas->setView(Camera);
    RenderCanvas->clear({51, 51, 51, 255});

    RenderCanvas->draw(GridMap);
    RenderCanvas->draw(Debug);
    RenderCanvas->draw(CameraAnchor);

    RenderCanvas->display();
}

void Playground::LoadViewport()
{
    Viewport = tgui::Panel::create();
    Viewport->setPosition(INIT_POSITION, VIEWPORT_POSITION_Y);
    Viewport->setSize(INIT_SIZE, INIT_SIZE);

    this->UIManager->add(Viewport);
}

void Playground::LoadRenderCanvas()
{
    RenderCanvas = tgui::CanvasSFML::create();
    RenderCanvas->setSize(INIT_SIZE, INIT_SIZE);
    RenderCanvas->setPosition(INIT_POSITION, INIT_POSITION);

    this->Viewport->add(RenderCanvas);
}

void Playground::LoadGrid()
{
    const int GridLayout[36] =
    {
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0,
        0, 0, 0, 0, 0, 0
    };

    if(!GridMap.load("./Setting/Teste.png", 
                     sf::Vector2u(GRID_TEXTURE_SIZE, GRID_TEXTURE_SIZE), 
                     GridLayout, 
                     GRID_LAYOUT_WIDTH, 
                     GRID_LAYOUT_HEIGHT))
    {
        std::cerr << "Cannot load grid texure." << std::endl;
    }
}

void Playground::LoadCamera()
{
    CameraAnchor.setPosition(sf::Vector2f(0, 0));
    CameraAnchor.setSize(sf::Vector2f(10, 10));
    Camera.setCenter(CameraAnchor.getPosition());
}

void Playground::ViewportMove()
{
    if(WindowEvent->type == sf::Event::MouseButtonPressed &&
       WindowEvent->mouseButton.button == sf::Mouse::Left)
    {
        // # Move Viewport to right
        if(WindowEvent->mouseButton.x > Viewport->getSize().x - VIEWPORT_BUTTON_SIZE)
        {
            this->ViewportMoveToRight();
        }

        // # Move Viewport to right
        if(WindowEvent->mouseButton.x < Viewport->getPosition().x + VIEWPORT_BUTTON_SIZE)
        {
            this->ViewportMoveToLeft();
        }

        // # Move Viewport to Top
        if(WindowEvent->mouseButton.y > Viewport->getPosition().y + VIEWPORT_BUTTON_SIZE)
        {
            this->ViewportMoveToDown();
        }

        // # Move Viewport to Down
        if(WindowEvent->mouseButton.y < Viewport->getSize().y - VIEWPORT_BUTTON_SIZE)
        {
            this->ViewportMoveToTop();
        }
    }

    Camera.setCenter(CameraAnchor.getPosition());
    RenderCanvas->setView(Camera);
}

void Playground::LoadViewportButtons()
{
    // # Load Viewport Right Button 
    Button_MoveViewport_Right = tgui::Button::create();
    Button_MoveViewport_Right->setPosition(Viewport->getSize().x - VIEWPORT_BUTTON_SIZE,
                                        VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Right->setSize(VIEWPORT_BUTTON_SIZE,
                                    Viewport->getSize().y - VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Right->setRenderer(Theme.getRenderer("Viewport-controller-right"));

    // # Load Viewport Left Button 
    Button_MoveViewport_Left = tgui::Button::create();
    Button_MoveViewport_Left->setPosition(VIEWPORT_BUTTON_SIZE,
                                       VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Left->setSize(VIEWPORT_BUTTON_SIZE,
                                   Viewport->getSize().y - VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Left->setRenderer(Theme.getRenderer("Viewport-controller-left"));

    // # Load Viewport Top Button 
    Button_MoveViewport_Top = tgui::Button::create();
    Button_MoveViewport_Top->setPosition(INIT_POSITION,
                                      INIT_POSITION);
    Button_MoveViewport_Top->setSize(Viewport->getSize().x,
                                  VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Top->setRenderer(Theme.getRenderer("Viewport-controller-top"));

    // # Load Viewport Down Button 
    Button_MoveViewport_Down = tgui::Button::create();
    Button_MoveViewport_Down->setPosition(VIEWPORT_BUTTON_SIZE,
                                       VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Down->setSize(Viewport->getSize().x,
                                   VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Down->setRenderer(Theme.getRenderer("Viewport-controller-down"));

    Viewport->add(Button_MoveViewport_Left);
    Viewport->add(Button_MoveViewport_Right);
    Viewport->add(Button_MoveViewport_Top);
    Viewport->add(Button_MoveViewport_Down);
}

void Playground::ViewportComponentResize()
{
    if(this->WindowEvent->type == sf::Event::Resized)
    {
        Camera.setSize(Viewport->getSize());
    }

    // # Viewpor Button Right
    Button_MoveViewport_Right->setPosition(Viewport->getSize().x - VIEWPORT_BUTTON_SIZE,
                                           VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Right->setSize(VIEWPORT_BUTTON_SIZE,
                                       Viewport->getSize().y - (VIEWPORT_BUTTON_SIZE * 2));
    
    // # Viewpor Button Left
    Button_MoveViewport_Left->setPosition(INIT_POSITION,
                                          VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Left->setSize(VIEWPORT_BUTTON_SIZE,
                                      Viewport->getSize().y - (VIEWPORT_BUTTON_SIZE * 2));
    
    // # Viewpor Button Top
    //Btn_MoveViewport_Top->setPosition(INIT_POSITION,
      //                                VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Top->setSize(Viewport->getSize().x,
                                     VIEWPORT_BUTTON_SIZE);

    // # Viewpor Button Down
    Button_MoveViewport_Down->setPosition(INIT_POSITION,
                                          Viewport->getSize().y - VIEWPORT_BUTTON_SIZE);
    Button_MoveViewport_Down->setSize(Viewport->getSize().x,
                                      VIEWPORT_BUTTON_SIZE);
    
}

void Playground::ViewportMoveToRight()
{
    this->CameraAnchor.move(VIEWPORT_MOVE_SPEED, 0);
}

void Playground::ViewportMoveToLeft()
{
    this->CameraAnchor.move(-VIEWPORT_MOVE_SPEED, 0);
}

void Playground::ViewportMoveToTop()
{
    this->CameraAnchor.move(0, -VIEWPORT_MOVE_SPEED);
}

void Playground::ViewportMoveToDown()
{
    this->CameraAnchor.move(0, VIEWPORT_MOVE_SPEED);
}

void Playground::AdjustGridOffsetBackward()
{
    sf::Vector2f CalculateGridPositionLimit
    (
        // # X
        ((GRID_TEXTURE_SIZE * GRID_LAYOUT_WIDTH) / 2),
        // # Y
        ((GRID_TEXTURE_SIZE * GRID_LAYOUT_HEIGHT) / 2)
    );

    sf::Vector2f GridPositionLimit
    (
        // # X
        -(CalculateGridPositionLimit.x - (this->Viewport->getSize().x / 2) - GRID_LIMIT_SAVE),
        // # Y
        -(CalculateGridPositionLimit.y - (this->Viewport->getSize().y / 2) - GRID_LIMIT_SAVE)
    );

    if(CameraAnchor.getPosition().x < GridPositionLimit.x)
    {
        this->CameraAnchor.setPosition(GridPositionLimit.x,
                                       CameraAnchor.getPosition().y);
    }

    if(CameraAnchor.getPosition().y < GridPositionLimit.y)
    {
        this->CameraAnchor.setPosition(CameraAnchor.getPosition().x,
                                       GridPositionLimit.y);
    }
}

void Playground::AdjustGridOffsetForward()
{
    sf::Vector2f CalculateGridSizeLimit
    (
        // # X
        ((GRID_TEXTURE_SIZE * GRID_LAYOUT_WIDTH) / 2),
        // # Y
        ((GRID_TEXTURE_SIZE * GRID_LAYOUT_HEIGHT) / 2)
    );

    sf::Vector2f GridSizeLimit
    (
        // # X
        (CalculateGridSizeLimit.x - (this->Viewport->getSize().x / 2) - GRID_LIMIT_SAVE),
        // # Y
        (CalculateGridSizeLimit.y - (this->Viewport->getSize().y / 2) - GRID_LIMIT_SAVE)
    );

    if(CameraAnchor.getPosition().x > GridSizeLimit.x)
    {
        this->CameraAnchor.setPosition(GridSizeLimit.x,
                                       CameraAnchor.getPosition().y);
    }

    if(CameraAnchor.getPosition().y > GridSizeLimit.y)
    {
        this->CameraAnchor.setPosition(CameraAnchor.getPosition().x,
                                       GridSizeLimit.y);
    }
}
