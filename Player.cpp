#include "Player.h"
#include "Utils.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

enum class possibleMoves { hit, stand, doub, split, null};

possibleMoves nextMove;

void Player::init() {
	chart = Game::BSChart;
}

void Player::setMoney(int value) {
	Player::money = value;
}

void Player::addMoney(int value) {
	Player::money += value;
}

void Player::removeMoney(int value) {
	Player::money -= value;
}

int Player::getMoney() {
	return Player::money;
}

std::vector<std::vector<Card>> Player::getHands() {
	return Player::hands;
}

std::vector<Card>& Player::getHand(int index) {
	return Player::hands.at(index);
}

int Player::getValue(std::vector<Card>& hand) {
	int combinedValue = 0;
	for (Card& i : hand) combinedValue += i.getValue();

	return combinedValue;
}

bool Player::isBust(std::vector<Card>& hand) {
	return getValue(hand) > 21;
}

bool Player::isBlackJack(std::vector<Card>& hand) {
	return getValue(hand) == 21;
}

bool Player::hasMultipleHands() {
	return getHands().size() > 1;
}

void Player::evaluateHand(std::vector<Card>& hand, int dealerVal) {
	int playerVal = getValue(hand);
	
	enum Result { blackjack, won, tie, lost };
	Result roundResult;

	if (playerVal == 21) roundResult = blackjack;
	else if (playerVal > dealerVal && !isBust(hand)) roundResult = won;
	else if (playerVal == dealerVal) roundResult = tie;
	else roundResult = lost;

	// what is the index of getBet() ?
	switch (roundResult){
		case blackjack:
			addMoney(getBet(0) * 2);
			std::cout << "\n " << "BlackJack " << std::endl;
			break;
		case won:
			addMoney(getBet(0));
			std::cout << "\n " << "Win " << std::endl;
			break;
		case lost:
			removeMoney(getBet(0));
			std::cout << "\n " << "Lose " << std::endl;
			break;
		case tie:
			std::cout << " Tie " << std::endl;
			break;
	}
}

void Player::setHand(int index, std::vector<Card> hand) {
	Player::hands.assign(index, hand);
}

void Player::addHand(std::vector<Card> hand) {
	Player::hands.push_back(hand);
}

void Player::setBet(int index, int value) {
	Player::bets.assign(index, value);
}

void Player::addBet(int value) {
	if (bets.back() == 0) {
		bets.pop_back();
	}
	Player::bets.push_back(value);

	
}

int Player::getBet(int index) {
	return Player::bets.at(index);
}

std::vector<int> Player::getBets() {
	return Player::bets;
}

bool Player::canSplit(std::vector<Card> &hand) {
	if (this -> hands.size() > MAX_HANDS) {
		return false;
	}

	return (hand.size() == 2 && (hand.at(0).getValue() == hand.at(1).getValue()));
}

void Player::Init() {
	nextMove = possibleMoves::null;
	hands.clear();
	bets.clear();
	hands.resize(1);
	bets.resize(1);
}

int i;

bool Player::allMovesConcluded() {
	//i++;
	//if (i > 5) {
	//	return true;
	//}

	//std::cout << "Hand: " + getValue(getHand(0)) << std::flush;

	if (nextMove == possibleMoves::stand) {
		return true;
	}
	else {
		return false;
	}
}

void Player::Move(int dealerVal) {
	if (dealerVal > 21) { nextMove = possibleMoves::stand; return; }
	if (dealerVal < 1) { dealerVal = 2; }

	int handOneValue = getValue(getHand(0));
	int handTwoValue;

	// FIRST HAND
	if (handOneValue > 21) { nextMove = possibleMoves::stand; return; }

	/* for (int i = 0; i < 20; i++) {
		for (int j = 0; i < 11; j++) {
		}
		std::cout << "\n" << std::flush;
	} */ 
	std::cout << "\n" << "Dealer " << dealerVal << " vs " << "Player " << handOneValue << "\n" << std::flush;


	std::string correspondingAction = chart[handOneValue - 3][dealerVal - 1];
	analyzeString(correspondingAction);
	//nextMove = possibleMoves::stand;
	makeMove(0);

	// SECOND HAND
	if (hasMultipleHands()) {
		handTwoValue = getValue(getHand(1));
		if (handTwoValue > 21) return;
		std::string correspondingAction = chart[handOneValue - 3][dealerVal - 1];
		analyzeString(correspondingAction);
		makeMove(1);
	}
}

void Player::Move() {
}

void Player::analyzeString(std::string &s) {
	if (s.compare("H") == 0) {
		nextMove = possibleMoves::hit;
	}
	else if (s.compare("S") == 0) {
		nextMove = possibleMoves::stand;
	}
	else if (s.compare("D") == 0) {
		nextMove = possibleMoves::stand;
		// CHANGE BACK TO DOUBLE AFTER FIX
	}
	else nextMove = possibleMoves::stand;
}

void Player::Hit(std::vector<Card> &hand) {
	hand.push_back(generateCard());
}

void Player::Stand() {

}

void Player::Split(std::vector<Card> &hand, int bet) {
	if (canSplit(hand)) {
		hand.pop_back();
		addHand(hand);
		addBet(bet);
	}
}

void Player::Double(int &bet) {
	bet *= 2;
}

int Player::getRevealedValue()
{
	return hands[0][0].getValue();
}

void Player::makeMove(int handIndex) {
	switch (nextMove) {
	case possibleMoves::hit:
		Hit(getHand(handIndex));
		std::cout << " Hit " << std::flush;
		break;
	case possibleMoves::stand:
		Stand();
		std::cout << " Stand " << std::flush;
		break;
	case possibleMoves::doub:
		Double(bets[0]);
		std::cout << " Double " << std::flush;
		break;
	}
}