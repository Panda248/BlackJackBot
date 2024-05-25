#include "Card.h"
#include <stdlib.h>


Card::Card(int value):
	number(value),
	suit(rand()%4) {

}

int Card::getSuit() {
	return suit;
}

int Card::getValue() {
	return number;
}