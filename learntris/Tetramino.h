#pragma once

class TetrisGame;

class Tetramino
{
public:
	Tetramino();
	~Tetramino();

	enum TetType { Itet, Otet, Ztet, Stet, Ltet, Jtet, Ttet };
	typedef std::array<int, 4*4> ShapeGrid;

	//TetType GetTetType() const;
	int GetShapeDataAtPosition(int Row, int Col) const;
	int GetShapeSize() const;
	//void GetPosition(int &OutRow, int &OutCol);

	// sets the tetramino type and resets to the starting position
	void SetTetType(TetType type);
	bool TryRotateRight(TetrisGame* TheGame); // clockwise
	bool TryRotateLeft(); // counter-clockwise


private:
	TetType TType;
	ShapeGrid ShapeData;
	int ShapeSize;

	// position of the upper left corner of the shape matrix
	int RowPos; 
	int ColPos;

	TetrisGame* CurrentGame;

	static const ShapeGrid IInitialShapeData;
	static const ShapeGrid OInitialShapeData;
	static const ShapeGrid ZInitialShapeData;
	static const ShapeGrid SInitialShapeData;
	static const ShapeGrid LInitialShapeData;
	static const ShapeGrid JInitialShapeData;
	static const ShapeGrid TInitialShapeData;
};

