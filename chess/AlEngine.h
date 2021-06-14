#include <SFML/Graphics.hpp>
#include <time.h>
#include "Engine.h"


using namespace std;
using namespace sf;

class AlEngine
{
	RenderWindow* window;
	Event e;


public:
	AlEngine(sf::RenderWindow& win);
	~AlEngine();
	void runAlEngine();
};

