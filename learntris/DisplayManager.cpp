#include "stdafx.h"
#include "DisplayManager.h"


TetrisDisplayManager::TetrisDisplayManager()
{
}


TetrisDisplayManager::~TetrisDisplayManager()
{
}

// Point this instance to the objects it needs to know about.
void TetrisDisplayManager::Initialize(TetrisGame * TheGame)
{
	pAttachedGame = TheGame;
}

void TetrisDisplayManager::PrintBoardState() const
{
	if (!pAttachedGame) { return; } // pointer protection. must have a game to display!

	TetrisGame::GameGrid GameGrid = pAttachedGame->GetBoardState();

	for (int r = 0; r < TetrisGame::Rows; r++)
	{
		for (int c = 0; c < TetrisGame::Cols; c++)
		{
			switch (GameGrid[r][c])
			{
			case TetrisGame::Blue:
				std::cout << "b ";
				break;
			case TetrisGame::Cyan:
				std::cout << "c ";
				break;
			case TetrisGame::Green:
				std::cout << "g ";
				break;
			case TetrisGame::Magenta:
				std::cout << "m ";
				break;
			case TetrisGame::Orange:
				std::cout << "o ";
				break;
			case TetrisGame::Red:
				std::cout << "r ";
				break;
			case TetrisGame::Yellow:
				std::cout << "y ";
				break;
			case TetrisGame::Black:
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

void TetrisDisplayManager::PrintScore() const
{
	if (!pAttachedGame) { return; }
	std::cout << pAttachedGame->GetScore() << std::endl;
}

void TetrisDisplayManager::PrintRowsCleared() const
{
	if (!pAttachedGame) { return; }
	std::cout << pAttachedGame->GetRowsCleared() << std::endl;
}
