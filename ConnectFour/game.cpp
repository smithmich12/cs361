// Michael Smith
// 11/18/18
// Lab 7

#include <iostream>
#include <stdio.h>
#include <stdlib.h> // for random
#include <time.h>
#include "players.h"
#include "game.h"

using namespace std;

// Constructor to set up the board, assign players, and sets the current
// state to player 1's turn. Also sets up a random seed for the Ai.
Game::Game(Player &p1, Player &p2) {
	srand(time(NULL));
	player1 = &p1;
	player2 = &p2;

	board = new BoardField *[BoardHeight];
	for (int y = 0; y < BoardHeight; y++) {
		board[y] = new BoardField [BoardWidth];
		for (int x = 0; x < BoardWidth; x++) {
			board[y][x] = Empty;
		}
	}
	currentState = TurnP1;
}

// Checks whose turn it is and then gets that players turn, then checks to see if
// they won.
void Game::nextTurn() {
	if (currentState == TurnP1) {
		bool played = play(*player1, 1);
		if (played)
			currentState = TurnP2;
	} else if (currentState == TurnP2) {
		bool played = play(*player2, 2);
		if (played)
			currentState = TurnP1;
	}

	checkWin();
}

// Checks to see if a player has won or if there has been a draw.
bool Game::isRunning() {
	if (currentState == P1Won || currentState == P2Won || currentState == Draw) {
		return false;
	}
	else {
		return true;
	}
}

// Returns the currentState
GameState Game::getState() {
	return currentState;
}

// Gets the BoardField at a specific x, y
BoardField Game::operator() (int x, int y) const {
	return board[y][x];
}

// Gets the players selection and then puts their selection on the board
// if the space is open and in bounds
bool Game::play(Player &player, int playernum) {
	int selection = player.getNextTurn(*this);
	if (selection == -1) return false;
	int y;
	for (y = 0; y < BoardHeight; y++) {
		if (board[y][selection - 1] != Empty) {
			break;
		}
	}
	if (y - 1 == -1) return false;
	if (playernum == 1)
		board[y - 1][selection - 1] = Player1;
	else
		board[y - 1][selection - 1] = Player2;
	return true;
}

// Checks every case for a connect four
void Game::checkWin() {

	// Vertical Check
	for (int y = 0; y < BoardHeight - 3; y++) {
		for (int x = 0; x < BoardWidth; x++) {
			if (board[y][x] == Player1 && board[y + 1][x] == Player1 && board[y + 2][x] == Player1 && board[y + 3][x] == Player1) {
				currentState = P1Won;
				return;
			}
			else if (board[y][x] == Player2 && board[y + 1][x] == Player2 && board[y + 2][x] == Player2 && board[y + 3][x] == Player2) {
				currentState = P2Won;
				return;
			}
		}
	}

	// Horizontal Check
	for (int x = 0; x < BoardWidth - 3; x++) {
		for (int y = 0; y < BoardHeight; y++) {
			if (board[y][x] == Player1 && board[y][x + 1] == Player1 && board[y][x + 2] == Player1 && board[y][x + 3] == Player1) {
				currentState = P1Won;
				return;
			}
			else if (board[y][x] == Player2 && board[y][x + 1] == Player2 && board[y][x + 2] == Player2 && board[y][x + 3] == Player2) {
				currentState = P2Won;
				return;
			}
		}
	}

	// Decending Diagonal Check (Down and to the left)
	for (int x = 3; x < BoardWidth; x++) {
		for (int y = 0; y < BoardHeight - 3; y++) {
			if (board[y][x] == Player1 && board[y + 1][x - 1] == Player1 && board[y + 2][x - 2] == Player1 && board[y + 3][x - 3] == Player1) {
				currentState = P1Won;
				return;
			}
			else if (board[y][x] == Player2 && board[y + 1][x - 1] == Player2 && board[y + 2][x - 2] == Player2 && board[y + 3][x - 3] == Player2) {
				currentState = P2Won;
				return;
			}
		}
	}

	// Ascending Diagonal Check (Up and to the left)
	for (int x = 3; x < BoardWidth; x++) {
		for (int y = 3; y < BoardHeight; y++) {
			if (board[y][x] == Player1 && board[y - 1][x - 1] == Player1 && board[y - 2][x - 2] == Player1 && board[y - 3][x - 3] == Player1) {
				currentState = P1Won;
				return;
			}
			else if (board[y][x] == Player2 && board[y - 1][x - 1] == Player2 && board[y - 2][x - 2] == Player2 && board[y - 3][x - 3] == Player2) {
				currentState = P2Won;
				return;
			}
		}
	}

	// Check for draw
	for (int x = 0; x < BoardWidth; x++) {
		if (board[0][x] == Empty) {
			break;
		}
		else if (x == BoardWidth - 1) {
			currentState = Draw;
		}
	}
}