#pragma once
#include<SFML/Graphics.hpp>

const unsigned int HEIGHT = 720;
const unsigned int WIDTH = 1280;
const std::string window_name{ "window" };

class Window
{
	static sf::RenderWindow* window;

public:

	static sf::RenderWindow* get()
	{
		if (window == nullptr)
		{
			window = new sf::RenderWindow(sf::VideoMode(WIDTH, HEIGHT), window_name);
		}

		return window;
	}
};

sf::RenderWindow* Window::window;