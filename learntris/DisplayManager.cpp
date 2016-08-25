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


void TetrisDisplayManager::PrintBoardState(TetrisGame* TheGame, Tetramino* Tet) const
{
	if (!TheGame) { return; } // pointer protection. must have a game to display!

	for (int r = 0; r < TetrisGame::Rows; r++)
	{
		for (int c = 0; c < TetrisGame::Cols; c++)
		{
			if (Tet) // if the tetramino was passed in, see if we need to print a tetramino at this position
			{
				int TetRow, TetCol, TetSize;
				Tet->GetPosition(TetRow, TetCol);
				TetSize = Tet->GetShapeSize();

				if (c >= TetCol && c < (TetCol + TetSize) && r >= TetRow && r < (TetRow + TetSize)) // if we're in the tetramino's position
				{
					switch (Tet->GetShapeDataAtPosition(r - TetRow, c - TetCol)) // TODO make this pretty (add function?)
					{
					case TetrisGame::Blue:
						std::cout << "B ";
						continue;
					case TetrisGame::Cyan:
						std::cout << "C ";
						continue;
					case TetrisGame::Green:
						std::cout << "G ";
						continue;
					case TetrisGame::Magenta:
						std::cout << "M ";
						continue;
					case TetrisGame::Orange:
						std::cout << "O ";
						continue;
					case TetrisGame::Red:
						std::cout << "R ";
						continue;
					case TetrisGame::Yellow:
						std::cout << "Y ";
						continue;
					case TetrisGame::Blank:
						std::cout << ". "; // represents blank space
						continue;
					default:
						std::cout << "? "; // bad data??
						continue;
						// TODO why is there bad data?
					}
				}
			}

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

void TetrisDisplayManager::PrintCurrentTetramino(Tetramino* Tet)
{
	if (!Tet) { return; }
	int size = Tet->GetShapeSize();

	for (int r = 0; r < size; r++)
	{
		for (int c = 0; c < size; c++)
		{
			switch (Tet->GetShapeDataAtPosition(r,c))
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
