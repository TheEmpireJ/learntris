/* This class handles all game state */

#pragma once
class TetrisGame
{
public:
	TetrisGame();
	~TetrisGame();

	// holds various static variables
	enum Vars
	{
		Cols = 10,
		Rows = 22
	};

	enum BlockColors {Black = 0, Blue, Cyan, Green, Magenta, Orange, Red, Yellow};

	// used to return a pointer to a two dimentional array from a function
	typedef int(*GameGrid)[Cols]; // TODO is there a better way to do this??

	int GetScore() const;
	int GetRowsCleared() const;
	GameGrid GetBoardState();

	void ClearBoardState();
	void SetBoardStateAtPosition(int Col, int Row, int Data);

private:

	int GameGridData[Rows][Cols] = { { 0 } };
	int Score = 0;
	int RowsCleared = 0;
};

