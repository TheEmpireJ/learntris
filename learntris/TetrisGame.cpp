#include "stdafx.h"
#include "TetrisGame.h"


TetrisGame::TetrisGame()
{
	//GameGridData = { {0,0,0,0,0,0,0,0,0,0} };
}


TetrisGame::~TetrisGame()
{
}

int TetrisGame::GetScore() const { return Score; }
int TetrisGame::GetRowsCleared() const { return RowsCleared; }

int TetrisGame::GetBoardStateAtPosition(int Row, int Col) const
{
	return GameGridData[Row*Cols + Col];
}

TetrisGame::GameGrid* TetrisGame::GetBoardState()
{
	return &GameGridData;
}

void TetrisGame::ClearBoardState()
{
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
		{
			GameGridData[r * Cols + c] = Blank;
		}
	}
}

void TetrisGame::SetBoardStateAtPosition(int Row, int Col, int Data)
{
	GameGridData[Row*Cols + Col] = Data; // TODO add validation
}

void TetrisGame::Simulate()
{
	// loop though all rows
	for (int r = 0; r < Rows; r++)
	{
		// if row is full
		if (IsRowFull(r))
		{
			RowsCleared++;
			Score += OneRowScore;
			ClearRow(r);
		}
	}
}

bool TetrisGame::IsRowFull(int Row) const
{
	bool RowFull = true;

	for (int c = 0; c < Cols; c++)
	{
		if (GameGridData[Row*Cols + c] == Blank)
		{
			RowFull = false;
			break;
		}
	}
	return RowFull;
}

void TetrisGame::ClearRow(int Row)
{
	// TODO make higher rows drop down here as well?
	for (int c = 0; c < Cols; c++)
	{
		GameGridData[Row*Cols + c] = Blank;
	}
	return;
}


