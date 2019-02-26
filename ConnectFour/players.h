// Michael Smith
// 11/18/18
// Lab 7

#pragma once
class Game;
class Player {
public:
	virtual int getNextTurn(Game game) = 0;
};

class HumanPlayer : public Player {
public:
	int getNextTurn(Game game);
};

class AiPlayer : public Player {
public:
	int getNextTurn(Game game);
	
};