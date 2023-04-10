#include "card.h"

#include "resources.h"

#include <QtMath>

Card::Card(Suit suit, Value value)
    : suit(suit), value(value) {}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Resources::cardSheet->paintRegion(
        painter,
        pos(),
        static_cast<size_t>(value),
        static_cast<size_t>(suit)
    );
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Card::boundingRect() const
{
    return Resources::cardSheet->boundingRect();
}

size_t Card::getValue()
{
    return qMax(10u, static_cast<size_t>(value) + 2);
}

