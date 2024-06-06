#include "Button.h"

Button::Button(float x, float y, float width, float height, 
		sf::Font* font, std::string text, 
		sf::Color defaultColor, sf::Color hoverColor, sf::Color pressedColor)
{
	buttonState = UNPRESSED;

	shape.setPosition(sf::Vector2f(x, y));
	shape.setSize(sf::Vector2f(width, height));

	this->font = font;
	this->text.setFont(*this->font);
	this->text.setString(text);

	this->text.setFillColor(sf::Color::White);
	this->text.setCharacterSize(12);
	this->text.setPosition(
		shape.getPosition().x + width/2.f - this->text.getGlobalBounds().width / 2.f,
		shape.getPosition().y + height/2.f - this->text.getGlobalBounds().height / 2.f
	);

	this->defaultColor = defaultColor;
	this->hoverColor = hoverColor;
	this->pressedColor = pressedColor;

	shape.setFillColor(this->defaultColor);
}

Button::Button()
{
}

void Button::update(sf::Vector2f mousePos)
{
	buttonState = UNPRESSED;

	if (shape.getGlobalBounds().contains(mousePos)) {
		buttonState = HOVER;
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			buttonState = PRESSED;
		}
	}

	switch (buttonState) {
	case UNPRESSED: 
		shape.setFillColor(defaultColor);
		break;
	case HOVER:
		shape.setFillColor(hoverColor);
		break;
	case PRESSED:
		shape.setFillColor(pressedColor);
		break;
	}
}

void Button::render(sf::RenderWindow* target)
{
	target->draw(shape);
}

bool Button::isPressed() {
	return buttonState == PRESSED;
}