//
// Created by Sneha Gurung on 11/14/22.
//

#ifndef POKER_DRAWCARD_H
#define POKER_DRAWCARD_H
#include "ranks.h"
#include "suits.h"
#include <SFML/Graphics.hpp>
#include <string>
#include "PokerScore.h"
#include <iomanip>


class DrawCard : public sf::Drawable, public sf::Transformable
{
private:
    sf::RectangleShape background;
    sf::Text rank;
    sf::Text rank2;
    sf::Sprite suit;
    static sf::Texture texture;
    static sf::Font font;
    sf::Text RoyalFlush, StraightFlush, FourOfAKind, FullHouse, Flush,
            Straight, ThreeOfAKind, TwoPair, Pair, HighCard;
    /* textures for SUITS */
    static sf::Texture Hearts;
    static sf::Texture Spades;
    static sf::Texture Diamonds;
    static sf::Texture Clubs;
    suits _suit;
    ranks _rank;
    std::string rankToString();
    std::string suitToString();
    void initialize();
    void setUpProbability();
    void setUpBackground();
    void setUpRank();
    void setUpSuit();
    void positionSuit();
    void positionRank();

    void setText();

public:
    DrawCard();
    DrawCard(std::string suit, std::string rank);
    DrawCard(suits suit, ranks rank);
    PokerScore scoreObj;
    sf::FloatRect bounds();
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const override;
    void setFillColor(const sf::Color& color);
    void setSize(sf::Vector2f size);
    void setSize(float width, float height);
    void setPosition(sf::Vector2f position);
    void setPosition(float x, float y);
};


#endif //POKER_DRAWCARD_H
