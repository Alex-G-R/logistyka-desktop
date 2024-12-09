#include "FRSGUI/FRSGUI.hpp"
#include <iostream>

int main()
{
    /* Create the render window and FRSGUI instance */
    const auto renderer_window_ptr = std::make_shared<sf::RenderWindow>(sf::VideoMode(1920, 1080), "Logistyka", sf::Style::Default);
    fr::FRSGUI frsgui(renderer_window_ptr);

    while(renderer_window_ptr->isOpen())
    {
        sf::Event event{};
        while(renderer_window_ptr->pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                renderer_window_ptr->close();
                break;
            }
            frsgui.dispatchEvent(event);
        }
        renderer_window_ptr->clear();

        // Render gui
        frsgui.Render();
        renderer_window_ptr->display();
    }
}
