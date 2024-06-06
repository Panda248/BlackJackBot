#pragma once

#include<iostream>
#include<ctime>
#include<cstdlib>
#include<sstream>
#include"SFML\System.hpp"
#include"SFML\Window.hpp"
#include"SFML\Graphics.hpp"

enum STATES {UNPRESSED = 0, HOVER = 1, PRESSED = 2};

class Button {
private: 
	int unsigned buttonState;

	sf::RectangleShape shape;
	sf::Font* font;
	sf::Text text;

	sf::Color defaultColor;
	sf::Color hoverColor;
	sf::Color pressedColor;

	sf::Clock clock;

	float timeAtFirstPress;
	float timeElapsed;

public:
	Button(float x, float y, float width, float height,
			sf::Font* font, std::string text,
			sf::Color defaultColor, sf::Color hoverColor, sf::Color pressedColor);

	Button();

	void update(sf::Vector2f mousePos);

	void render(sf::RenderWindow* target);

	bool isPressed();
};