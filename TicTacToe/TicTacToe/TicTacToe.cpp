// TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>
#include <stdlib.h>

enum GAMESTATE
{
	START,
	NEWGAME,
	RUNNING,
	GAMEOVER,
	QUIT
}; 

void PrintText(int gameState)
{
	switch (gameState)
	{
	case GAMESTATE::START:
		// print start text
		std::cout << "Welcome to TIC TAC TOE\n\n";
		// print menu choices
		std::cout << "[ ] NEW GAME\n";
		std::cout << "[ ] QUIT GAME\n\n";
		std::cout << "Use the arrow keys to make your selection then press space...\n";
		break;
	case GAMESTATE::NEWGAME:
		// print instructions text
		std::cout << "Use the arrow keys to move, hit space to select\n\n";
		std::cout << "[ ][ ][ ]\n[ ][ ][ ]\n[ ][ ][ ]\n";
		break;
	case GAMESTATE::GAMEOVER:
		// get result
		// print result text
		break;
	default:
		std::cout << "Failed to PrintText";
		break;
	}
}

void SetCursorPosition(int gameState)
{
	COORD start = { 1,3 };
	COORD centre = { 5,5 };
	switch (gameState)
	{
	case GAMESTATE::START:
		// set cursor position to NEW GAME
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), start);
		break;
	case GAMESTATE::RUNNING:
		// set cursor to middle of board
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), centre);
		break;
	case GAMESTATE::GAMEOVER:
		// set cursor position to NEWGAME
		break;
	default:
		std::cout << "Failed to Set Cursor Position";
		break;
	}
}

int MoveCursor(int gameState)
{
	// error here, always returns 1 even when it shouldnt
	COORD STARTnewGame = { 1,3 };
	COORD STARTquit = { 1,4 };
	bool selectionMade = false;
	int switchTo = 0;

	while (selectionMade == false)
	{
		switch (gameState)
		{
		case GAMESTATE::START:
			// move cursor between NEW GAME and QUIT
			if (GetAsyncKeyState(VK_UP))
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), STARTnewGame);
				switchTo = NEWGAME;
			}
			else if (GetAsyncKeyState(VK_DOWN))
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), STARTquit);
				switchTo = QUIT;
			}
			break;
		case GAMESTATE::RUNNING:
			// print instructions text
			break;
		case GAMESTATE::GAMEOVER:
			// set cursor position to NEWGAME
			break;
		default:
			std::cout << "Failed to Move Cursor";
			break;
		}
		if (GetAsyncKeyState(VK_SPACE))
		{
			selectionMade = true;
		}
	}
	if (switchTo > 0)
	{
		return switchTo;
	}
}

void DrawGameBoard()
{

}

void ClearScreen()
{
	system("CLS");
}

int main()
{
	int gameState = 0;
	bool isGameComplete = false;

	while (!isGameComplete)
	{
		switch (gameState)
		{
		case GAMESTATE::START:
		{
			std::cout << "GAMESTATE::START" << std::endl;
			// print intro text
			// print menu choices
			PrintText(START);
			// cursor movement
			// change state on selection (NEWGAME or QUIT)
			SetCursorPosition(START);
			gameState = MoveCursor(START);
			break;
		}
		case GAMESTATE::NEWGAME:
		{
			ClearScreen();
			std::cout << "GAMESTATE::NEWGAME" << std::endl;
			// print instructions and controls
			PrintText(NEWGAME);
			// draw game board
			DrawGameBoard();
			// change state on completion to RUNNING
			gameState = RUNNING;
			break;
		}
		case GAMESTATE::RUNNING:
		{
			std::cout << "GAMESTATE::RUNNING" << std::endl;
			// cursor movement
			SetCursorPosition(RUNNING);
			// selection of tile
			// draw player selection
			// draw computer selection
			// when game is over change state to GAMEOVER
			break;
		}
		case GAMESTATE::GAMEOVER:
		{
			std::cout << "GAMESTATE::GAMEOVER" << std::endl;
			// draw and highlight winning board combination or none
			// print result to user
			PrintText(GAMEOVER);
			// cursor movement
			// change state on selection (NEWGAME or QUIT)
			break;
		}
		case GAMESTATE::QUIT:
		{
			std::cout << "GAMESTATE::QUIT" << std::endl;
			// unload all memory
			// quit application
			break;
		}
		default:
			std::cout << "Failed to switch states";
			break;
		}
	}

	

	/*char enter = 0;
	while (!enter) 
	{
		std::cout << "Press enter to quit...\n";
		enter = std::cin.get();
		return 0;
	}*/
	return 0;
}

