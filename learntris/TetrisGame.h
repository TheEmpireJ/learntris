#pragma once
#include <array>
#include "Tetramino.h"

// forward declarations
// class Tetramino; // this is not enough here...

/* This class handles all game state */
class TetrisGame
{
public:
	TetrisGame();
	~TetrisGame();

	// holds various static variables
	enum Vars
	{
		Cols = 10,
		Rows = 22,
		OneRowScore = 100,
		TwoRowsScore = 220,
		ThreeRowsScore = 450,
		FourRowsScore = 800
	};

	enum BlockColor {Blank = 0, Blue, Cyan, Green, Magenta, Orange, Red, Yellow}; // TODO change to enum class?

	typedef std::array<int, Rows * Cols> GameGrid; // for easier reading

	int GetScore() const;
	int GetRowsCleared() const;
	int GetBoardStateAtPosition(int Row, int Col) const;
	GameGrid* GetBoardState(); // TODO this is probably dangerous and uneccessary.

	void ClearBoardState();
	void SetBoardStateAtPosition(int Row, int Col, int Data);

	// checks for completed rows and updates the score and rows cleared
	void Simulate();

private:

	GameGrid GameGridData = {0};
	 /*{ 
		0,0,0,0,0,0,0,0,0,0,
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		Green,Green,Green,Green,Green,Green,Green,Green,Green,Green,
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0, 
		0,0,0,0,0,0,0,0,0,0
	}; // */

	Tetramino CurrentTetramino;

	int Score = 0;
	int RowsCleared = 0;

	bool IsRowFull(int Row) const;
	void ClearRow(int Row);
};

