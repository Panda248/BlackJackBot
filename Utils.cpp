#include <vector>
#include <SFML/Graphics.hpp>
#include "Utils.h"
#include <iostream>
#include "Card.h"

int cardValues[13] = { 11,2,3,4,5,6,7,8,9,10,10,10 };

int chipValues[4] = { 5,10,25,100 };

const int CARD_WIDTH = 88;
const int CARD_HEIGHT = 124;
const int CARD_OFFSET(22);

const int CHIP_WIDTH = 64;
const int CHIP_HEIGHT = 72;
const int CHIP_OFFSET(16);

sf::Font jqkasWild;
sf::Text title;
sf::Color background;

sf::Texture cardBack;
sf::Texture spades;
sf::Texture hearts;
sf::Texture clubs;
sf::Texture diamonds;

sf::Texture chips;

std::vector<sf::Sprite> spadeSprites;
std::vector<sf::Sprite> heartSprites;
std::vector<sf::Sprite> clubSprites;
std::vector<sf::Sprite> diamondSprites;
std::vector<sf::Sprite> chipSprites;

std::vector<sf::Sprite> renderSprites;

sf::Color getBackground() {
    return background;
}

std::vector<sf::Sprite> getSpadeSprites() {
    return spadeSprites;
}
std::vector<sf::Sprite> getHeartSprites() {
    return heartSprites;
}
std::vector<sf::Sprite> getClubSprites() {
    return clubSprites;
}
std::vector<sf::Sprite> getDiamondSprites() {
    return diamondSprites;
}
std::vector<sf::Sprite> getChipSprites() {
    return chipSprites;
}


void InitializeFonts() {
    jqkasWild.loadFromFile("assets/JqkasWild.ttf");
}

void InitializeColors() {
    background = sf::Color(0, 128, 0);
}

void InitializeText() {
    title.setFont(jqkasWild);

    title.setString("BlackJack");

    title.setFillColor(sf::Color::Black);
}

void InitializeTextures() {

    std::cout<<cardBack.loadFromFile("assets/Cards/Card_Back-88x124.png", sf::IntRect(0, 0, CARD_WIDTH, CARD_HEIGHT));
    cardBack.setSmooth(false);

    std::cout<<spades.loadFromFile("assets/Cards/Spades-88x124.png");
    spades.setSmooth(false);

    hearts.loadFromFile("assets/Cards/Hearts-88x124.png");
    hearts.setSmooth(false);

    clubs.loadFromFile("assets/Cards/Clubs-88x124.png");
    clubs.setSmooth(false);

    diamonds.loadFromFile("assets/Cards/Diamonds-88x124.png");
    diamonds.setSmooth(false);

    chips.loadFromFile("assets/Chips/ChipsA_Outline-64x72.png");
    chips.setSmooth(false);

}

void InitializeCardSprites(std::vector<sf::Sprite> &spriteVector, sf::Texture &texture) {
    sf::Sprite sprite;
    int j = -1;
    for (int i = 0; i < 13; i++) {

        if (i % 5 == 0) {
            j++;
        }
        sprite.setTexture(texture);
        sprite.setTextureRect(sf::IntRect(CARD_WIDTH*(i%5), CARD_HEIGHT*j, CARD_WIDTH, CARD_HEIGHT));
        spriteVector.push_back(sprite);
    }
    //std::cout << spriteVector.size();
}

void InitializeChips() {
    chipSprites.reserve(4);

    sf::Sprite sprite;
    sprite.setTexture(chips);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH, 0, CHIP_WIDTH, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH * 2, 0, CHIP_WIDTH, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH * 2, CHIP_HEIGHT, CHIP_WIDTH, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH * 4, 0, CHIP_WIDTH, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
}

void InitializeCards() {
    InitializeCardSprites(spadeSprites, spades);
    InitializeCardSprites(heartSprites, hearts);
    InitializeCardSprites(clubSprites, clubs);
    InitializeCardSprites(diamondSprites, diamonds);
}

int calculateHand(std::vector<int> hand) {
	int sum = 0;
	int aceCount = 0;

	for (int i : hand) {

		sum += i;

		if (i == 1) {
			aceCount++;
		}

	}
	while (sum > 21 && aceCount > 0) {
		sum -= 10;
		aceCount--;
	}
	return sum;
}

Card generateCard() {
	return Card(cardValues[rand() % 13]);
}

void renderHand(std::vector<int> hand, int x, int y, sf::RenderWindow window) {
    
}

void renderCard(int card, int x, int y, sf::RenderWindow window) {
    
}

void renderBet(int bet, int x, int y, sf::RenderWindow window) {

}

void render(sf::RenderWindow& window) {
    renderSprites.clear();
    window.draw(title);
    window.draw(heartSprites.at(6));
}