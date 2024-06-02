#include "Game.h"
#include "Utils.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <fstream>

enum class CSVReader {
    UnquotedField,
    QuotedField,
    QuotedQuote
};

std::vector<std::string> readCSVRow(const std::string& row) {
    CSVReader state = CSVReader::UnquotedField;
    std::vector<std::string> fields{ "" };
    size_t i = 0; // index of the current field
    for (char c : row) {
        switch (state) {
        case CSVReader::UnquotedField:
            switch (c) {
            case ',': // end of field
                fields.push_back(""); i++;
                break;
            case '"': state = CSVReader::QuotedField;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVReader::QuotedField:
            switch (c) {
            case '"': state = CSVReader::QuotedQuote;
                break;
            default:  fields[i].push_back(c);
                break;
            }
            break;
        case CSVReader::QuotedQuote:
            switch (c) {
            case ',': // , after closing quote
                fields.push_back(""); i++;
                state = CSVReader::UnquotedField;
                break;
            case '"': // "" -> "
                fields[i].push_back('"');
                state = CSVReader::QuotedField;
                break;
            default:  // end of quote
                state = CSVReader::UnquotedField;
                break;
            }
            break;
        }
    }
    return fields;
}

/// Read CSV file
std::vector<std::vector<std::string>> readCSV(std::istream& in) {
    std::vector<std::vector<std::string>> table;
    std::string row;
    while (!in.eof()) {
        std::getline(in, row);
        if (in.bad() || in.fail()) {
            break;
        }
        auto fields = readCSVRow(row);
        table.push_back(fields);
    }
    return table;
}

void Game::initialize() {
	std::ifstream csvFile("assets/BasicStrategy.csv");

	BSChart = readCSV(csvFile);

    std::string str = BSChart[0][0];

}

void Game::round(sf::RenderWindow& window)
{
    initialize();

	bot.Init();
	dealer.Init();
	recieveBets();
	renderBet(bot.getBet(0), 20, 300, window);
	dealHand();
	renderHand(bot.getHand(0), 200, 250, window);
	renderHand(dealer.getHand(0), 200, 100, window);
	std::this_thread::sleep_for(std::chrono::seconds(3));
	recieveMoves();
	winCondition();
}

void Game::recieveBets()
{
	//bot card counts first, then determines optimal bet
	bot.addBet(10);
	initialBet = bot.getBet(0);
}

void Game::dealHand()
{
	dealer.Hit(dealer.getHand(0));
	bot.Hit(bot.getHand(0));

	dealer.Hit(dealer.getHand(0));
	bot.Hit(bot.getHand(0));
}

void Game::recieveMoves()
{
	while (!bot.allMovesConcluded()) {
		bot.Move(dealer.getRevealedValue());
	}
	while (!dealer.allMovesConcluded()) {
		dealer.Move();
	}
}

void Game::winCondition() {
	int dealerVal = dealer.getValue(dealer.getHand(0));

	bot.evaluateHand(bot.getHand(0), dealerVal);

	if (bot.hasMultipleHands()) {
		bot.evaluateHand(bot.getHand(1), dealerVal);
	}
	std::cout << "Money" << bot.getMoney() << std::endl;
}

void Game::shuffleDeck()
{
}