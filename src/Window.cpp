#include "Window.h"

void Window::update()
{
	window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_window_name);
	window->setFramerateLimit(25);

	Sets set{ Switcher::menu };
	set.load(m_width, m_height);

	while (window->isOpen())
	{
		// quit on ESC
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window->close();

		sf::Event event;
		while (window->pollEvent(event))
		{
			// quit on close icon
			if (event.type == sf::Event::Closed)
				window->close();
		}

		window->clear();
		set.update(window);
		window->display();
	}
}