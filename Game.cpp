#include "Game.h"
#include "Utils.h"
#include <thread>
#include <chrono>
#include <iostream>


void Game::round(sf::RenderWindow& window)
{
	bot.Init();
	dealer.Init();
	recieveBets();
	renderBet(bot.getBet(0), 200, 300, window);
	dealHand();
	renderHand(bot.getHand(0), 200, 250, window);
	renderHand(dealer.getHand(0), 200, 100, window);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	recieveMoves();
	winCondition();
}

void Game::recieveBets()
{
	//bot card counts first, then determines optimal bet
	bot.addBet(10);
	initialBet = bot.getBet(0);
}

void Game::dealHand()
{
	dealer.Hit(dealer.getHand(0));
	bot.Hit(bot.getHand(0));

	dealer.Hit(dealer.getHand(0));
	bot.Hit(bot.getHand(0));
}

void Game::recieveMoves()
{
	while (!bot.allMovesConcluded()) {
		bot.Move();
	}
	while (!dealer.allMovesConcluded()) {
		dealer.Move();
	}
}

void Game::winCondition() {
	int dealerVal = dealer.getValue(dealer.getHand(0));

	bot.evaluateHand(bot.getHand(0), dealerVal);

	if (bot.hasMultipleHands()) {
		bot.evaluateHand(bot.getHand(1), dealerVal);
	}
	std::cout << "Money" << bot.getMoney() << std::endl;
}

void Game::shuffleDeck()
{
}