#include "stdafx.h"
#include "Tetramino.h"
#include "TetrisGame.h"

Tetramino::Tetramino()
{
	SetTetType(NOTet);
}


Tetramino::~Tetramino()
{
}

int Tetramino::GetShapeDataAtPosition(int Row, int Col) const
{
	return ShapeData[Row*ShapeSize + Col];
}

int Tetramino::GetShapeSize() const
{
	return ShapeSize;
}

void Tetramino::GetPosition(int & OutRow, int & OutCol)
{
	OutRow = RowPos;
	OutCol = ColPos;
}

void Tetramino::SetTetType(TetType type)
{
	switch (type)
	{
	case NOTet: // blank tetramino
		TType = NOTet;
		ShapeSize = 0;
		ShapeData.fill(TetrisGame::Blank);
		RowPos = 0;
		ColPos = 0;
		break;

	case Itet: // setup for the "I" tetramino
		TType = Itet;
		ShapeSize = 4;
		ShapeData = IInitialShapeData;
		RowPos = 0; 
		ColPos = 3; // TODO find a place to put these magic numbers
		break;

	case Otet: // setup for the "O" tetramino
		TType = Otet;
		ShapeSize = 2;
		ShapeData = OInitialShapeData;
		RowPos = 0; 
		ColPos = 4;
		break;

	case Stet: // setup for the "S" tetramino
		TType = Stet;
		ShapeSize = 3;
		ShapeData = SInitialShapeData;
		RowPos = 0; 
		ColPos = 3;
		break;

	case Ztet: // setup for the "Z" tetramino
		TType = Ztet;
		ShapeSize = 3;
		ShapeData = ZInitialShapeData;
		RowPos = 0; 
		ColPos = 3;
		break;

	case Ltet: // setup for the "L" tetramino
		TType = Ltet;
		ShapeSize = 3;
		ShapeData = LInitialShapeData;
		RowPos = 0; 
		ColPos = 3;
		break;

	case Jtet: // setup for the "J" tetramino
		TType = Jtet;
		ShapeSize = 3;
		ShapeData = JInitialShapeData;
		RowPos = 0; 
		ColPos = 3;
		break;

	case Ttet: // setup for the "T" tetramino
		TType = Ttet;
		ShapeSize = 3;
		ShapeData = TInitialShapeData;
		RowPos = 0; 
		ColPos = 3;
		break;

	default:
		break;
	}

	FindExtents();
}

bool Tetramino::TryMoveLeft(TetrisGame * TheGame)
{
	// TODO check for colisions with the wall and other board state, for now, just subract one from the column position
	if (ColPos + MinCol - 1 < 0) // check for wall collisions
	{
		return false;
	}
	else if (CheckForCollisionWithGame(RowPos, ColPos - 1, &ShapeData, TheGame)) // check game board collision
	{
		return false;
	}
	else
	{
		ColPos--;
		return true;
	}
}

bool Tetramino::TryMoveRight(TetrisGame * TheGame)
{
	if (ColPos + MaxCol + 1 >= TetrisGame::Cols) // check for wall collisions
	{
		return false;
	}
	else if(CheckForCollisionWithGame(RowPos, ColPos + 1, &ShapeData, TheGame)) // check game board collision
	{
		return false;
	}
	else
	{
		ColPos++;
		return true;
	}
}

bool Tetramino::TryMoveDown(TetrisGame * TheGame)
{
	if (RowPos + MaxRow + 1 >= TetrisGame::Rows) // check for floor colisions 
	{
		return false;
	}
	else if (CheckForCollisionWithGame(RowPos + 1, ColPos, &ShapeData, TheGame)) // check for colisions with the game board
	{
		return false;
	}
	else
	{
		RowPos++;
		return true;
	}
}

bool Tetramino::TryRotateRight(TetrisGame* TheGame)
{
	ShapeGrid TempShapeData;

	// perform the rotation to a temp matrix
	if (ShapeSize % 2 != 0) // just copy middle element if odd size matrix
	{
		int mid = ShapeSize / 2;
		TempShapeData[mid*ShapeSize + mid] = ShapeData[mid*ShapeSize + mid];
	}

	for (int x = 0; x < (ShapeSize / 2); x++) // loop though all cycles (there are floor(size/2) cycles)
	{
		int CycleMax = ShapeSize - x - 1; // maximum x or y value for this cycle
		for (int y = x; y < CycleMax; y++) // rotate each element in the cycle
		{
			TempShapeData[y*ShapeSize + CycleMax] = ShapeData[x*ShapeSize + y]; // move top row element to right side

			TempShapeData[CycleMax*ShapeSize + CycleMax - y + x] = ShapeData[y*ShapeSize + CycleMax]; // move right side element to bottom

			TempShapeData[(CycleMax - y + x)*ShapeSize + x] = ShapeData[CycleMax*ShapeSize + CycleMax - y + x]; // move bottom element to left side

			TempShapeData[x*ShapeSize + y] = ShapeData[(CycleMax - y + x)*ShapeSize + x]; // move left side element to top
		}
	}
	//TODO check if the tetramino is able to rotote. For now, just copy the temp shape to the real shape
	for (int r = 0; r < ShapeSize; r++)
	{
		for (int c = 0; c < ShapeSize; c++)
		{
			ShapeData[r*ShapeSize + c] = TempShapeData[r*ShapeSize + c];
		}
	}

	FindExtents();
	return true; // TODO change to check if the rotation succeeds
}

