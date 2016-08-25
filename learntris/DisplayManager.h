#pragma once

class TetrisGame;
class Tetramino;

class TetrisDisplayManager
{
public:
	TetrisDisplayManager();
	~TetrisDisplayManager();

	void PrintBoardState(TetrisGame* TheGame, Tetramino* Tet = nullptr) const;
	void PrintScore(TetrisGame* TheGame) const;
	void PrintRowsCleared(TetrisGame* TheGame) const;
	void PrintCurrentTetramino(Tetramino* Tet);

private:
};

