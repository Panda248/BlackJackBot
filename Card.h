#pragma once
#include <SFML/Graphics.hpp>


class Card {
	public: 
		Card(int value);
		int getValue();
		int getSuit();
		sf::Sprite getSprite();
	protected:
		int number;
		int suit;
		sf::Sprite sprite;
};