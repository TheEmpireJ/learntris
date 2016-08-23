#pragma once

// forward declarations
class TetrisGame;
class Tetramino;

class TetrisDisplayManager
{
public:
	TetrisDisplayManager();
	~TetrisDisplayManager();

	// Point this instance to the objects it needs to know about.
	void PrintBoardState(TetrisGame* TheGame) const;
	void PrintScore(TetrisGame* TheGame) const;
	void PrintRowsCleared(TetrisGame* TheGame) const;

private:
};

