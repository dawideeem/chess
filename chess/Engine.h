#include <SFML/Graphics.hpp>
#include <time.h>


#pragma once

using namespace std;
using namespace sf;



class Engine
{
	RenderWindow *window;
	Event e;
	bool isMove = false;
	float dx = 0, dy = 0;
	int size = 100;
	int n = 0;
	Sprite f[32]; //figures
	int board[8][8] =
	{ 2, 3, 4, 5, 6, 4, 3, 2,
	 1, 1, 1, 1, 1, 1, 1, 1,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  -1, -1, -1, -1, -1, -1, -1, -1,
	 -2, -3, -4, -5, -6, -4, -3, -2 };
	void loadPosition();

public:
	Engine(sf::RenderWindow &win);
	~Engine();
	void runEngine();

};

