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

std::vector<Card> Player::getHand(int index) {
	return Player::hands.at(index);
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


