#include "Game.h"
#include "Utils.h"

void Game::round() 
{
	
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

	if (dealer.getValue(dealer.getHand(0)) == 21) {
		blackJack = true;
	}
}

void Game::recieveMoves()
{

}

void Game::shuffleDeck()
{
}
