#include "card.h"

#include "resources.h"

#include <QtMath>

Card::Card(Suit suit, Rank value)
    : suit(suit), rank(value) {}

Card::Card(size_t suitIdx, size_t rankIdx)
    : Card(toSuit(suitIdx), toRank(rankIdx)) {}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    auto rank_idx = visible ? toIdx(rank) : 0u;
    auto suit_idx = toIdx(visible ? suit : Suit::HIDDEN);
    Resources::cardSheet->paintRegion(
        painter,
        pos(),
        rank_idx,
        suit_idx
    );
    Q_UNUSED(option)
    Q_UNUSED(widget)
}

QRectF Card::boundingRect() const
{
    return Resources::cardSheet->boundingRect();
}

size_t Card::getScore()
{
    if (rank == Rank::ACE)
        return 11u;

    return qMin(10u, toIdx(rank) + 2);
}

Card::Rank Card::getRank()
{
    return rank;
}

Card::Suit Card::getSuit()
{
    return suit;
}

bool Card::isVisible()
{
    return visible;
}

void Card::setVisible(bool value)
{
    visible = value;
}

void Card::hide()
{
    setVisible(false);
}

void Card::show()
{
    setVisible(true);
}

