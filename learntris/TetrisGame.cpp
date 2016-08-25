#include "stdafx.h"
#include "TetrisGame.h"

TetrisGame::TetrisGame()
{
	//GameGridData = { {0,0,0,0,0,0,0,0,0,0} };
}


TetrisGame::~TetrisGame()
{
}

int TetrisGame::GetScore() const { return Score; }
int TetrisGame::GetRowsCleared() const { return RowsCleared; }

int TetrisGame::GetBoardStateAtPosition(int Row, int Col) const
{
	return GameGridData[Row*Cols + Col];
}

Tetramino* TetrisGame::GetCurrentTetramino() 
{
	return &CurrentTetramino;
}

TetrisGame::GameGrid* TetrisGame::GetBoardState()
{
	return &GameGridData;
}

void TetrisGame::ReadGameStateFromInput()
{
	//TODO test for invalid inputs
	std::string input;

	for (int r = 0; r < TetrisGame::Rows; r++)
	{
		std::getline(std::cin, input);
		for (int c = 0; c < TetrisGame::Cols; c++)
		{
			switch (input[c * 2]) // c * 2 accounts for spaces
			{
			case '.':
				SetBoardStateAtPosition(r, c, TetrisGame::Blank);
				break;
			case 'b':
				SetBoardStateAtPosition(r, c, TetrisGame::Blue);
				break;
			case 'c':
				SetBoardStateAtPosition(r, c, TetrisGame::Cyan);
				break;
			case 'g':
				SetBoardStateAtPosition(r, c, TetrisGame::Green);
				break;
			case 'm':
				SetBoardStateAtPosition(r, c, TetrisGame::Magenta);
				break;
			case 'o':
				SetBoardStateAtPosition(r, c, TetrisGame::Orange);
				break;
			case 'r':
				SetBoardStateAtPosition(r, c, TetrisGame::Red);
				break;
			case 'y':
				SetBoardStateAtPosition(r, c, TetrisGame::Yellow);
				break;
			default:
				SetBoardStateAtPosition(r, c, -1); // error case
				break;
			}
		}
	}// */
}

void TetrisGame::ClearBoardState()
{
	for (int r = 0; r < Rows; r++)
	{
		for (int c = 0; c < Cols; c++)
		{
			GameGridData[r * Cols + c] = Blank;
		}
	}
}

void TetrisGame::SetBoardStateAtPosition(int Row, int Col, int Data)
{
	GameGridData[Row*Cols + Col] = Data; // TODO add validation
}

void TetrisGame::Simulate()
{
	// loop though all rows
	for (int r = 0; r < Rows; r++)
	{
		// if row is full
		if (IsRowFull(r))
		{
			RowsCleared++;
			Score += OneRowScore;
			ClearRow(r);
		}
	}
}

void TetrisGame::ProcessInput()
{
	std::string input;
	std::getline(std::cin, input);

	for (int i = 0; i < input.length(); i++) {
		switch (input[i]) {
		case 'q': // quit the game
			bKeepRunning = false;
			return; 
			break;

		case 'p':  // print the current game state matrix if 'p' is typed
			DisplayManager.PrintBoardState(this);
			break;

		case ';': // print a newline
			std::cout << std::endl; // TODO handle with the display manager?
			break;

		case 'g':  // read in the next lines to set the game board.
			ReadGameStateFromInput(); // TODO I think there is a bug here if 'g' is not the last thing in the line
			break;

		case 'c': // clear the game board
			ClearBoardState();
			break;

		case '?': // output the score
			i++; //TODO this might crash if '?' is the last thing in the line?
			if (input[i] == 's') { DisplayManager.PrintScore(this); }
			else if (input[i] == 'n') { DisplayManager.PrintRowsCleared(this); }
			break;

		case 's': // run one step of the simulation
			Simulate();
			break;

		case ')': // rotate current tetramino right (clockwise)
			CurrentTetramino.TryRotateRight(this);
			break;

		case 't': // print the current tetramino
			DisplayManager.PrintCurrentTetramino(&CurrentTetramino);
			break;

		case 'I': // change the current tetramino to "I"
			CurrentTetramino.SetTetType(Tetramino::Itet);
			break;

		case 'O': // change the current tetramino to "O"
			CurrentTetramino.SetTetType(Tetramino::Otet);
			break;

		case 'Z': // change the current tetramino to "Z"
			CurrentTetramino.SetTetType(Tetramino::Ztet);
			break;

		case 'S': // change the current tetramino to "S"
			CurrentTetramino.SetTetType(Tetramino::Stet);
			break;

		case 'J': // change the current tetramino to "J"
			CurrentTetramino.SetTetType(Tetramino::Jtet);
			break;

		case 'L': // change the current tetramino to "L"
			CurrentTetramino.SetTetType(Tetramino::Ltet);
			break;

		case 'T': // change the current tetramino to "T"
			CurrentTetramino.SetTetType(Tetramino::Ttet);
			break;

		default:
			break;
		}
	}
}

void TetrisGame::Run()
{
	while (bKeepRunning)
	{
		ProcessInput();
	}
}

bool TetrisGame::IsRowFull(int Row) const
{
	bool RowFull = true;

	for (int c = 0; c < Cols; c++)
	{
		if (GameGridData[Row*Cols + c] == Blank)
		{
			RowFull = false;
			break;
		}
	}
	return RowFull;
}

void TetrisGame::ClearRow(int Row)
{
	// TODO make higher rows drop down here as well?
	for (int c = 0; c < Cols; c++)
	{
		GameGridData[Row*Cols + c] = Blank;
	}
	return;
}


