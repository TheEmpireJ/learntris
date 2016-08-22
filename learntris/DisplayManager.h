#pragma once

// forward declarations
class TetrisGame;

class TetrisDisplayManager
{
public:
	TetrisDisplayManager();
	~TetrisDisplayManager();

	// Point this instance to the objects it needs to know about.
	void Initialize(TetrisGame* TheGame);
	void PrintBoardState() const;
	void PrintScore() const;
	void PrintRowsCleared() const;

private:
	TetrisGame* pAttachedGame = nullptr;
};

