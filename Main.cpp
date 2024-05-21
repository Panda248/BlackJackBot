#include <SFML/Graphics.hpp>



const int CARD_WIDTH = 88;
const int CARD_HEIGHT = 124;

const int CHIP_WIDTH = 64;
const int CHIP_HEIGHT = 72;



sf::RenderWindow window;

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
    cardBack.loadFromFile("assets/Cards/Card_Back-88x124.png", sf::IntRect(0,0,CARD_WIDTH,CARD_HEIGHT));
    cardBack.setSmooth(false);
    
    spades.loadFromFile("assets/Cards/Spades-88x124.png");
    spades.setSmooth(false);
    
    hearts.loadFromFile("assets/Cards/Hearts-88x124.png");
    hearts.setSmooth(false);
    
    clubs.loadFromFile("assets/Cards/Clubs-88x124.png");
    clubs.setSmooth(false);

    diamonds.loadFromFile("assets/Cards/Diamonds-88x124.png");
    diamonds.setSmooth(false);

    chips.loadFromFile("assets/Chips/ChipsA_Outline-64x72");
    chips.setSmooth(false);
}

void InitializeCardSprites(std::vector<sf::Sprite> spriteVector, sf::Texture texture) {
    spriteVector.reserve(13);
    sf::Sprite sprite;
    int j = 1;
    for (int i = 1; i <= 13; i++) {
        
        if (i % 5 == 0) {
            j++;
        }
        sprite.setTextureRect(sf::IntRect(0, 0, CARD_WIDTH * i, CARD_HEIGHT * j));
        spriteVector.push_back(sprite);
    }
}

void InitializeChips() {
    chipSprites.reserve(4);

    sf::Sprite sprite;
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH, 0, CHIP_WIDTH * 2, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH*2, 0, CHIP_WIDTH * 3, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH*2, CHIP_HEIGHT, CHIP_WIDTH * 3, CHIP_HEIGHT*2));
    chipSprites.push_back(sprite);
    sprite.setTextureRect(sf::IntRect(CHIP_WIDTH*4, 0, CHIP_WIDTH * 5, CHIP_HEIGHT));
    chipSprites.push_back(sprite);
}

void InitializeCards() {
    InitializeCardSprites(spadeSprites, spades);
    InitializeCardSprites(heartSprites, hearts);
    InitializeCardSprites(clubSprites, clubs);
    InitializeCardSprites(diamondSprites, diamonds);
}

int main()  {
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "BlackJack AI");

    InitializeColors();
    InitializeFonts();
    InitializeText();
    InitializeTextures();
    InitializeChips();
    InitializeCards();


    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // clear the window with black color
        window.clear(background);

        // draw everything here...
        // window.draw(...);
        window.draw(title);
        // end the current frame
        window.display();
    }

    return 0;
}