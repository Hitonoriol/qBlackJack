#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "hand.h"

#include "scene.h"

class BlackJack
{
private:
    Deck deck;

    /* Dealer's & player's hands.
     * Safe to allocate via `new` because they will be owned by `QGraphicsScene`,
     * not by this class. */
    Hand *dealer;
    Hand *player;

    int balance = 100;
    int bet;

    void startGame();

public:
    BlackJack(Scene&);

    void placeBet(int amount);

    void hit();
    void stand();

    int getBalance();
};

#endif // BLACKJACK_H
