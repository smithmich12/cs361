// Michael Smith
// 11/18/18
// Lab 7

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // for random
#include <time.h>
#include "game.h"
#include "players.h"
using namespace std;

// Human Next turn asks for user input if user input is not in bounds
// then it returns -1 otherwise it returns the users input
int HumanPlayer::getNextTurn(Game game) {
	int selection;
	cin >> selection;
	if (selection <= 0 || selection > game.BoardWidth)
		return -1;
	return selection;
}

// Ai Next Turn gets a random number between 1 and the BoardWidth
// and returns that selection
int AiPlayer::getNextTurn(Game game) {
	int selection = rand() % game.BoardWidth + 1;
	cout << selection;
	return selection;
}