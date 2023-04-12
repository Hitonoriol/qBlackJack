#include "hand.h"
#include "resources.h"

void Hand::draw(Deck &deck, size_t n)
{
    for (size_t i = 0; i < n; ++i)
        cards.append(deck.nextCard());
    update();
}

Card &Hand::lastCard()
{
    return *cards.last();
}

size_t Hand::evaluate()
{
    size_t score = 0;
    for (auto card : cards) {
        auto worth = card->getScore();
        if (card->getRank() == Card::Rank::ACE) {
            if (score + worth > BLACKJACK)
                worth = 1;
        }
        score += worth;
    }
    return score;
}

void Hand::clear()
{
    cards.clear();
    update();
}

void Hand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    auto x = pos().x();
    for (auto card : cards) {
        card->setX(x);
        card->paint(painter, option, widget);
        x += Resources::cardSheet->getRegionWidth();
    }
}

QRectF Hand::boundingRect() const
{
    double width = cards.size() * Resources::cardSheet->getRegionWidth();
    double height = Resources::cardSheet->getRegionHeight();
    return {0, 0, width, height};
}

