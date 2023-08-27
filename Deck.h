//
// Created by Sneha Gurung on 11/6/22.
//

#ifndef POKER_DECK_H
#define POKER_DECK_H
#include "Card.h"


class Deck
{
private:
    int cardIndex;
    const static int DECK_SIZE = 52;
    Card deck[DECK_SIZE];

public:
    Deck();
    bool empty();
    void shuffle();
    Card dealCard();
    Card getCardAt(int index);
    void printDeck();
//    friend std::ostream& operator <<(std::ostream& outs, const Deck& deck);
};


#endif //POKER_DECK_H
