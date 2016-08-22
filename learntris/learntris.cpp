// learntris.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void ReadGameStateFromInput(TetrisGame* TheGame)
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
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Black);
				break;
			case 'b':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Blue);
				break;
			case 'c':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Cyan);
				break;
			case 'g':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Green);
				break;
			case 'm':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Magenta);
				break;
			case 'o':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Orange);
				break;
			case 'r':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Red);
				break;
			case 'y':
				TheGame->SetBoardStateAtPosition(r, c, TetrisGame::Yellow);
				break;
			default:
				TheGame->SetBoardStateAtPosition(r, c, -1); // error case
				break;
			}
		}
	}// */
}

int main()
{
	TetrisGame TheGame;
	TetrisDisplayManager DisplayManager;
	TetrisInputManager InputManager;

	DisplayManager.Initialize(&TheGame);

	while (true)
	{
		// TODO refactor getting/interperating input
		std::string input;
		std::getline(std::cin, input);

		if (input.length() == 1 && input[0] == 'q') { return 0; } // quit if 'q' is typed
		else if (input.length() == 1 && input[0] == 'p') // print the current game state matrix if 'p' is typed
		{
			DisplayManager.PrintBoardState();
		}
		else if (input.length() == 1 && input[0] == 'g') // read in the next lines to set the game board.
		{
			ReadGameStateFromInput(&TheGame);
		}
		else if (input.length() == 1 && input[0] == 'c') // clear the game board
		{
			TheGame.ClearBoardState();
		}
		else if (input.length() == 2 && input == "?s") // output the score
		{
			DisplayManager.PrintScore();
		}
		else if (input.length() == 2 && input == "?n") // output the number of rows cleared so far
		{
			DisplayManager.PrintRowsCleared();
		}
	}
    return 0;
}

