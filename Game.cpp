#include "Game.h"
#include "Utils.h"

void Game::initialize() {
}

void Game::round() 
{
	recieveBets();
	dealHand();
	recieveMoves();
	winCondition();
}

void Game::recieveBets()
{
	//bot card counts first, then determines optimal bet
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
}

void Game::shuffleDeck()
{
}
