#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {

protected:
	Player dealer;
	Player bot;

	bool win;

	void recieveBets();
	void dealHand();
	void recieveMoves();

	void shuffleDeck();
};