#ifndef CARD_H
#define CARD_H

#include "spritesheet.h"

#include <QGraphicsItem>

class Card : public QGraphicsItem
{
public:
    enum class Rank
    {
        TWO,
        THREE,
        FOUR,
        FIVE,
        SIX,
        SEVEN,
        EIGHT,
        NINE,
        TEN,
        JACK,
        QUEEN,
        KING,
        ACE
    };

    enum class Suit
    {
        HEARTS,
        DIAMONDS,
        CLUBS,
        SPADES,
        HIDDEN
    };

private:
    Suit suit;
    Rank rank;
    bool visible = true;

public:
    Card(Suit, Rank);
    Card(size_t suitIdx, size_t rankIdx);

    /* Get this card's score worth. Always 11 for Ace. */
    size_t getScore();

    Rank getRank();
    Suit getSuit();

    /* Get this card's visibility state - if it's not visible, the backside is displayed. */
    bool isVisible();

    void setVisible(bool);
    void hide();
    void show();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    QRectF boundingRect() const override;

    static constexpr size_t SUITS = static_cast<size_t>(Suit::SPADES) + 1;
    static constexpr size_t RANKS = static_cast<size_t>(Rank::ACE) + 1;

    inline static Rank toRank(size_t rank_idx)
    {
        if (rank_idx >= RANKS)
            throw std::runtime_error("Invalid rank index");

        return static_cast<Rank>(rank_idx);
    }

    inline static Suit toSuit(size_t suit_idx)
    {
        if (suit_idx >= SUITS)
            throw std::runtime_error("Invalid suit index");

        return static_cast<Suit>(suit_idx);
    }

    inline static size_t toIdx(Suit suit)
    {
        return static_cast<size_t>(suit);
    }

    inline static size_t toIdx(Rank rank)
    {
        return static_cast<size_t>(rank);
    }
};

#endif // CARD_H