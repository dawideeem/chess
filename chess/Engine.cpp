#include "Engine.h"
#include <iostream>


int Engine::PawnW(int ox, int oy, int nx, int ny)
{
	if (oldPoz.y == 6)
	{
		if ((ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0) || (ny == oy - 2 && nx == ox && board[oy - 1][ox] == 0 && board[oy - 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy - 1 && nx == ox && board[oy - 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy - 1][ox - 1] > 0)
	{
		if (ny == oy - 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy - 1][ox + 1] > 0)
	{
		if (ny == oy - 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int Engine::PawnB(int ox, int oy, int nx, int ny)
{
	if (oldPoz.y == 1)
	{
		if ((ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0) || (ny == oy + 2 && nx == ox && board[oy + 1][ox] == 0 && board[oy + 2][ox] == 0))
		{
			return 1;
		}
	}
	else if (ny == oy + 1 && nx == ox && board[oy + 1][ox] == 0)
	{
		return 1;
	}
	if (board[oy + 1][ox - 1] < 0)
	{
		if (ny == oy + 1 && nx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] < 0)
	{
		if (ny == oy + 1 && nx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int Engine::RookW(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // Right
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // Down
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int Engine::RookB(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // Right
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // Down
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int Engine::BishopW(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up Left
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down Left
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // Down Right
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::BishopB(int ox, int oy, int nx, int ny)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up Left
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down Left
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // Down Right
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::QueenW(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] >= 0 && (nx == i && ny == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // Right
	{
		if (board[oy][i] >= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // Down
	{
		if (board[i][ox] >= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up left
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down Left
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // Down Right
	{
		if (board[i][j] >= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::QueenB(int ox, int oy, int nx, int ny)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] <= 0 && (nx == i && ny == oy))
		{
			return 1;
			
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i <= 7; i++) // right
	{
		if (board[oy][i] <= 0 && (ny == oy && nx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i <= 7; i++) // Down
	{
		if (board[i][ox] <= 0 && (ny == i && nx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up Left
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down left
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // Down Right
	{
		if (board[i][j] <= 0 && (ny == i && nx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::KnightW(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; // Up left
	}
	if (oy - 2 >= 0 && ox + 1 < LENGHT && ny == oy - 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1; // Up Right
	}
	if (oy - 1 >= 0 && ox + 2 < LENGHT && ny == oy - 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1; // Right 1
	}
	if (oy + 1 >= 0 && ox + 2 < LENGHT && ny == oy + 1 && nx == ox + 2 && board[ny][nx] >= 0)
	{
		return 1; // Right 2
	}
	if (oy + 2 < LENGHT && ox + 1 < LENGHT && ny == oy + 2 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		return 1; // Down 1
	}
	if (oy + 2 < LENGHT && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		return 1; // Down 1
	}
	if (oy + 1 < LENGHT && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1; // Left 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] >= 0)
	{
		return 1;
	}
	return 0;
}

int Engine::KnightB(int ox, int oy, int nx, int ny)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && ny == oy - 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1; // Up left
	}
	if (oy - 2 >= 0 && ox + 1 < LENGHT && ny == oy - 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1; // Up Right
	}
	if (oy - 1 >= 0 && ox + 2 < LENGHT && ny == oy - 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1; // Right 1
	}
	if (oy + 1 >= 0 && ox + 2 < LENGHT && ny == oy + 1 && nx == ox + 2 && board[ny][nx] <= 0)
	{
		return 1; // Right 2
	}
	if (oy + 2 < LENGHT && ox + 1 < LENGHT && ny == oy + 2 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		return 1; // Down 1
	}
	if (oy + 2 < LENGHT && ox - 1 >= 0 && ny == oy + 2 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		return 1; // Down 2
	}
	if (oy + 1 < LENGHT && ox - 2 >= 0 && ny == oy + 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1; // Left 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && ny == oy - 1 && nx == ox - 2 && board[ny][nx] <= 0)
	{
		return 1;
	}
	return 0;
}

int Engine::PionWCheck(int posx, int posy, int kingx, int kingy)
{
	//std::cout << "ox=" << posx << " oy=" << posy << " kingx=" << kingx << " kingy=" << kingy << "\n\n\n";
	if (board[posy - 1][posx - 1] >= 0)
	{
		if (posy - 1 == kingy && posx - 1 == kingx)
		{
			return 1;
		}
	}
	if (board[posy - 1][posx + 1] >= 0)
	{
		//std::cout << "yy";
		if (posy - 1 == kingy && posx + 1 == kingx)
		{
			return 1;
		}
	}
	return 0;
}

int Engine::RookWCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] >= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGHT; i++) // Right
	{
		if (board[oy][i] >= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGHT; i++) // Down
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int Engine::BishopWCheck(int ox, int oy, int kingx, int kingy)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up Left
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down Left
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // Down Right
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::QueenWCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] >= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGHT; i++) // Right
	{
		if (board[oy][i] >= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGHT; i++) // Down
	{
		if (board[i][ox] >= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up Left
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down Left
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LENGHT; i++)  // Down Right
	{
		if (board[i][j] >= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::KnightWCheck(int ox, int oy, int kingx, int kingy)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && kingy == oy - 2 && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1; // Up Left
	}
	if (oy - 2 >= 0 && ox + 1 < LENGHT && kingy == oy - 2 && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1; // Up Right
	}
	if (oy - 1 >= 0 && ox + 2 < LENGHT && kingy == oy - 1 && kingx == ox + 2 && board[kingy][kingx] >= 0)
	{
		return 1; // RIght 1
	}
	if (oy + 1 >= 0 && ox + 2 < LENGHT && kingy == oy + 1 && kingx == ox + 2 && board[kingy][kingx] >= 0)
	{
		return 1; // Right 2
	}
	if (oy + 2 < LENGHT && ox + 1 < LENGHT && kingy == oy + 2 && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1; // Down 1
	}
	if (oy + 2 < LENGHT && ox - 1 >= 0 && kingy == oy + 2 && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1; // Down 2
	}
	if (oy + 1 < LENGHT && ox - 2 >= 0 && kingy == oy + 1 && kingx == ox - 2 && board[kingy][kingx] >= 0)
	{
		return 1; // Left 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && kingy == oy - 1 && kingx == ox - 2 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	return 0;
}

int Engine::KingWCheck(int ox, int oy, int kingx, int kingy)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && kingy == oy - 1 && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && kingx == ox && kingy == oy - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LENGHT && kingx == ox + 1 && kingy == oy - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGHT && kingy == oy && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGHT && oy + 1 < LENGHT && kingy == oy + 1 && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGHT && kingy == oy + 1 && kingx == ox && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LENGHT && kingx == ox - 1 && kingy == oy + 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && kingy == oy && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	return 0;
}

int Engine::PionBCheck(int ox, int oy, int kingx, int kingy)
{
	if (board[oy + 1][ox - 1] <= 0)
	{
		if (kingy == oy + 1 && kingx == ox - 1)
		{
			return 1;
		}
	}
	if (board[oy + 1][ox + 1] <= 0)
	{
		if (kingy == oy + 1 && kingx == ox + 1)
		{
			return 1;
		}
	}
	return 0;
}

int Engine::RookBCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] <= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGHT; i++) // Right
	{
		if (board[oy][i] <= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGHT; i++) // Down
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	return 0;
}

int Engine::BishopBCheck(int ox, int oy, int kingx, int kingy)
{
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up left
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down left
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i <= 7; i++)  // Down Right
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::QueenBCheck(int ox, int oy, int kingx, int kingy)
{
	for (int i = ox - 1; i >= 0; i--) // Left
	{
		if (board[oy][i] <= 0 && (kingx == i && kingy == oy))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy - 1; i >= 0; i--) // Up
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	for (int i = ox + 1; i < LENGHT; i++) // Right
	{
		if (board[oy][i] <= 0 && (kingy == oy && kingx == i))
		{
			return 1;
		}
		else if (board[oy][i] != 0)
		{
			break;
		}
	}
	for (int i = oy + 1; i < LENGHT; i++) // Down
	{
		if (board[i][ox] <= 0 && (kingy == i && kingx == ox))
		{
			return 1;
		}
		else if (board[i][ox] != 0)
		{
			break;
		}
	}
	int j = ox - 1;
	for (int i = oy - 1; i >= 0; i--) // Up Left
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy - 1; i >= 0; i--) // Up Right
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	j = ox - 1;
	for (int i = oy + 1; i <= 7; i++) // Down Left
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j--;
	}
	j = ox + 1;
	for (int i = oy + 1; i < LENGHT; i++)  // Down Right
	{
		if (board[i][j] <= 0 && (kingy == i && kingx == j))
		{
			return 1;
		}
		else if (board[i][j] != 0)
		{
			break;
		}
		j++;
	}
	return 0;
}

int Engine::KnightBCheck(int ox, int oy, int kingx, int kingy)
{
	if (oy - 2 >= 0 && ox - 1 >= 0 && kingy == oy - 2 && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1; // Up left
	}
	if (oy - 2 >= 0 && ox + 1 < LENGHT && kingy == oy - 2 && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1; // Up Right
	}
	if (oy - 1 >= 0 && ox + 2 < LENGHT && kingy == oy - 1 && kingx == ox + 2 && board[kingy][kingx] <= 0)
	{
		return 1; // Right 1
	}
	if (oy + 1 >= 0 && ox + 2 < LENGHT && kingy == oy + 1 && kingx == ox + 2 && board[kingy][kingx] <= 0)
	{
		return 1; // Right 2
	}
	if (oy + 2 < LENGHT && ox + 1 < LENGHT && kingy == oy + 2 && kingx == ox + 1 && board[kingy][kingx] <= 0)
	{
		return 1; // Down 1
	}
	if (oy + 2 < LENGHT && ox - 1 >= 0 && kingy == oy + 2 && kingx == ox - 1 && board[kingy][kingx] <= 0)
	{
		return 1; // Down 2
	}
	if (oy + 1 < LENGHT && ox - 2 >= 0 && kingy == oy + 1 && kingx == ox - 2 && board[kingy][kingx] <= 0)
	{
		return 1; // Left 1
	}
	if (oy - 1 >= 0 && ox - 2 >= 0 && kingy == oy - 1 && kingx == ox - 2 && board[kingy][kingx] <= 0)
	{
		return 1;
	}
	return 0;
}

int Engine::KingBCheck(int ox, int oy, int kingx, int kingy)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && kingy == oy - 1 && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && kingx == ox && kingy == oy - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy - 1 >= 0 && ox + 1 < LENGHT && kingx == ox + 1 && kingy == oy - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGHT && kingy == oy && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox + 1 < LENGHT && oy + 1 < LENGHT && kingy == oy + 1 && kingx == ox + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (oy + 1 < LENGHT && kingy == oy + 1 && kingx == ox && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && oy + 1 < LENGHT && kingx == ox - 1 && kingy == oy + 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	if (ox - 1 >= 0 && kingy == oy && kingx == ox - 1 && board[kingy][kingx] >= 0)
	{
		return 1;
	}
	return 0;
}

int Engine::CheckForBlackKing(int posKingx, int posKingy)
{
	int ok = 0;
	for (int i = 0; i < LENGHT; i++)
	{
		for (int j = 0; j < LENGHT; j++)
		{
			if (board[i][j] < 0)
			{
				if (board[i][j] == pawnWHITE)
				{
					ok = PionWCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == rookWHITE)
				{
					ok = RookWCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == knightWHITE)
				{
					ok = KnightWCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == bishopWHITE)
				{
					ok = BishopWCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == queenWHITE)
				{
					ok = QueenWCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == kingWHITE)
				{
					ok = KingWCheck(j, i, posKingx, posKingy);
				}
				if (ok == 1)
				{
					std::cout << "szach";
					return 0;
				}
			}
		}
	}
	return 1;
}

int Engine::KingB(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // Up left
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // Up
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LENGHT && nx == ox + 1 && ny == oy - 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // Up right
		}
	}
	if (ox + 1 < LENGHT && ny == oy && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // Right
		}
	}
	if (ox + 1 < LENGHT && oy + 1 < LENGHT && ny == oy + 1 && nx == ox + 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // Down Right
		}
	}
	if (oy + 1 < LENGHT && ny == oy + 1 && nx == ox && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // Down
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LENGHT && nx == ox - 1 && ny == oy + 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // Down left
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] <= 0)
	{
		int ok = CheckForBlackKing(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // Left
		}
	}
	// Go right
	if (RookBlackRight == 0 && KINGBLACK == 0 && board[0][5] == 0 && board[0][6] == 0 && ny == 0 && nx == 6)
	{
		int ok = CheckForBlackKing(4, 0);
		if (ok == 1)
		{
			ok = CheckForBlackKing(5, 0);
			if (ok == 1)
			{
				ok = CheckForBlackKing(6, 0);
				if (ok == 1)
				{
					KINGBLACK = 1;
					RookBlackRight = 1;
					board[0][7] = 0;
					board[0][5] = rookBLACK;
					return 1;
				}
			}
		}
	}
	if (RookBlackLeft == 0 && KINGBLACK == 0 && board[0][3] == 0 && board[0][2] == 0 && board[0][1] == 0 && ny == 0 && nx == 2)
	{
		int ok = CheckForBlackKing(4, 0);
		if (ok == 1)
		{
			ok = CheckForBlackKing(3, 0);
			if (ok == 1)
			{
				ok = CheckForBlackKing(2, 0);
				if (ok == 1)
				{
					ok = CheckForBlackKing(1, 0);
					if (ok == 1)
					{
						KINGBLACK = 1;
						RookBlackLeft = 1;
						board[0][0] = 0;
						board[0][3] = rookBLACK;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int Engine::CheckForWhiteKing(int posKingx, int posKingy)
{
	int ok = 0;
	for (int i = 0; i < LENGHT; i++)
	{
		for (int j = 0; j < LENGHT; j++)
		{
			if (board[i][j] > 0)
			{
				if (board[i][j] == pawnBLACK)
				{
					ok = PionBCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == rookBLACK)
				{
					ok = RookBCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == knightBLACK)
				{
					ok = KnightBCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == bishopBLACK)
				{
					ok = BishopBCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == queenBLACK)
				{
					ok = QueenBCheck(j, i, posKingx, posKingy);
				}
				if (board[i][j] == kingBLACK)
				{
					ok = KingBCheck(j, i, posKingx, posKingy);
				}
				if (ok == 1)
				{
						/*std::cout << "da" << "\n";*/
					return 0;
				}
			}
		}
	}
	return 1;
}

int Engine::KingW(int ox, int oy, int nx, int ny)
{
	if (ox - 1 >= 0 && oy - 1 >= 0 && ny == oy - 1 && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox - 1, oy - 1);
		if (ok == 1)
		{
			return 1;  // Up Left
		}
	}
	if (oy - 1 >= 0 && nx == ox && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox, oy - 1);
		if (ok == 1)
		{
			return 1; // Up
		}
	}
	if (oy - 1 >= 0 && ox + 1 < LENGHT && nx == ox + 1 && ny == oy - 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox + 1, oy - 1);
		if (ok == 1)
		{
			return 1; // Right Up
		}
	}
	if (ox + 1 < LENGHT && ny == oy && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox + 1, oy);
		if (ok == 1)
		{
			return 1; // Right
		}
	}
	if (ox + 1 < LENGHT && oy + 1 < LENGHT && ny == oy + 1 && nx == ox + 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox + 1, oy + 1);
		if (ok == 1)
		{
			return 1; // Down Right
		}
	}
	if (oy + 1 < LENGHT && ny == oy + 1 && nx == ox && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox, oy + 1);
		if (ok == 1)
		{
			return 1; // Down
		}
	}
	if (ox - 1 >= 0 && oy + 1 < LENGHT && nx == ox - 1 && ny == oy + 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox - 1, oy + 1);
		if (ok == 1)
		{
			return 1; // Down Left
		}
	}
	if (ox - 1 >= 0 && ny == oy && nx == ox - 1 && board[ny][nx] >= 0)
	{
		int ok = CheckForWhiteKing(ox - 1, oy);
		if (ok == 1)
		{
			return 1; // Left
		}
	}
	// go right
	if (KINGWHITE == 0 && RookWhiteRight == 0 && board[7][5] == 0 && board[7][6] == 0 && ny == 7 && nx == 6)
	{
		int ok = 1;
		ok = CheckForWhiteKing(4, 7);
		if (ok == 1)
		{
			ok = CheckForWhiteKing(5, 7);
			if (ok == 1)
			{
				ok = CheckForWhiteKing(6, 7);
				if (ok == 1)
				{
					board[7][7] = 0;
					board[7][5] = rookWHITE;
					KINGWHITE = 1;
					RookWhiteRight = 1;
					return 1;
				}
			}
		}
	}
	// go left
	if (KINGWHITE == 0 && RookWhiteRight == 0 && board[7][3] == 0 && board[7][2] == 0 && board[7][1] == 0 && ny == 7 && nx == 2)
	{
		int ok = 1;
		ok = CheckForWhiteKing(4, 7);
		if (ok == 1)
		{
			ok = CheckForWhiteKing(3, 7);
			if (ok == 1)
			{
				ok = CheckForWhiteKing(2, 7);
				if (ok == 1)
				{
					ok = CheckForWhiteKing(1, 7);
					if (ok == 1)
					{
						board[7][0] = 0;
						board[7][3] = rookWHITE;
						KINGWHITE = 1;
						RookWhiteLeft = 1;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void Engine::pozKingWhite()
{
	for (int i = 0; i < LENGHT; i++)
	{
		for (int j = 0; j < LENGHT; j++)
		{
			if (board[i][j] == kingWHITE)
			{
				KingWhite.x = j;
				KingWhite.y = i;
				break;
			}
		}
	}
}

void Engine::pozKingBlack()
{
	for (int i = 0; i < LENGHT; i++)
	{
		for (int j = 0; j < LENGHT; j++)
		{
			if (board[i][j] == kingBLACK)
			{
				KingBlack.y = i;
				KingBlack.x = j;
				break;
			}
		}
	}
}



Engine::Engine(RenderWindow& win)
{
	window = &win;

}


Engine::~Engine()
{
}
void Engine::runEngine()
{


	Texture t1, t2, t3, t4, t5, t6, t7, t8, t9, t10, t11, t12, t13, t14, t15;
	t1.loadFromFile("images/board1.png");
	t2.loadFromFile("images/blackpawn.png");
	t3.loadFromFile("images/whitepawn.png");
	t4.loadFromFile("images/blackrook.png");
	t5.loadFromFile("images/whiterook.png");
	t6.loadFromFile("images/whiteknight.png");
	t7.loadFromFile("images/blackknight.png");
	t8.loadFromFile("images/blackbishop.png");
	t9.loadFromFile("images/whitebishop.png");
	t10.loadFromFile("images/whitequeen.png");
	t11.loadFromFile("images/blackqueen.png");
	t12.loadFromFile("images/blackking.png");
	t13.loadFromFile("images/whiteking.png");
	t14.loadFromFile("images/whitetransform.png");
	t15.loadFromFile("images/blacktransform.png");

	Sprite chessboard(t1);
	Sprite PawnBlack(t2);
	Sprite PawnWhite(t3);
	Sprite RookBlack(t4);
	Sprite RookWhite(t5);
	Sprite KnightWhite(t6);
	Sprite KnightBlack(t7);
	Sprite BishopBlack(t8);
	Sprite BishopWhite(t9);
	Sprite QueenWhite(t10);
	Sprite QueenBlack(t11);
	Sprite BlackKing(t12);
	Sprite WhiteKing(t13);
	Sprite Moving;
	Sprite WhiteTransform(t14);
	Sprite BlackTransform(t15);


	float dx = 0, dy = 0;
	int numberMovingPiece = 0;

	while (window->isOpen())
	{
		Vector2i pos(Mouse::getPosition(*window));
		x = pos.x / size;
		y = pos.y / size;
		Event e;
		while (window->pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				window->close();
			}
			window->clear();
			if (e.type == Event::MouseButtonPressed)
			{
				if (e.key.code == Mouse::Left)
				{
					/*std::cout << "x=" << x << " y=" << y << "\n";
					std::cout << "pos_x=" << pos.x << " pos_y=" << pos.y << "\n";
					std::cout << "board[y][x]=" << board[y][x] << "\n";
					std::cout << "\n";*/
					if (TransformWhite == 1)
					{
						if (pos.y >= transformWhite.y * size && pos.y <= (transformWhite.y + 1) * size && pos.x >= transformWhite.x * size && pos.x <= (transformWhite.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transformWhite.y][transformWhite.x] = rookWHITE;
								TransformWhite = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transformWhite.y][transformWhite.x] = queenWHITE;
								TransformWhite = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transformWhite.y][transformWhite.x] = knightWHITE;
								TransformWhite = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transformWhite.y][transformWhite.x] = bishopWHITE;
								TransformWhite = 0;
							}
							if (TransformWhite == 0)
							{
								pozKingBlack();
								int h = CheckForBlackKing(KingBlack.x, KingBlack.y);
								if (h == 0)
								{
									CheckBlack = 1;
								}
							}
						}
					}
					if (TransformBlack == 1)
					{
						if (pos.y >= transformBlack.y * size && pos.y <= (transformBlack.y + 1) * size && pos.x >= transformBlack.x * size && pos.x <= (transformBlack.x + 1) * size)
						{
							int xx = pos.x % 100, yy = pos.y % 100;
							//std::cout << "pos.y=" << yy << "\n";
							//std::cout << "pos.x=" << xx << "\n";
							if (xx < 50 && yy < 50 && xx > 0 && yy > 0)
							{
								board[transformBlack.y][transformBlack.x] = rookBLACK;
								TransformBlack = 0;
							}
							if (xx > 50 && xx < 100 && yy < 50 && yy > 0)
							{
								board[transformBlack.y][transformBlack.x] = queenBLACK;
								TransformBlack = 0;
							}
							if (xx > 50 && xx < 100 && yy>50 && yy < 100)
							{
								board[transformBlack.y][transformBlack.x] = knightBLACK;
								TransformBlack = 0;
							}
							if (xx < 50 && xx>0 && yy > 50 && y < 100)
							{
								board[transformBlack.y][transformBlack.x] = bishopBLACK;
								TransformBlack = 0;
							}
							if (TransformBlack == 0)
							{
								pozKingWhite();
								int h = CheckForWhiteKing(KingWhite.x, KingWhite.y);
								if (h == 0)
								{
									CheckWhite = 1;
								}
							}
						}
					}
					if (board[y][x] != 0)
					{
						dx = pos.x - x * 100;
						dy = pos.y - y * 100;
						if (board[y][x] == pawnBLACK && moving == 1)
						{
							numberMovingPiece = pawnBLACK;
							Moving = PawnBlack;
							board[y][x] = 0;
						}
						if (board[y][x] == pawnWHITE && moving == 0)
						{
							numberMovingPiece = pawnWHITE;
							Moving = PawnWhite;
							board[y][x] = 0;
						}
						if (board[y][x] == rookBLACK && moving == 1)
						{
							numberMovingPiece = rookBLACK;
							Moving = RookBlack;
							board[y][x] = 0;

						}
						if (board[y][x] == rookWHITE && moving == 0)
						{
							numberMovingPiece = rookWHITE;
							Moving = RookWhite;
							board[y][x] = 0;

						}
						if (board[y][x] == knightWHITE && moving == 0)
						{
							numberMovingPiece = knightWHITE;
							Moving = KnightWhite;
							board[y][x] = 0;
						}
						if (board[y][x] == knightBLACK && moving == 1)
						{
							numberMovingPiece = knightBLACK;
							Moving = KnightBlack;
							board[y][x] = 0;
						}
						if (board[y][x] == bishopBLACK && moving == 1)
						{
							numberMovingPiece = bishopBLACK;
							Moving = BishopBlack;
							board[y][x] = 0;
						}
						if (board[y][x] == bishopWHITE && moving == 0)
						{
							numberMovingPiece = bishopWHITE;
							Moving = BishopWhite;
							board[y][x] = 0;
						}
						if (board[y][x] == queenWHITE && moving == 0)
						{
							numberMovingPiece = queenWHITE;
							Moving = QueenWhite;
							board[y][x] = 0;
						}
						if (board[y][x] == queenBLACK && moving == 1)
						{
							numberMovingPiece = queenBLACK;
							Moving = QueenBlack;
							board[y][x] = 0;
						}
						if (board[y][x] == kingBLACK && moving == 1)
						{
							numberMovingPiece = kingBLACK;
							Moving = BlackKing;
							board[y][x] = 0;
						}
						if (board[y][x] == kingWHITE && moving == 0)
						{
							numberMovingPiece = kingWHITE;
							Moving = WhiteKing;
							board[y][x] = 0;
						}
						if (board[y][x] == 0)
						{
							move = 1;
							oldPoz.x = x;
							oldPoz.y = y;
						}
					}
				}
			}


			if (e.type == Event::MouseButtonReleased)
			{
				if (e.key.code == Mouse::Left)
				{
					int ok = 2;
					if (numberMovingPiece == pawnWHITE && move == 1)
					{
						ok = PawnW(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == pawnBLACK && move == 1)
					{
						ok = PawnB(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == rookWHITE && move == 1)
					{
						ok = RookW(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && RookWhiteLeft == 0 && oldPoz.y == 7 && oldPoz.x == 0)
						{
							RookWhiteLeft = 1;
							//std::cout << RookWhiteLeft << "\n";
						}
						if (ok == 1 && RookWhiteRight == 0 && oldPoz.y == 7 && oldPoz.x == 7)
						{
							RookWhiteRight = 1;
							//std::cout << RookWhiteRight << "\n";
						}
					}
					if (numberMovingPiece == rookBLACK && move == 1)
					{
						ok = RookB(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && RookBlackRight == 0 && oldPoz.y == 0 && oldPoz.x == 7)
						{
							RookBlackRight = 1;
							//std::cout << RookBlackRight<< "\n";
						}
						if (ok == 1 && RookBlackLeft == 0 && oldPoz.y == 0 && oldPoz.x == 0)
						{
							RookBlackLeft = 1;
							//std::cout << RookBlackLeft << "\n";
						}
					}
					if (numberMovingPiece == bishopWHITE && move == 1)
					{
						ok = BishopW(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == bishopBLACK && move == 1)
					{
						ok = BishopB(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == queenWHITE && move == 1)
					{
						ok = QueenW(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == queenBLACK && move == 1)
					{
						ok = QueenB(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == knightWHITE && move == 1)
					{
						ok = KnightW(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == knightBLACK && move == 1)
					{
						ok = KnightB(oldPoz.x, oldPoz.y, x, y);
					}
					if (numberMovingPiece == kingBLACK && move == 1)
					{
						ok = KingB(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && KINGBLACK == 0)
						{
							KINGBLACK = 1;
							//	std::cout << KINGBLACK << "\n";
						}
					}
					if (numberMovingPiece == kingWHITE && move == 1)
					{
						ok = KingW(oldPoz.x, oldPoz.y, x, y);
						if (ok == 1 && KINGWHITE == 0)
						{
							KINGWHITE = 1;
							//std::cout << "primaMutareREGEalb=" << KINGWHITE << "\n";
						}
					}
					if (ok == 1)
					{
						int nr = board[y][x];
						board[y][x] = numberMovingPiece;
						if (y == 0 && numberMovingPiece == pawnWHITE)
						{
							TransformWhite = 1;
							transformWhite.x = x;
							transformWhite.y = y;
							board[y][x] = 0;
						}
						if (y == 7 && numberMovingPiece == pawnBLACK)
						{
							TransformBlack = 1;
							transformBlack.x = x;
							transformBlack.y = y;
							board[y][x] = 0;
						}
						if (moving == 0) // white moved, black follows
						{
							if (CheckWhite == 1)
							{
								pozKingWhite();
								int s = CheckForWhiteKing(KingWhite.x, KingWhite.y);
								if (s == 0)
								{
									board[oldPoz.y][oldPoz.x] = numberMovingPiece;
									board[y][x] = nr;
								}
								else
								{
									CheckWhite = 0;
									pozKingBlack();
									int sah = CheckForBlackKing(KingBlack.x, KingBlack.y);
									if (sah == 0)
									{
										CheckBlack = 1;
									}
									moving = 1;
								}
							}
							else
							{
								pozKingWhite();
								int sa = CheckForWhiteKing(KingWhite.x, KingWhite.y);
								if (sa == 0)
								{
									board[oldPoz.y][oldPoz.x] = numberMovingPiece;
									board[y][x] = nr;
								}
								else
								{
									pozKingBlack();
									int sah = CheckForBlackKing(KingBlack.x, KingBlack.y);
									if (sah == 0)
									{
										CheckBlack = 1;
									}
									moving = 1;
								}
							}
						}
						else // black moved, white follows
						{
							if (CheckBlack == 1)
							{
								pozKingBlack();
								int s = CheckForBlackKing(KingBlack.x, KingBlack.y);
								if (s == 0)
								{
									board[oldPoz.y][oldPoz.x] = numberMovingPiece;
									board[y][x] = nr;
								}
								else
								{
									CheckBlack = 0;
									pozKingWhite();
									int sah = CheckForWhiteKing(KingWhite.x, KingWhite.y);
									if (sah == 0)
									{
										CheckWhite = 1;
									}
									moving = 0;
								}
							}
							else
							{
								pozKingBlack();
								int sa = CheckForBlackKing(KingBlack.x, KingBlack.y);
								if (sa == 0)
								{
									board[oldPoz.y][oldPoz.x] = numberMovingPiece;
									board[y][x] = nr;
								}
								else
								{
									pozKingWhite();
									int sah = CheckForWhiteKing(KingWhite.x, KingWhite.y);
									if (sah == 0)
									{
										CheckWhite = 1;
									}
									moving = 0;
								}
							}
						}
					}
					else if (ok == 0)
					{
						board[oldPoz.y][oldPoz.x] = numberMovingPiece;
					}
					move = 0;
				}
			}
		}

		// display //
		window->clear();
		window->draw(chessboard);
		if (TransformWhite == 1)
		{
			WhiteTransform.setPosition(transformWhite.x * size, transformWhite.y * size);
			window->draw(WhiteTransform);
		}
		if (TransformBlack == 1)
		{
			BlackTransform.setPosition(transformBlack.x * size, transformBlack.y * size);
			window->draw(BlackTransform);
		}
		if (move == 1)
		{
			Moving.setPosition(pos.x - dx, pos.y - dy);
			window->draw(Moving);
		}
		for (int i = 0; i < LENGHT; i++)
		{
			for (int j = 0; j < LENGHT; j++)
			{

				if (board[i][j] != 0)
				{
					if (board[i][j] == pawnBLACK)
					{
						PawnBlack.setPosition(j * size, i * size);
						window->draw(PawnBlack);
					}
					if (board[i][j] == pawnWHITE)
					{
						PawnWhite.setPosition(j * size, i * size);
						window->draw(PawnWhite);
					}
					if (board[i][j] == rookBLACK)
					{
						RookBlack.setPosition(j * size, i * size);
						window->draw(RookBlack);

					}
					if (board[i][j] == rookWHITE)
					{
						RookWhite.setPosition(j * size, i * size);
						window->draw(RookWhite);

					}
					if (board[i][j] == knightWHITE)
					{
						KnightWhite.setPosition(j * size, i * size);
						window->draw(KnightWhite);
					}
					if (board[i][j] == knightBLACK)
					{
						KnightBlack.setPosition(j * size, i * size);
						window->draw(KnightBlack);
					}
					if (board[i][j] == bishopBLACK)
					{
						BishopBlack.setPosition(j * size, i * size);
						window->draw(BishopBlack);
					}
					if (board[i][j] == bishopWHITE)
					{
						BishopWhite.setPosition(j * size, i * size);
						window->draw(BishopWhite);
					}
					if (board[i][j] == queenWHITE)
					{
						QueenWhite.setPosition(j * size, i * size);
						window->draw(QueenWhite);
					}
					if (board[i][j] == queenBLACK)
					{
						QueenBlack.setPosition(j * size, i * size);
						window->draw(QueenBlack);
					}
					if (board[i][j] == kingBLACK)
					{
						BlackKing.setPosition(j * size, i * size);
						window->draw(BlackKing);
					}
					if (board[i][j] == kingWHITE)
					{
						WhiteKing.setPosition(j * size, i * size);
						window->draw(WhiteKing);
					}
				}
			}
		}
		window->display();
	}

}