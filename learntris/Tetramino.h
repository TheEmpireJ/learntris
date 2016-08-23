#pragma once
#include<array>

class TetrisGame; // this is not enough?

class Tetramino
{
public:
	Tetramino();
	~Tetramino();

	enum TetType { Itet, Otet, Ztet, Stet, Ltet, Jtet, Ttet };
	typedef std::array<int, 4*4> ShapeGrid;

	TetType GetTetType() const;
	int GetShapeDataAtPosition() const;
	void GetPosition(int &OutRow, int &OutCol);

	// sets the tetramino type and resets to the starting position
	void SetTetType(TetType type);


private:
	TetType TType;
	ShapeGrid ShapeData;
	int ShapeSize;

	// position of the upper left corner of the shape matrix
	int RowPos; 
	int ColPos;

	TetrisGame* CurrentGame;

	static const ShapeGrid IInitialShapeData;
};

