#include <iostream>
#include "Deck.h"
#include "CardHand.h"
#include "CardHandScorer.h"
#include "PokerScore.h"
#include <SFML/Graphics.hpp>
#include "PokerRankings.h"


int main() {
    srand(time(0));
    Deck deck;
    PokerScore a;
    for(int i = 0; i < 10000; i++)
    {
        deck.shuffle();
        CardHand ch;
        for (int j = 0; j < 5; j++)
        {
            ch.add_card(deck.dealCard());
        }
        a = CardHandScorer::scorePokerHand(ch);
    }
    std::cout << a.getPokerScore() << std::endl;

    sf::RenderWindow window({2300, 1300, 32}, "Poker Analysis");
    window.setFramerateLimit(60);

    PokerRankings b;
    b.outputHand(window);

    return 0;
}