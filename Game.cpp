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

	// TODO: remove unused booleans
}

void Game::recieveMoves()
{	
	bot.Move();
	dealer.Move();
}

void Game::winCondition(){
	bool hasSplit = bot.hasMultipleHands();



	if ((dealerblackJack && playerblackJack) || ) {
	}

}

void Game::shuffleDeck()
{
}
