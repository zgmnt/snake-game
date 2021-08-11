#include "Background.h"

class Sets
{
	Background background;

public:
	Sets() {}
	~Sets() {}
	void load(int WIDTH, int HEIGHT);
	void update(sf::RenderWindow* W);
};