#include"Window.h"

int main()
{
    while (Window::get()->isOpen())
    {
        sf::Event event;
        while (Window::get()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                Window::get()->close();
        }

        Window::get()->clear();
        // draw
        Window::get()->display();
    }

    return 0;
}