#include "stdafx.h"
#include "TetrisGame.h"


TetrisGame::TetrisGame()
{
	//GameGrid[10][22] = { 0 };
}


TetrisGame::~TetrisGame()
{
}

int TetrisGame::GetScore() const
{
	return Score;
}

void TetrisGame::PrintGameState() const
{
	for (int r = 0; r < Rows; r++) 
	{
		for (int c = 0; c < Cols; c++)
		{
			switch (GameGrid[r][c])
			{
			case Blue:
				std::cout << "b ";
				break;
			case Cyan:
				std::cout << "c ";
				break;
			case Green:
				std::cout << "g ";
				break;
			case Magenta:
				std::cout << "m ";
				break;
			case Orange:
				std::cout << "o ";
				break;
			case Red:
				std::cout << "r ";
				break;
			case Yellow:
				std::cout << "y ";
				break;
			case Black:
				std::cout << ". "; // represents blank space
				break;
			default:
				break;
				// TODO why is there bad data?
			}
		}
		std::cout << std::endl;
	}
}

void TetrisGame::Reset()
{
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
		{
			GameGrid[r][c] = Black;
		}
	}
}

void TetrisGame::ReadGameStateFromInput()
{
	//TODO test for invalid inputs
	std::string input;

	for (int r = 0; r < Rows; r++)
	{
		std::getline(std::cin, input);
		for (int c = 0; c < Cols; c++)
		{
			switch (input[c * 2]) // c * 2 accounts for spaces
			{
			case '.':
				GameGrid[r][c] = Black;
				break;
			case 'b':
				GameGrid[r][c] = Blue;
				break;
			case 'c':
				GameGrid[r][c] = Cyan;
				break;
			case 'g':
				GameGrid[r][c] = Green;
				break;
			case 'm':
				GameGrid[r][c] = Magenta;
				break;
			case 'o':
				GameGrid[r][c] = Orange;
				break;
			case 'r':
				GameGrid[r][c] = Red;
				break;
			case 'y':
				GameGrid[r][c] = Yellow;
				break;
			default:
				GameGrid[r][c] = -1; // error case
				break;
			}
		}
	}// */
}

