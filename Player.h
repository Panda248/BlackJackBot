#pragma once
#include <vector>



class Player
{
	const int MAX_HANDS = 4;

	int money;

	void setMoney(int value);
	void addMoney(int value);
	void removeMoney(int value);
	int getMoney();


	std::vector<std::vector<int>> hands;

	std::vector<std::vector<int>> getHands();
	std::vector<int> getHand(int index);
	void setHand(int index, std::vector<int> hand);
	void addHand(std::vector<int> hand);

	std::vector<int> bets;

	void setBet(int index, int value);
	void addBet(int value);
	int getBet(int index);
	std::vector<int> getBets();

	void Move();
	void Hit(std::vector<int> &hand);
	void Stand();
	void Split(std::vector<int> &hand, int bet);
	bool canSplit(std::vector<int> hand);
	void Double(int &bet);

};

