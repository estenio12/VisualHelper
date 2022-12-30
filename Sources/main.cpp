#include <iostream>
#include <TGUI/TGUI.hpp>
#include <TGUI/Backend/SFML-Graphics.hpp>

#include "../Includes/Dock.hpp"
#include "../Includes/Playground.hpp"

static int SCREEN_SIZE_WIDTH  = 900;
static int SCREEN_SIZE_HEIGHT = 600;

int main(int argc, char** argv)
{

    sf::RenderWindow Window(sf::VideoMode(SCREEN_SIZE_WIDTH, SCREEN_SIZE_HEIGHT), 
                            "VSScript-Editor", 
                            sf::Style::Default);
    sf::Event WindowEvent;

    // # Window Setting
    Window.setVerticalSyncEnabled(true);

    // # Assign Window to GUI manager
    tgui::Gui GUIManager{Window};
    tgui::Theme Theme{"./Setting/laf_standard.laf"};

    // # Instanciate enitities
    Dock* dock = new Dock(&GUIManager, Theme);
    Playground* canvas = new Playground(&GUIManager, &WindowEvent, Theme);

    while(Window.isOpen())
    {
        while(Window.pollEvent(WindowEvent))
        {
            GUIManager.handleEvent(WindowEvent);

            switch (WindowEvent.type)
            {
                case sf::Event::Closed:
                    Window.close();
                    break;
                
                default:
                    break;
            }
        }

        // # Update all components
        dock->UpdateComponent();
        canvas->UpdateComponent();

        // // # Render all components
        Window.clear(sf::Color(67, 67, 67, 255));

        GUIManager.draw();

        Window.display();
    }

    // # Free component from memory
    delete dock;
    delete canvas;

    return EXIT_SUCCESS;
}