#include "Player.h"
#include "Utils.h"
#include <SFML/Graphics.hpp>


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
	int combinedValue;
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


void Player::Move() {

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


