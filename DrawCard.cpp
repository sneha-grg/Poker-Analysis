//
// Created by Sneha Gurung on 11/14/22.
//

#include "DrawCard.h"
#include <string>

sf::Texture DrawCard::texture;
sf::Font DrawCard::font;
sf::Texture DrawCard::Hearts;
sf::Texture DrawCard::Spades;
sf::Texture DrawCard::Diamonds;
sf::Texture DrawCard::Clubs;

DrawCard::DrawCard() : DrawCard(HEARTS, ACE)
{
    initialize();
}

DrawCard::DrawCard(suits suit, ranks rank) : _suit(suit), _rank(rank)
{
    initialize();
}

void DrawCard::draw(sf::RenderTarget &window, sf::RenderStates states) const
{
    window.draw(background), window.draw(suit), window.draw(rank), window.draw(rank2);
    window.draw(RoyalFlush), window.draw(StraightFlush), window.draw(FourOfAKind);
    window.draw(FullHouse), window.draw(FullHouse), window.draw(Flush);
    window.draw(Straight), window.draw(ThreeOfAKind), window.draw(TwoPair);
    window.draw(Pair), window.draw(HighCard);
}

std::string DrawCard::rankToString()
{
    switch (_rank) {
        case ACE: return "A";
        case KING: return "K";
        case QUEEN: return "Q";
        case JACK: return "J";
        case TEN: return "10";
        case NINE: return "9";
        case EIGHT: return "8";
        case SEVEN: return "7";
        case SIX: return "6";
        case FIVE: return "5";
        case FOUR: return "4";
        case THREE: return "3";
        case TWO: return "2";
        default: return "Error";
    }
}

std::string DrawCard::suitToString()
{
    switch (_suit) {
        case HEARTS: return "Image/heart.png";
        case DIAMONDS: return "Image/diamonds.png";
        case CLUBS: return "Image/club.png";
        case SPADES: return "Image/spades.png";
        default: return "Error";
    }
}

void DrawCard::initialize()
{
    setText();
    setUpBackground();
    setUpRank();
    setUpSuit();
}

void DrawCard::setUpBackground()
{
    background.setSize({100, 150});
    background.setPosition({150, 200});
}

void DrawCard::setUpRank()
{
    if (!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(20);
    rank.setFont(font);
    rank.setString(rankToString());
    rank.setFillColor(sf::Color::Black);
    rank.setCharacterSize(30);
    rank2.setFont(font);
    rank2.setString(rankToString());
    rank2.setFillColor(sf::Color::Black);
    rank2.setCharacterSize(30);
    positionRank();
    rank2.rotate(180);
}

void DrawCard::positionSuit() {
    suit.setPosition({bounds().left + bounds().width/4,bounds().top + bounds().height/3});
}

void DrawCard::positionRank() {
    rank.setPosition({bounds().left, bounds().top});
    rank2.setPosition({bounds().left + bounds().width,bounds().top + bounds().height});
}

void DrawCard::setUpSuit()
{
    if (!texture.loadFromFile(suitToString()))
        exit(21);

    if (_suit == SPADES) {
        Spades.loadFromFile(suitToString());
        suit.setTexture(Spades);
        suit.setScale({0.7, 0.7});
        positionSuit();
    }

    if (_suit == DIAMONDS) {
        Diamonds.loadFromFile(suitToString());
        rank.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
        suit.setTexture(Diamonds);
        suit.setScale(0.14, 0.14);
        positionSuit();
    }

    if (_suit == HEARTS) {
        Hearts.loadFromFile(suitToString());
        rank.setFillColor(sf::Color::Red);
        rank2.setFillColor(sf::Color::Red);
        suit.setTexture(Hearts);
        suit.setScale({0.7, 0.7});
        positionSuit();
    }

    if (_suit == CLUBS) {
        Clubs.loadFromFile(suitToString());
        suit.setTexture(Clubs);
        suit.setScale({0.7, 0.7});
        positionSuit();
    }
}

void DrawCard::setFillColor(const sf::Color &color) {
    setFillColor(color);
}

void DrawCard::setSize(sf::Vector2f size) {
    setSize(size);
}

void DrawCard::setSize(float width, float height) {
    setSize(width, height);
}

void DrawCard::setPosition(float x, float y) {
    setPosition({x, y});
}

void DrawCard::setPosition(sf::Vector2f position) {
    background.setPosition(position);
    positionSuit();
    positionRank();
}

sf::FloatRect DrawCard::bounds() {
    return background.getGlobalBounds();
}

void DrawCard::setText() {
    if (!font.loadFromFile("Fonts/OpenSans-Bold.ttf"))
        exit(20);

    /* Left side Column */
    RoyalFlush.setPosition({50, 50});
    RoyalFlush.setFont(font);
    RoyalFlush.setString("Royal Flush\nProbability: " + std::to_string(scoreObj.numChances[0]) + "%");
    RoyalFlush.setFillColor(sf::Color(250, 132, 226));
    RoyalFlush.setCharacterSize(35);

    StraightFlush.setPosition({50, 300});
    StraightFlush.setFont(font);
    StraightFlush.setString("Straight Flush\nProbability: " + std::to_string(scoreObj.numChances[1]) + "%");
    StraightFlush.setFillColor(sf::Color(250, 132, 226));
    StraightFlush.setCharacterSize(35);

    FourOfAKind.setPosition({50, 550});
    FourOfAKind.setFont(font);
    FourOfAKind.setString("Four of a kind\nProbability: " + std::to_string(scoreObj.numChances[2]) + "%");
    FourOfAKind.setFillColor(sf::Color(250, 132, 226));
    FourOfAKind.setCharacterSize(35);

    FullHouse.setPosition({50, 800});
    FullHouse.setFont(font);
    FullHouse.setString("Full House\nProbability: " + std::to_string(scoreObj.numChances[3]) + "%");
    FullHouse.setFillColor(sf::Color(250, 132, 226));
    FullHouse.setCharacterSize(35);

    Flush.setPosition({50, 1050});
    Flush.setFont(font);
    Flush.setString("Flush\nProbability: " + std::to_string(scoreObj.numChances[4]) + "%");
    Flush.setFillColor(sf::Color(250, 132, 226));
    Flush.setCharacterSize(35);

    /* Right side Column */
    Straight.setPosition({1800, 50});
    Straight.setFont(font);
    Straight.setString("Straight\nProbability: " + std::to_string(scoreObj.numChances[5]) + "%");
    Straight.setFillColor(sf::Color(250, 132, 226));
    Straight.setCharacterSize(35);

    ThreeOfAKind.setPosition({1800, 300});
    ThreeOfAKind.setFont(font);
    ThreeOfAKind.setString("Three of a Kind\nProbability: " + std::to_string(scoreObj.numChances[6]) + "%");
    ThreeOfAKind.setFillColor(sf::Color(250, 132, 226));
    ThreeOfAKind.setCharacterSize(35);

    TwoPair.setPosition({1800, 550});
    TwoPair.setFont(font);
    TwoPair.setString("Two Pair\nProbability: " + std::to_string(scoreObj.numChances[7]) + "%");
    TwoPair.setFillColor(sf::Color(250, 132, 226));
    TwoPair.setCharacterSize(35);

    Pair.setPosition({1800, 800});
    Pair.setFont(font);
    Pair.setString("Pair\nProbability: " + std::to_string(scoreObj.numChances[8]) + "%");
    Pair.setFillColor(sf::Color(250, 132, 226));
    Pair.setCharacterSize(35);

    HighCard.setPosition({1800, 1050});
    HighCard.setFont(font);
    HighCard.setString("High Card\nProbability: " + std::to_string(scoreObj.numChances[9]) + "%");
    HighCard.setFillColor(sf::Color(250, 132, 226));
    HighCard.setCharacterSize(35);
}