bool Tetramino::TryRotateLeft(TetrisGame * TheGame)
{
	ShapeGrid TempShapeData;

	// perform the rotation to a temp matrix
	if (ShapeSize % 2 != 0) // just copy middle element if odd size matrix
	{
		int mid = ShapeSize / 2;
		TempShapeData[mid*ShapeSize + mid] = ShapeData[mid*ShapeSize + mid];
	}

	for (int x = 0; x < (ShapeSize / 2); x++) // loop though all cycles (there are floor(size/2) cycles)
	{
		int CycleMax = ShapeSize - x - 1; // maximum x or y value for this cycle
		for (int y = x; y < CycleMax; y++) // rotate each element in the cycle
		{
			TempShapeData[(CycleMax - y + x)*ShapeSize + x] = ShapeData[x*ShapeSize + y]; // move the top row element to the left side

			TempShapeData[CycleMax*ShapeSize + CycleMax - y + x] = ShapeData[(CycleMax - y + x)*ShapeSize + x]; // move the left side element to the bottom

			TempShapeData[y*ShapeSize + CycleMax] = ShapeData[CycleMax*ShapeSize + CycleMax - y + x]; // move the bottom element to the right side

			TempShapeData[x*ShapeSize + y] = ShapeData[y*ShapeSize + CycleMax]; // move the right side element to the top
		}
	}
	//TODO check if the tetramino is able to rotote. For now, just copy the temp shape to the real shape
	for (int r = 0; r < ShapeSize; r++)
	{
		for (int c = 0; c < ShapeSize; c++)
		{
			ShapeData[r*ShapeSize + c] = TempShapeData[r*ShapeSize + c];
		}
	}

	FindExtents();
	return true; // TODO change to check if the rotation succeeds
}

void Tetramino::FindExtents()
{
	MinRow = ShapeSize;
	MaxRow = 0;
	MinCol = ShapeSize;
	MaxCol = 0;

	for (int r = 0; r < ShapeSize; r++)
	{
		for (int c = 0; c < ShapeSize; c++)
		{
			if (GetShapeDataAtPosition(r, c) != TetrisGame::Blank)
			{
				if (r < MinRow) { MinRow = r; }
				if (r > MaxRow) { MaxRow = r; }
				if (c < MinCol) { MinCol = c; }
				if (c > MaxCol) { MaxCol = c; }
			}
		}
	}
	//std::cout << "extents are: MinRow: " << MinRow << ", MaxRow: " << MaxRow << ", MinCol: " << MinCol << ", MaxCol: " << MaxCol << std::endl;
}

bool Tetramino::CheckForCollisionWithGame(int ChkRow, int ChkCol, ShapeGrid * ChkGrid, TetrisGame* Game)
{
	for (int r = 0; r < ShapeSize; r++)
	{
		for (int c = 0; c < ShapeSize; c++)
		{
			// if any non-blank spaces overlap, we have a colision!
			if (GetShapeDataAtPosition(r, c) != TetrisGame::Blank && Game->GetBoardStateAtPosition(ChkRow + r, ChkCol + c) != TetrisGame::Blank)
			{
				return true;
			}
		}
	}
	return false;
}

// setting up static const members. Thiese define each shape's initial position and rotation data
const Tetramino::ShapeGrid Tetramino::IInitialShapeData = {
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank,
	TetrisGame::Cyan, TetrisGame::Cyan, TetrisGame::Cyan, TetrisGame::Cyan,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };

const Tetramino::ShapeGrid Tetramino::OInitialShapeData = {
	TetrisGame::Yellow, TetrisGame::Yellow,
	TetrisGame::Yellow, TetrisGame::Yellow };

const Tetramino::ShapeGrid Tetramino::ZInitialShapeData = {
	TetrisGame::Red, TetrisGame::Red, TetrisGame::Blank,
	TetrisGame::Blank, TetrisGame::Red, TetrisGame::Red,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };

const Tetramino::ShapeGrid Tetramino::SInitialShapeData = {
	TetrisGame::Blank, TetrisGame::Green, TetrisGame::Green,
	TetrisGame::Green, TetrisGame::Green, TetrisGame::Blank,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };

const Tetramino::ShapeGrid Tetramino::JInitialShapeData = {
	TetrisGame::Blue, TetrisGame::Blank, TetrisGame::Blank,
	TetrisGame::Blue, TetrisGame::Blue, TetrisGame::Blue,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };

const Tetramino::ShapeGrid Tetramino::LInitialShapeData = {
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Orange,
	TetrisGame::Orange, TetrisGame::Orange, TetrisGame::Orange,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };

const Tetramino::ShapeGrid Tetramino::TInitialShapeData = {
	TetrisGame::Blank, TetrisGame::Magenta, TetrisGame::Blank,
	TetrisGame::Magenta, TetrisGame::Magenta, TetrisGame::Magenta,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };
