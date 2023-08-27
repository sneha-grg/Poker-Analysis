//
// Created by Sneha Gurung on 11/20/22.
//

#include "PokerRankings.h"

void PokerRankings::outputHand(sf::RenderWindow& window) {

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({HEARTS, ACE});
        ch.add_card({HEARTS, KING});
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({HEARTS, JACK});
        ch.add_card({HEARTS, TEN});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({CLUBS, TEN});
        ch.add_card({CLUBS, NINE});
        ch.add_card({CLUBS, EIGHT});
        ch.add_card({CLUBS, SEVEN});
        ch.add_card({CLUBS, SIX});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({SPADES, QUEEN});
        ch.add_card({DIAMONDS, QUEEN});
        ch.add_card({CLUBS, QUEEN});
        ch.add_card({HEARTS, KING});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({SPADES, QUEEN});
        ch.add_card({DIAMONDS, QUEEN});
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({CLUBS, FIVE});
        ch.add_card({HEARTS, FIVE});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos, startYpos);
        ch.add_card({CLUBS, KING});
        ch.add_card({CLUBS, NINE});
        ch.add_card({CLUBS, SEVEN});
        ch.add_card({CLUBS, FIVE});
        ch.add_card({CLUBS, TWO});
        allHands.push_back(ch);
        startYpos += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({DIAMONDS, TEN});
        ch.add_card({SPADES, NINE});
        ch.add_card({HEARTS, EIGHT});
        ch.add_card({CLUBS, SEVEN});
        ch.add_card({DIAMONDS, SIX});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({DIAMONDS, FIVE});
        ch.add_card({SPADES, NINE});
        ch.add_card({HEARTS, FIVE});
        ch.add_card({CLUBS, FIVE});
        ch.add_card({DIAMONDS, SIX});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({DIAMONDS, ACE});
        ch.add_card({SPADES, ACE});
        ch.add_card({HEARTS, TEN});
        ch.add_card({CLUBS, TEN});
        ch.add_card({SPADES, SIX});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({CLUBS, TWO});
        ch.add_card({DIAMONDS, JACK});
        ch.add_card({SPADES, ACE});
        ch.add_card({HEARTS, ACE});
        ch.add_card({SPADES, SEVEN});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    {
        CardHand ch(startXpos2, startYpos2);
        ch.add_card({SPADES, JACK});
        ch.add_card({HEARTS, QUEEN});
        ch.add_card({CLUBS, KING});
        ch.add_card({HEARTS, FIVE});
        ch.add_card({DIAMONDS, TWO});
        allHands.push_back(ch);
        startYpos2 += rowIncrementAmount;
    }

    for (int i = 0; i < allHands.size(); ++i) {
        drawableHands.emplace_back(allHands[i]);
    }

    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window.close();
            }
        }

        window.clear(sf::Color(85, 125, 96));
        for (int i = 0; i < drawableHands.size(); i++)
        {
            window.draw(drawableHands[i]);
        }
        window.display();
    }
}

PokerRankings::PokerRankings() = default;
