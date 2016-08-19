// learntris.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "TetrisGame.h"



int main()
{
	TetrisGame TheGame;

	while (true)
	{
		// TODO refactor getting/interperating input
		std::string input;
		std::getline(std::cin, input);
		if (input.length() == 1 && input[0] == 'q') { return 0; } // quit if 'q' is typed
		else if (input.length() == 1 && input[0] == 'p') // print the current game state matrix if 'p' is typed
		{
			TheGame.PrintGameState();
		}
		else if (input.length() == 1 && input[0] == 'g')
		{
			TheGame.ReadGameStateFromInput();
		}
	}
    return 0;
}

