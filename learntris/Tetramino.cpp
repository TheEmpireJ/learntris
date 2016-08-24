#include "stdafx.h"
#include "Tetramino.h"
#include "TetrisGame.h"

Tetramino::Tetramino()
{
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
		TType = Otet;
		ShapeSize = 2;
		ShapeData = OInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	case Stet:
		TType = Stet;
		ShapeSize = 3;
		ShapeData = SInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	case Ztet:
		TType = Ztet;
		ShapeSize = 3;
		ShapeData = ZInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	case Ltet:
		TType = Ltet;
		ShapeSize = 3;
		ShapeData = LInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	case Jtet:
		TType = Jtet;
		ShapeSize = 3;
		ShapeData = JInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	case Ttet:
		TType = Ttet;
		ShapeSize = 3;
		ShapeData = TInitialShapeData;
		RowPos = 0; // TODO set real starting position
		ColPos = 0;
		break;

	default:
		break;
	}
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
