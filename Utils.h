#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Card.h"


sf::Color getBackground();

std::vector<sf::Sprite> getSpadeSprites();
std::vector<sf::Sprite> getHeartSprites();
std::vector<sf::Sprite> getClubSprites();
std::vector<sf::Sprite> getDiamondSprites();
std::vector<sf::Sprite> getChipSprites();



void InitializeFonts();
void InitializeColors();
void InitializeText();
void InitializeTextures();
void InitializeCards();

void InitializeChips();

int calculateHand(std::vector<int> hand);

Card generateCard();

void render(sf::RenderWindow& window);


