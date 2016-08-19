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

	void PrintGameState() const;

	void ReadGameStateFromInput();

private:

	int GameGrid[Rows][Cols] = { { 0 } };
};

