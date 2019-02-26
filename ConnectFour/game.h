// Michael Smith
// 11/18/18
// Lab 7

#pragma once
class Player;
enum BoardField { Empty, Player1, Player2 };
enum GameState { TurnP1, TurnP2, P1Won, P2Won, Draw };


class Game {
	

public:
	int const BoardWidth = 7;
	int const BoardHeight = 6;

	Game(Player &p1, Player &p2);

	void nextTurn();
	bool isRunning();
	GameState getState();

	BoardField operator() (int x, int y) const;

private:
	Player *player1;
	Player *player2;
	BoardField **board;
	GameState currentState;
	bool play(Player &player, int playernum);
	void checkWin();
};