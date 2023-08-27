//
// Created by Sneha Gurung on 11/7/22.
//

#include "CardHand.h"
#include "Card.h"
#include <iostream>
#include <algorithm>

CardHand::CardHand(): CardHand(0, 0) { }

CardHand::CardHand(float xPos, const float yPos)
    : m_xPos(xPos), m_yPos(yPos)
{
}

void CardHand::add_card(const Card& card) {
    player_hand.push_back(card);
}

std::ostream& operator <<(std::ostream& outs, const CardHand& hand) {
    for (int i = 0; i < hand.getSize(); i++) {
        outs << hand.player_hand[i] << std::endl;
    }
    return outs;
}

Card CardHand::getCardAt(int index) const {
    return player_hand.at(index);
}

int CardHand::getSize() const {
    return player_hand.size();
}

int CardHand::getCardValueAt(int index) {
    return player_hand[index].getRank();
}

bool operator<(const Card& a, const Card& b) {
    return a.getRankInt() < b.getRankInt();
}

void CardHand::sortRank() {
    std::sort(player_hand.begin(), player_hand.end());
}
