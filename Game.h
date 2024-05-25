#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {

protected:
	Player dealer;
	Player bot;

	int initialBet;
	bool dealerblackJack;
	bool playerblackJack;

	bool dealerWin;
	bool playerWin;

	void round();

	void recieveBets();
	void dealHand();
	void recieveMoves();

	void shuffleDeck();
};