#include <SFML/Graphics.hpp>
#include <time.h>


#pragma once

using namespace std;
using namespace sf;

class Engine
{
	sf::RenderWindow *window;
	bool isMove = false;
	float dx = 0, dy = 0;


public:
	Engine(sf::RenderWindow &win);
	~Engine();
	void runEngine();
	void draw();
};

