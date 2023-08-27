//
// Created by Sneha Gurung on 11/6/22.
//

#include "Card.h"

/* CONSTRUCTORS */

Card::Card() : Card(HEARTS, TEN) { }

Card::Card(const Card& other) : Card(other.suit, other.value) { }

Card::Card(suits suit, ranks value) : value(value), suit(suit) { }

std::ostream& operator <<(std::ostream& outs, const Card& card)
{
    outs << card.getRank() << " of " << card.getSuit() << std::endl;
    return outs;
}

/* CONVERSION FUNCTIONS - String */

std::string Card::rankToString() const {
    switch (value) {
        case ACE: return "Ace";
        case KING: return "King";
        case QUEEN: return "Queen";
        case JACK: return "Jack";
        case TEN: return "Ten";
        case NINE: return "Nine";
        case EIGHT: return "Eight";
        case SEVEN: return "Seven";
        case SIX: return "Six";
        case FIVE: return "Five";
        case FOUR: return "Four";
        case THREE: return "Three";
        case TWO: return "Two";
        default: return "Error";
    }
}

std::string Card::suitToString() const{
    switch (suit) {
        case HEARTS: return "Hearts";
        case DIAMONDS: return "Diamonds";
        case CLUBS: return "Clubs";
        case SPADES: return "Spades";
    }
}

/* CONVERSION FUNCTION - Int */

int Card::getRankInt() const {
    switch (value) {
        case TWO: return 2;
        case THREE: return 3;
        case FOUR: return 4;
        case FIVE: return 5;
        case SIX: return 6;
        case SEVEN: return 7;
        case EIGHT: return 8;
        case NINE: return 9;
        case TEN: return 10;
        case JACK: return 11;
        case QUEEN: return 12;
        case KING: return 13;
        case ACE: return 14;
        default: return -1;
    }
}

/* GETTER FUNCTIONS */

suits Card::getSuit() const {
    return suit;
}

ranks Card::getRank() const {
    return value;
}

/* SETTER FUNCTIONS */

void Card::setSuit(suits newSuit) {
    this->suit = newSuit;
}

void Card::setRank(ranks newValue) {
    this->value = newValue;
}
