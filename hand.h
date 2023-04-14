#ifndef HAND_H
#define HAND_H

#include "card.h"
#include "deck.h"

#include <QGraphicsObject>
#include <QList>

class Hand : public QGraphicsObject
{
private:
    Q_OBJECT

    static constexpr int DRAW_DELAY = 275;

    QList<std::shared_ptr<Card>> cards;
    int cardsDrawing = 0;

    void add(std::shared_ptr<Card>);

public:
    Hand();

    /* Draw `n` cards from the deck */
    void draw(Deck&, size_t n = 1);

    /* Get a reference to the first/last card drawn from the deck */
    Card& lastCard();
    Card& firstCard();

    /* Evaluate this hand's score */
    size_t evaluate();

    /* Remove all cards from this hand */
    void clear();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    QRectF boundingRect() const;
};

#endif // HAND_H
