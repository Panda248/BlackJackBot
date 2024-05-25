#include "Card.h"
#include <stdlib.h>
#include "Utils.h"


Card::Card(int value):
	number(value),
	suit(rand()%4) {
	sprite = getSuitSprites(suit).at(number);
	sprite.setPosition(100.f, 100.f);
}

int Card::getSuit() {
	return suit;
}

int Card::getValue() {
	return number;
}

sf::Sprite& Card::getSprite() {
	return sprite;
}