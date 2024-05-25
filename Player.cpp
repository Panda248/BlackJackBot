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

std::vector<std::vector<int>> Player::getHands() {
	return Player::hands;
}

std::vector<int> Player::getHand(int index) {
	return Player::hands.at(index);
}

void Player::setHand(int index, std::vector<int> hand) {
	Player::hands.assign(index, hand);
}

void Player::addHand(std::vector<int> hand) {
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

bool Player::canSplit(std::vector<int> hand) {
	if (this -> hands.size() > MAX_HANDS) {
		return false;
	}

	return (hand.size() == 2 && (hand.at(0) == hand.at(1)));
}


void Player::Move() {

}


void Player::Hit(std::vector<int> &hand) {

}

void Player::Stand() {

}


void Player::Split(std::vector<int> &hand, int bet) {
	if (canSplit(hand)) {
		hand.pop_back();
		addHand(hand);
		addBet(bet);
	}
}

void Player::Double(int &bet) {
	bet *= 2;
}


