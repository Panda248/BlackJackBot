#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Utils.h"
#include <iostream>
#include <ctime>
#include "Card.h"

sf::RenderWindow window;


int main()  {
    srand(time(NULL));
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BlackJack AI");
    
    InitializeTextures();
    InitializeColors();
    InitializeFonts();
    InitializeText();
   

    InitializeChips();
    InitializeCards();

    std::vector<Card> testHand;
    
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

        //renderHand(testHand, 50, 100, window);
        renderBet(162, 50, 100, window);
        window.display();
    }

    return 0;
}