#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include "Game.h"
#include "Button.h"

sf::RenderWindow window;
Game game;

int main()  {
    srand(time(NULL));
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BlackJack AI");
    InitializeTextures();
    InitializeColors();
    InitializeFonts();
    InitializeText();
    InitializeButtons();

    InitializeChips();
    InitializeCards();

    std::vector<Card> testHand;
    
    game.initialize();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        // clear the window with black color
        window.clear(getBackground());
        
        //render(window);
        //testHand.push_back(generateCard());

        sf::RenderWindow* target = &window;
        sf::Vector2f mousePositionFloat = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));

        updateButtons(mousePositionFloat, target);

        if (nextRoundButton.isPressed()) {
            game.round(window);
            game.render(window);
        }
        //renderHand(testHand, 50, 100, window);
        window.display();
    }

    return 0;
}