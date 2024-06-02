#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"

class Game {
public:
	void render(sf::RenderWindow& window);
	void update();
	void round(sf::RenderWindow& window);

protected:
	Player dealer;
	Player bot;

	std::vector<std::vector<std::string>> BSChart;

	int initialBet;
	bool dealerblackJack;
	bool playerblackJack;

	bool dealerWin;
	bool playerWin;

	void initialize();

	void recieveBets();
	void dealHand();
	void recieveMoves();

	void winCondition();

	void shuffleDeck();
};