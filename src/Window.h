#include"Sets.h"

class Window
{
public:
	Window(const unsigned int WIDTH = 800, const unsigned int HEIGHT = 600,
		const std::string& WINDOW_NAME = "None")
		: m_width(WIDTH), m_height(HEIGHT), m_window_name(WINDOW_NAME)
	{
		m_window =  nullptr;
	}
	~Window() { delete m_window; }
	void update();
private:
	const unsigned int m_width;
	const unsigned int  m_height;
	const std::string m_window_name;
	sf::RenderWindow* m_window;
};
