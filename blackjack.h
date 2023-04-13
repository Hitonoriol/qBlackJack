#ifndef BLACKJACK_H
#define BLACKJACK_H

#include "deck.h"
#include "hand.h"

class BlackJack
{
public:
    enum class GameState
    {
        None,       // Only used as initial `state` value before the first game
        InProgress,
        Bust,       // When player's total is >21
        Loss,       // When dealer has a better hand
        Win,        // When player has a better hand
        BlackJack,  // When player's two initial cards are worth 21
        Push        // When player and dealer have equivalent hands
    };

private:
    GameState state = GameState::None;
    Deck deck;

    /* Dealer's & player's hands.
     * Safe to allocate via `new` because they will be owned by `QGraphicsScene`,
     * not by this class.
     *
     * TODO: Make hands and cards non-Qt objects and create separate
     * `HandView` and `CardView` classes for displaying them graphically.
     */
    Hand *dealer;
    Hand *player;

    int balance = 100;
    int bet = 0;

    /* Score after which dealer stops drawing cards from the deck */
    size_t dealerThreshold = 17;

    void startGame();
    void checkGameEndConditions();

public:
    BlackJack();

    bool placeBet(int amount);

    void hit();
    void stand();

    int getBalance();
    int getBet();

    GameState getGameState();
    bool isGameInProgress();

    int winAmount();

    Hand& getDealerHand();
    Hand& getPlayerHand();

    static constexpr size_t BJ = 21;
};

#endif // BLACKJACK_H
