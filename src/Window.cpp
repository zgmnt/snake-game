#include "Window.h"

void Window::update()
{
	if(!m_window)
		m_window = new sf::RenderWindow(sf::VideoMode(m_width, m_height), m_window_name);
	
	m_window->setFramerateLimit(25);

	Sets set{ Switcher::menu };
	set.load(m_width, m_height);

	while (m_window->isOpen())
	{
		// quit on ESC
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			m_window->close();

		sf::Event event;
		while (m_window->pollEvent(event))
		{
			// quit on close icon
			if (event.type == sf::Event::Closed)
				m_window->close();
		}

		m_window->clear();
		set.update(m_window);
		m_window->display();
	}
}
