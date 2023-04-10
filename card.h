#ifndef CARD_H
#define CARD_H

#include "spritesheet.h"

#include <QGraphicsItem>

class Card : public QGraphicsItem
{
public:
    enum class Value
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
        SPADES
    };

private:
    Suit suit;
    Value value;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

public:
    Card(Suit suit, Value value);

    size_t getValue();
};

#endif // CARD_H
