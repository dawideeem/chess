#pragma once

#include <SFML\Graphics.hpp>
#include <Windows.h>
#include <string>
#include "engine.h"
#include "AlEngine.h"

using namespace std;
using namespace sf;

class Game
{
public:
	Game(void);
	~Game(void);

	void runGame();

protected:
	enum GameState { MENU, GAME, GAME2, END };
	GameState state;

private:
	Font font;

	void menu();
	void single();
	void comp();
};