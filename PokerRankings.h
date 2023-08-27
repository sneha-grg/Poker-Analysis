//
// Created by Sneha Gurung on 11/20/22.
//

#ifndef POKER_POKERRANKINGS_H
#define POKER_POKERRANKINGS_H
#include <SFML/Graphics.hpp>
#include "CardHand.h"
#include "SFML_hand.h"
#include "CardHandScorer.h"
#include "PokerScore.h"


class PokerRankings {
private:
    std::vector<CardHand> allHands = {};
    std::vector<SFML_hand> drawableHands = {};
    int startXpos = 500;
    int startYpos = 50;
    int startXpos2 = 1200.f;
    int startYpos2 = 50;
    const static int rowIncrementAmount = 250;

public:
    PokerRankings();
    void outputHand(sf::RenderWindow& window);
};


#endif //POKER_POKERRANKINGS_H
