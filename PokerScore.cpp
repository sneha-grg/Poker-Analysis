//
// Created by Sneha Gurung on 11/10/22.
//

#include "PokerScore.h"
#include <iostream>
float PokerScore::numChances[10] = {0};

PokerScore::PokerScore() = default;

void PokerScore::operator+=(const Scores &score) {
    this->addScore(score);
}

Scores& PokerScore::operator[](unsigned int index) {
    return scores[index];
}

void PokerScore::addScore(Scores score) {
    scores.push_back(score);
}

bool operator ==(const PokerScore& p, Scores score) {
    for (int i = 0; i < p.size(); i++) {
        if (p.getScoreAt(i) == score)
            return true;
    }
    return false;
}

int PokerScore::size() const {
    return scores.size();
}

Scores PokerScore::getScoreAt(int index) const {
    return scores[index];
}

std::string PokerScore::getPokerScore() {
    int temp[SIZE_SCORES] = {0};
    for (auto & score : scores) {
        switch (score) {
            case ROYAL_FLUSH:
                temp[ROYAL_FLUSH] += 1;
                break;
            case STRAIGHT_FLUSH:
                temp[STRAIGHT_FLUSH] += 1;
                break;
            case FOUR_OF_A_KIND:
                temp[FOUR_OF_A_KIND] += 1;
                break;
            case FULL_HOUSE:
                temp[FULL_HOUSE] += 1;
                break;
            case FLUSH:
                temp[FLUSH] += 1;
                break;
            case STRAIGHT:
                temp[STRAIGHT] += 1;
                break;
            case THREE_OF_A_KIND:
                temp[THREE_OF_A_KIND] += 1;
                break;
            case TWO_PAIR:
                temp[TWO_PAIR] += 1;
                break;
            case ONE_PAIR:
                temp[ONE_PAIR] += 1;
                break;
            case HIGH_CARD:
                temp[HIGH_CARD] += 1;
                break;
            default:
                break;
        }
    }

//    int num = 1000;

    std::string arr[] = {"ROYAL_FLUSH", "STRAIGHT_FLUSH", "FOUR_OF_A_KIND", "FULL_HOUSE", "FLUSH",
                         "STRAIGHT","THREE_OF_A_KIND", "TWO_PAIR", "ONE_PAIR", "HIGH_CARD"};

    for (int i = 0; i < SIZE_SCORES; i++){
        numChances[i] = (((float) temp[i] / (float) temp[9]) * 100);
        std::cout << arr[i] << ": " << temp[i] << std::endl;
    }

    return "";
}
