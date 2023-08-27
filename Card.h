//
// Created by Sneha Gurung on 11/6/22.
//

#ifndef POKER_CARD_H
#define POKER_CARD_H
#include "suits.h"
#include "ranks.h"
#include <iostream>

class Card {
private:
    suits suit;
    ranks value;

public:
    Card();
    Card(suits suit, ranks value);
    Card(const Card& other);

    friend std::ostream& operator <<(std::ostream& outs, const Card& card);

    std::string suitToString() const;
    std::string rankToString() const;

    void setSuit(suits newSuit);
    void setRank(ranks newValue);
    suits getSuit() const;
    ranks getRank() const;

    int getRankInt() const;
};


#endif //POKER_CARD_H
