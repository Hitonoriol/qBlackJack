#include "blackjack.h"
#include "resources.h"

#include <QMessageBox>

BlackJack::BlackJack()
    : dealer(new Hand), player(new Hand) {}

bool BlackJack::placeBet(int amount)
{
    if (amount > balance || amount <= 0)
        return false;

    balance -= amount;
    bet = amount;
    startGame();
    return true;
}

void BlackJack::hit()
{
    player->draw(deck);
    auto score = player->evaluate();
    qDebug() << "Drew a card worth" << player->lastCard().getScore() << "; Total:" << score;
    if (score > BJ)
        state = GameState::Bust;
}

void BlackJack::stand()
{
    dealer->lastCard().show();
    while (dealer->evaluate() < dealerThreshold)
        dealer->draw(deck);
    checkGameEndConditions();
}

int BlackJack::getBalance()
{
    return balance;
}

int BlackJack::getBet()
{
    return bet;
}

BlackJack::GameState BlackJack::getGameState()
{
    return state;
}

bool BlackJack::isGameInProgress()
{
    return state == GameState::InProgress;
}

int BlackJack::winAmount()
{
    switch(state) {
    case GameState::BlackJack:
        return bet * 2.5;

    case GameState::Win:
        return bet * 2;

    case GameState::Push:
        return bet;

    default:
        return 0;
    }
}

Hand &BlackJack::getDealerHand()
{
    return *dealer;
}

Hand &BlackJack::getPlayerHand()
{
    return *player;
}

void BlackJack::startGame()
{
    state = GameState::InProgress;
    deck.reset();
    dealer->clear();
    player->clear();
    dealer->draw(deck);
    player->draw(deck);
    dealer->draw(deck);
    dealer->lastCard().hide();
    player->draw(deck);

    if (player->evaluate() == BJ) {
        state = GameState::BlackJack;
        balance += winAmount();
    }
}

void BlackJack::checkGameEndConditions()
{
    auto playerScore = player->evaluate();
    auto dealerScore = dealer->evaluate();

    qDebug() << "Ending the game. Dealer has:" << dealerScore << "; player has:" << playerScore;

    if (playerScore > BJ)
        state = GameState::Bust;

    else if (dealerScore > BJ || dealerScore < playerScore)
        state = GameState::Win;

    else if (dealerScore > playerScore)
        state = GameState::Loss;

    else if (dealerScore == playerScore)
        state = GameState::Push;

    balance += winAmount();
}

