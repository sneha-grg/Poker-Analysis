//
// Created by Sneha Gurung on 11/16/22.
//

#include "SFML_hand.h"
#include <vector>

SFML_hand::SFML_hand() = default;


SFML_hand::SFML_hand(const CardHand& hand_1) : hand(hand_1)
{
    setPosition({hand_1.m_xPos, hand_1.m_yPos});
}


void SFML_hand::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    std::vector<DrawCard> cards;
    for(int i = 0; i < hand.getSize(); i++)
    {
        cards.emplace_back(hand.getCardAt(i).getSuit(), hand.getCardAt(i).getRank());
    }
    int num = 110; // :)
    for(int i = 0; i < cards.size(); i++)
    {
        cards[i].setPosition(position.x + (num * i), position.y);
        window.draw(cards[i]);
    }
}


void SFML_hand::setPosition(sf::Vector2f pos) {
    this->position = pos;
}
