//
// Created by Sneha Gurung on 11/16/22.
//

#ifndef POKER_SFML_HAND_H
#define POKER_SFML_HAND_H
#include <SFML/Graphics.hpp>
#include "DrawCard.h"
#include "CardHand.h"


class SFML_hand : public sf::Drawable
{
private:
    CardHand hand;
    sf::Vector2f position;


public:
    SFML_hand();
    SFML_hand(const CardHand& hand_1);
    void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setPosition(sf::Vector2f pos);
};


#endif //POKER_SFML_HAND_H
