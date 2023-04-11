#ifndef HAND_H
#define HAND_H

#include "card.h"
#include "deck.h"

#include <QGraphicsItem>
#include <QList>

class Hand : public QGraphicsItem
{
private:
    QList<std::shared_ptr<Card>> cards;

public:
    /* Draw `n` cards from the deck */
    void draw(Deck&, size_t n = 1);

    /* Get a reference to the last card drawn from the deck */
    Card& lastCard();

    /* Evaluate this hand's score */
    size_t evaluate();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;

    static constexpr size_t BLACKJACK = 21;
};

#endif // HAND_H
