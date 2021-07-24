#include "Player.h"
#include <iostream>
using namespace std;

void Player::PrintText()
{
	cout << "Hello World\n";
}
void Player::PrintText(int a, int b)
{
	int limit = 0;
	for (size_t i = 0; i < a; i++)
	{
		cout << "There was a farmer, had a dog and Bingo was his Name'o\n";
		
		cout << "B\nI\nN\nG\nO\n" + limit*2;
		if (limit < b) ++limit;

		cout << "And Bingo was his Name'o\n\n";
	}
}
