#include <SFML/Graphics.hpp>
#include <time.h>

#define LENGHT 8
#define pawnBLACK 1
#define pawnWHITE -1
#define rookBLACK 2
#define rookWHITE -2
#define knightWHITE -3
#define knightBLACK 3
#define bishopBLACK 4
#define bishopWHITE -4
#define queenWHITE -5
#define queenBLACK 5
#define kingBLACK 6
#define kingWHITE -6

#pragma once

using namespace std;
using namespace sf;



class Engine
{
	RenderWindow* window;
	Event e;
	bool isMove = false;
	struct poz
	{
		int x, y;
	}oldPoz, KingWhite, KingBlack, transformWhite, transformBlack;

	int  size = 100, move = 0, x, y;
	int board[8][8] =
	{ 2, 3, 4, 5, 6, 4, 3, 2,
	  1, 1, 1, 1, 1, 1, 1, 1,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	  0, 0, 0, 0, 0, 0, 0, 0,
	 -1,-1,-1,-1,-1,-1,-1,-1,
	 -2,-3,-4,-5,-6,-4,-3,-2, };

	int RookWhiteRight = 0, RookWhiteLeft = 0, KINGWHITE = 0;
	int RookBlackRight = 0, RookBlackLeft = 0, KINGBLACK = 0;

	int moving = 0; // 0 move white, 1 move black

	int CheckWhite = 0, CheckBlack = 0;

	int TransformWhite = 0, TransformBlack = 0;

	int PawnW(int ox, int oy, int nx, int ny);
	int PawnB(int ox, int oy, int nx, int ny);
	int RookW(int ox, int oy, int nx, int ny);
	int RookB(int ox, int oy, int nx, int ny);
	int BishopW(int ox, int oy, int nx, int ny);
	int BishopB(int ox, int oy, int nx, int ny);
	int QueenW(int ox, int oy, int nx, int ny);
	int QueenB(int ox, int oy, int nx, int ny);
	int KnightW(int ox, int oy, int nx, int ny);
	int KnightB(int ox, int oy, int nx, int ny);
	int PionWCheck(int posx, int posy, int regex, int regey);
	int RookWCheck(int ox, int oy, int regex, int regey);
	int BishopWCheck(int ox, int oy, int regex, int regey);
	int QueenWCheck(int ox, int oy, int regex, int regey);
	int KnightWCheck(int ox, int oy, int regex, int regey);
	int KingWCheck(int ox, int oy, int regex, int regey);
	int PionBCheck(int ox, int oy, int regex, int regey);
	int RookBCheck(int ox, int oy, int regex, int regey);
	int BishopBCheck(int ox, int oy, int regex, int regey);
	int QueenBCheck(int ox, int oy, int regex, int regey);
	int KnightBCheck(int ox, int oy, int regex, int regey);
	int KingBCheck(int ox, int oy, int regex, int regey);
	int CheckForBlackKing(int posRegex, int posRegey);
	int KingB(int ox, int oy, int nx, int ny);
	int CheckForWhiteKing(int posRegex, int posRegey);
	int KingW(int ox, int oy, int nx, int ny);
	void pozKingWhite();
	void pozKingBlack();


public:
	Engine(sf::RenderWindow& win);
	~Engine();
	void runEngine();

};