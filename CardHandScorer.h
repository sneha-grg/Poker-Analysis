//
// Created by Sneha Gurung on 11/7/22.
//

#ifndef POKER_CARDHANDSCORER_H
#define POKER_CARDHANDSCORER_H
#include "Scores.h"
#include "ranks.h"
#include "CardHand.h"
#include "PokerScore.h"

class CardHandScorer {
public:
    CardHandScorer();

    static PokerScore scorePokerHand(CardHand& hand);
    static bool isRoyalFlush(CardHand& hand);
    static bool isStraightFlush(CardHand& hand);
    static bool isFourOfAKind(CardHand& hand);
    static bool isFullHouse(CardHand& hand);
    static bool isFlush(CardHand& hand);
    static bool isStraight(CardHand& hand);
    static bool isThreeOfAKind(CardHand& hand);
    static bool isTwoPair(CardHand& hand);
    static bool isOnePair(CardHand& hand);
    static bool isHighCard(CardHand& hand);
    static PokerScore hold;
};


#endif //POKER_CARDHANDSCORER_H
