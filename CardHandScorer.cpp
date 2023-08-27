//
// Created by Sneha Gurung on 11/7/22.
//

#include "CardHandScorer.h"
PokerScore CardHandScorer::hold;

CardHandScorer::CardHandScorer() { }

PokerScore CardHandScorer::scorePokerHand(CardHand& hand) {
    hand.sortRank();
    isRoyalFlush(hand);
    isStraightFlush(hand);
    isFourOfAKind(hand);
    isFullHouse(hand);
    isFlush(hand);
    isStraight(hand);
    isThreeOfAKind(hand);
    isTwoPair(hand);
    isOnePair(hand);
    isHighCard(hand);
    return hold;
}

bool CardHandScorer::isRoyalFlush(CardHand &hand) {
    bool stands = true;
    for (int i = 0; i < hand.getSize(); i++) {
        if (hand.getCardAt(0).getSuit() != hand.getCardAt(i).getSuit())
            stands = false;
    }

    if (hand.getCardAt(0).suitToString() == "TEN"
    && hand.getCardAt(1).suitToString() == "JACK"
    && hand.getCardAt(2).suitToString() == "QUEEN"
    && hand.getCardAt(3).suitToString() == "KING"
    && hand.getCardAt(4).suitToString() == "ACE"
    && stands)
        hold.addScore(Scores::ROYAL_FLUSH);

    return stands;
}

bool CardHandScorer::isStraightFlush(CardHand &hand) {
    bool stands = true;
    for (int i = 0; i < hand.getSize(); i++) {
        if (hand.getCardAt(0).getSuit() != hand.getCardAt(i).getSuit())
            return false;
    }

    hand.sortRank();
    for (int i = 0; i < hand.getSize()-1; i++) {
        if (hand.getCardValueAt(i+1) - hand.getCardValueAt(i) != 1)
            return false;
    }
    hold.addScore(Scores::STRAIGHT_FLUSH);
    return stands;
}

bool CardHandScorer::isFourOfAKind(CardHand& hand) {
    bool stands = false;
    int count[13] = {0};
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)] ++;
    }
    for (int j = 0; j < 13; j++) {
        if (count[j] >= 4)
        {
            hold.addScore(Scores::FOUR_OF_A_KIND);
            stands = true;
            break;
        }
    }
    return stands;
}

bool CardHandScorer::isFullHouse(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    int three = 0;
    int pair = 0;
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)]++;
    }

    for (int i = 0; i < ranks::NUM_RANKS; i++) {
        if (count[i] == 2)
            pair += 1;
        if (count[i] == 3)
            three += 1;
        if (three > 0 && pair > 0){
            hold.addScore(Scores::FULL_HOUSE);
            break;
        }
    }

    return stands;
}

bool CardHandScorer::isFlush(CardHand &hand) {
    bool stands = true;
    for (int i = 0; i < hand.getSize(); i++) {
        if (hand.getCardAt(0).getSuit() != hand.getCardAt(i).getSuit()) {
            stands = false;
            break;
        }
    }
    if (stands)
        hold.addScore(Scores::FLUSH);

    return stands;
}

bool CardHandScorer::isStraight(CardHand &hand) {
    bool stands = true;
    hand.sortRank();
    for (int i = 0; i < hand.getSize()-1; i++) {
        if (hand.getCardValueAt(i+1) - hand.getCardValueAt(i) != 1)
            return stands;
    }
    hold.addScore(Scores::STRAIGHT);
    return stands;
}

bool CardHandScorer::isThreeOfAKind(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)] ++;
    }
    for (int i = 0; i < ranks::NUM_RANKS; i++) {
        if (count[i] >= 3)
        {
            hold.addScore(Scores::THREE_OF_A_KIND);
            break;
        }
    }

    return stands;
}

bool CardHandScorer::isTwoPair(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    int pairs = 0;
    for (int i = 0; i < hand.getSize(); i++) {
        count[hand.getCardValueAt(i)]++;
    }

    for(int i = 0; i < ranks::NUM_RANKS; i++) {
        if(count[i] >= 2) {
            pairs++;
            if(pairs >= 2) {
                hold.addScore(Scores::TWO_PAIR);
                break;
            }
        }
    }
    return stands;
}

bool CardHandScorer::isOnePair(CardHand &hand) {
    bool stands = true;
    int count[13] = {0};
    //int count[ranks::NUM_RANKS] = {0};
    for (int i = 0; i < hand.getSize(); i++)
    {
        count[hand.getCardValueAt(i)]++;
    }
    for(int i = 0; i < ranks::NUM_RANKS; i++)
    {
        if(count[i] >= 2)
        {
            hold.addScore(Scores::ONE_PAIR);
            break;
        }
    }
    return stands;
}

bool CardHandScorer::isHighCard(CardHand &hand) {
    hold.addScore(Scores::HIGH_CARD);
    return true;
}
