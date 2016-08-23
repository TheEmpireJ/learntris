#include "stdafx.h"
#include "Tetramino.h"

// setting up static const members. This is for the shape data
const Tetramino::ShapeGrid Tetramino::IInitialShapeData = {
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank,
	TetrisGame::Cyan, TetrisGame::Cyan, TetrisGame::Cyan, TetrisGame::Cyan,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank,
	TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank, TetrisGame::Blank };

Tetramino::Tetramino()
{
}


Tetramino::~Tetramino()
{
}

void Tetramino::SetTetType(TetType type)
{
	switch (type)
	{
	case Itet: // setup for the "I" tetramino
		TType = Itet;
		ShapeSize = 4;
		ShapeData = IInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	case Otet:
		break;
	default:
		break;
	}
}
