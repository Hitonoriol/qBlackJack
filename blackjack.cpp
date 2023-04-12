#include "blackjack.h"
#include "resources.h"

#include <QMessageBox>

BlackJack::BlackJack(Scene &scene)
    : dealer(new Hand), player(new Hand)
{
    scene.add(dealer);
    scene.add(player);
}

void BlackJack::placeBet(int amount)
{
    if (amount > balance || amount <= 0) {
        QMessageBox::warning(
            nullptr, "Error",
            "Bet amount is invalid!",
            QMessageBox::Ok
        );
        return;
    }

    balance -= amount;
    bet = amount;
    startGame();
}

int BlackJack::getBalance()
{
    return balance;
}

void BlackJack::startGame()
{
    deck.reset();
    dealer->clear();
    player->clear();
    dealer->draw(deck);
    player->draw(deck);
    dealer->draw(deck);
    dealer->lastCard().hide();
}

