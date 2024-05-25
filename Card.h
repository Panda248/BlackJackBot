#pragma once

class Card {
	public: 
		Card(int value);
		int getValue();
		int getSuit();
	protected:
		int number;
		int suit;
};