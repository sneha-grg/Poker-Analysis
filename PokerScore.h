//
// Created by Sneha Gurung on 11/10/22.
//

#ifndef POKER_POKERSCORE_H
#define POKER_POKERSCORE_H
#include "vector"
#include "Scores.h"
#include <iostream>

class PokerScore {
private:
    std::vector<Scores> scores;

public:
//    int temp[SIZE_SCORES] = {0};
    PokerScore();
    std::string getPokerScore();
    int size() const;
    void operator += (const Scores& score);
    friend bool operator ==(const PokerScore& p, Scores score);
    Scores& operator[](unsigned int index);
    void addScore(Scores score);
    Scores getScoreAt(int index) const;
    static float numChances[10];
};


#endif //POKER_POKERSCORE_H
