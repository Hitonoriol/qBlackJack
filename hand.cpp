#include "hand.h"
#include "resources.h"
#include "blackjack.h"

Hand::Hand()
{
    auto emptyCard = std::make_shared<Card>(Card::Suit::CLUBS, Card::Rank::ACE);
    emptyCard->hide();
    cards.append(emptyCard);
}

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

Card &Hand::firstCard()
{
    return *cards.first();
}

size_t Hand::evaluate()
{
    size_t score = 0;
    size_t aces = 0;
    for (auto card : cards) {
        auto worth = card->getScore();
        if (card->getRank() == Card::Rank::ACE) {
            ++aces;
            continue;
        }
        score += worth;
    }
    for (size_t i = 0; i < aces; ++i)
        score += score + 11 > BlackJack::BJ ? 1 : 11;
    return score;
}

void Hand::clear()
{
    cards.clear();
    update();
}

void Hand::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    auto x = 0;
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

