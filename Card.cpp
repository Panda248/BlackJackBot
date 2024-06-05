#include "Card.h"
#include <stdlib.h>
#include "Utils.h"


Card::Card(int value):
	number(value),
	suit(rand()%4) {
	sprite = getSuitSprites(suit).at(number);
}

int Card::getSuit() {
	return suit;
}

int Card::getValue() {
	int actualValue = number + 1;
	if (actualValue > 10) {
		actualValue = 10;
	}
	if (number < 2) actualValue = 11;

	return actualValue;
}

sf::Sprite& Card::getSprite() {
	return sprite;
}