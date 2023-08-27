cmake_minimum_required(VERSION 3.23)
project(Poker)

set(CMAKE_CXX_STANDARD 14)

add_executable(Poker main.cpp Deck.cpp Deck.h Card.cpp Card.h suits.h ranks.h CardHand.cpp
        CardHand.h Scores.h CardHandScorer.cpp CardHandScorer.h PokerScore.cpp PokerScore.h DrawCard.cpp
        DrawCard.h SFML_hand.cpp SFML_hand.h PokerRankings.cpp PokerRankings.h)

target_link_libraries(Poker sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)
