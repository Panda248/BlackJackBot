#pragma once
#include <vector>
#include "Card.h"


class Player
{
	const int MAX_HANDS = 4;

	int money;

public:

	void setMoney(int value);
	void addMoney(int value);
	void removeMoney(int value);
	int getMoney();


	std::vector<std::vector<Card>> hands;

	std::vector<std::vector<Card>> getHands();
	std::vector<Card>& getHand(int index);
	int getValue(std::vector<Card>& hand);
	void setHand(int index, std::vector<Card> hand);
	void addHand(std::vector<Card> hand);

	std::vector<int> bets;

	void setBet(int index, int value);
	void addBet(int value);

	int getBet(int index);

	std::vector<int> getBets();

	void Move();
	void Hit(std::vector<Card> &hand);
	void Stand();
	void Split(std::vector<Card> &hand, int bet);
	bool canSplit(std::vector<Card> &hand);
	void Double(int &bet);

};

