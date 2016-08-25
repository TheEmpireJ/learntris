#include "stdafx.h"
#include "DisplayManager.h"
#include "Tetramino.h"
#include "TetrisGame.h"

TetrisDisplayManager::TetrisDisplayManager()
{
}


TetrisDisplayManager::~TetrisDisplayManager()
{
}


void TetrisDisplayManager::PrintBoardState(TetrisGame* TheGame) const
{
	if (!TheGame) { return; } // pointer protection. must have a game to display!

	for (int r = 0; r < TetrisGame::Rows; r++)
	{
		for (int c = 0; c < TetrisGame::Cols; c++)
		{
			switch (TheGame->GetBoardStateAtPosition(r,c))
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
			case TetrisGame::Blank:
				std::cout << ". "; // represents blank space
				break;
			default:
				std::cout << "? "; // bad data??
				break;
				// TODO why is there bad data?
			}
		}
		std::cout << std::endl;
	}
}

void TetrisDisplayManager::PrintScore(TetrisGame* TheGame) const
{
	if (!TheGame) { return; }
	std::cout << TheGame->GetScore() << std::endl;
}

void TetrisDisplayManager::PrintRowsCleared(TetrisGame* TheGame) const
{
	if (!TheGame) { return; }
	std::cout << TheGame->GetRowsCleared() << std::endl;
}

void TetrisDisplayManager::PrintCurrentTetramino(Tetramino* CurrentTetramino)
{
	if (!CurrentTetramino) { return; }
	int size = CurrentTetramino->GetShapeSize();

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			switch (CurrentTetramino->GetShapeDataAtPosition(r,c))
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
			case TetrisGame::Blank:
				std::cout << ". "; // represents blank space
				break;
			default:
				std::cout << "? "; // bad data??
				break;
				// TODO why is there bad data?
			}
		}
		std::cout << std::endl;
	}
}
