//
// Created by Sneha Gurung on 11/6/22.
//

#include "Deck.h"

Deck::Deck() : cardIndex(0)
{
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck[cardIndex] = Card(static_cast<suits>(i), static_cast<ranks>(j));
            cardIndex++;
        }
    }
    cardIndex = 0;
}

bool Deck::empty() {
    if (cardIndex > DECK_SIZE)
        return true;
    return false;
}

void Deck::shuffle() {
    cardIndex = 0;
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % 52;
        Card swap = deck[i];
        deck[i] = deck[r];
        deck[r] = swap;
    }
}

Card Deck::dealCard() {
    if (!empty()) {
        Card card = deck[cardIndex];
        cardIndex++;
        return card;
    }
    Card card;
    return card;
}

Card Deck::getCardAt(int index) {
    return deck[index];
}

void Deck::printDeck()
{
    for (int i = 0; i < 52; i++) {
        std::cout << i+1 << ": " << getCardAt(i);
    }
}
