#include "stdafx.h"
#include "TetrisGame.h"


TetrisGame::TetrisGame()
{
	//GameGrid[10][22] = { 0 };
}


TetrisGame::~TetrisGame()
{
}

void TetrisGame::PrintGameState() const
{
	for (int r = 0; r < Rows; r++) {
		for (int c = 0; c < Cols; c++)
		{
			switch (GameGrid[r][c])
			{
			case Blue:
				std::cout << "b ";
			case Cyan:
				std::cout << "c ";
			case Green:
				std::cout << "g ";
			case Magenta:
				std::cout << "m ";
			case Orange:
				std::cout << "o ";
			case Red:
				std::cout << "r ";
			case Yellow:
				std::cout << "y ";
			case Black:
				std::cout << ". "; // represents blank space
			}
		}
		std::cout << std::endl;
	}
}

void TetrisGame::ReadGameStateFromInput()
{
	//TODO test for invalid inputs

}
