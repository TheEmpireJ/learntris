#pragma once

class TetrisGame;

class Tetramino
{
public:
	Tetramino();
	~Tetramino();

	enum TetType { Itet, Otet, Ztet, Stet, Ltet, Jtet, Ttet, NOTet };
	typedef std::array<int, 4*4> ShapeGrid;

	//TetType GetTetType() const;
	int GetShapeDataAtPosition(int Row, int Col) const;
	int GetShapeSize() const;
	void GetPosition(int &OutRow, int &OutCol);

	// sets the tetramino type and resets to the starting position
	void SetTetType(TetType type);

	// move and rotate functions! they can fail
	bool TryMoveLeft(TetrisGame* TheGame);
	bool TryMoveRight(TetrisGame* TheGame);
	bool TryMoveDown(TetrisGame* TheGame);

	bool TryRotateRight(TetrisGame* TheGame); // clockwise
	bool TryRotateLeft(TetrisGame* TheGame); // counter-clockwise


private:
	TetType TType;
	ShapeGrid ShapeData;
	int ShapeSize;

	// position of the upper left corner of the shape matrix
	int RowPos; 
	int ColPos;

	// min and max extents of the shape based on how it is currently rotated
	int MinRow, MaxRow, MinCol, MaxCol;

	void FindExtents();


	static const ShapeGrid IInitialShapeData;
	static const ShapeGrid OInitialShapeData;
	static const ShapeGrid ZInitialShapeData;
	static const ShapeGrid SInitialShapeData;
	static const ShapeGrid LInitialShapeData;
	static const ShapeGrid JInitialShapeData;
	static const ShapeGrid TInitialShapeData;
};

