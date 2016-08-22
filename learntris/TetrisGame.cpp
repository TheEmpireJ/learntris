#include "stdafx.h"
#include "TetrisGame.h"


TetrisGame::TetrisGame()
{
	//GameGrid[10][22] = { 0 };
}


TetrisGame::~TetrisGame()
{
}

int TetrisGame::GetScore() const { return Score; }
int TetrisGame::GetRowsCleared() const { return RowsCleared; }

 TetrisGame::GameGrid TetrisGame::GetBoardState()
{
	return GameGridData;
}

void TetrisGame::ClearBoardState()
{
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
		{
			GameGridData[r][c] = Black;
		}
	}
}

void TetrisGame::SetBoardStateAtPosition(int Col, int Row, int Data)
{
	GameGridData[Col][Row] = Data; // TODO add validation
}


