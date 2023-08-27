//
// Created by Sneha Gurung on 11/7/22.
//

#ifndef POKER_CARDHAND_H
#define POKER_CARDHAND_H
#include "Deck.h"
#include <vector>
#include <iostream>
#include <algorithm>


class CardHand
{
private:
    std::vector<Card> player_hand;
public:
    float m_xPos;
    float m_yPos;

public:
    CardHand();
    CardHand(float, const float);

    void add_card(const Card& card);

    friend std::ostream& operator <<(std::ostream& outs, const CardHand& hand);
    friend bool operator <(const Card& a, const Card& b);
    Card getCardAt(int index) const;

    int getSize() const;
    int getCardValueAt(int index);
    void sortRank();
};


#endif //POKER_CARDHAND_H
