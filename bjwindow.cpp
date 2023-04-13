#include "bjwindow.h"
#include "ui_bjwindow.h"

#include "resources.h"
#include "dialogs.h"

#include "gamecontrols.h"
#include "betcontrols.h"
#include "gameinfo.h"
#include "handinfo.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>

BJWindow::BJWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BJWindow),
    scene(new Scene),
    blackJack(std::make_unique<BlackJack>())
{
    Resources::load();
    ui->setupUi(this);

    betControls = new BetControls(*this);
    gameControls = new GameControls(*this);
    gameInfo = new GameInfo(*this);
    dealerHandInfo = new HandInfo(blackJack->getDealerHand());
    playerHandInfo = new HandInfo(blackJack->getPlayerHand());
    gameControls->hide();

    /* Populate the game scene */
    scene->append(scene->addWidget(gameInfo)).pad(LABEL_PADDING);
    scene->append(&blackJack->getDealerHand());
    scene->append(scene->addWidget(dealerHandInfo)).pad(LABEL_PADDING);
    scene->append(&blackJack->getPlayerHand());
    scene->append(scene->addWidget(playerHandInfo)).pad(LABEL_PADDING);
    scene->add(scene->addWidget(betControls));
    scene->append(scene->addWidget(gameControls));
    ui->gameView->setScene(scene);

    show();
    gameSceneResized();
}

BJWindow::~BJWindow()
{
    delete ui;
}

void BJWindow::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event);
    gameSceneResized();
}

void BJWindow::startGame(int bet)
{
    if (blackJack->placeBet(bet))
        gameStarted();
    else
        Dialog::error("Error", "Bet amount is invalid!");
}

void BJWindow::gameStarted()
{
    betControls->hide();
    gameControls->show();
    gameInfo->infoUpdated();
    playerHandInfo->handUpdated();
    dealerHandInfo->handUpdated();
    scene->center();
    if (!blackJack->isGameInProgress())
        gameEnded();
}

void BJWindow::doHit()
{
    blackJack->hit();
    playerHandInfo->handUpdated();
    dealerHandInfo->handUpdated();
    scene->center();
    gameSceneResized();
    if (!blackJack->isGameInProgress())
        gameEnded();
}

void BJWindow::doStand()
{
    gameControls->setDisabled(true);
    blackJack->stand();
    playerHandInfo->handUpdated();
    dealerHandInfo->handUpdated();
    scene->center();
    gameSceneResized();
    gameEnded();
}

void BJWindow::gameEnded()
{
    gameControls->setDisabled(false);
    gameControls->hide();
    betControls->balanceUpdated();
    betControls->show();
    gameInfo->infoUpdated();
    switch(blackJack->getGameState()) {
    case BlackJack::GameState::Bust:
        Dialog::warning(
            "Bust",
            "You busted and lost $" + QString::number(blackJack->getBet())
        );
        break;

    case BlackJack::GameState::Loss:
        Dialog::warning(
            "Loss",
            "You lost $" + QString::number(blackJack->getBet())
        );
        break;

    case BlackJack::GameState::Push:
        Dialog::info(
            "Push",
            "Dealer has an equivalent hand. Your bet is refunded."
        );
        break;

    case BlackJack::GameState::BlackJack:
        Dialog::info(
            "BlackJack",
            "Congratulations! You won $" + QString::number(blackJack->winAmount())
        );
        break;

    case BlackJack::GameState::Win:
        Dialog::info(
            "Win",
            "Congratulations! You won $" + QString::number(blackJack->winAmount())
        );
        break;

    default:
        break;
    }
}

BlackJack &BJWindow::getBlackJack()
{
    return *blackJack;
}

void BJWindow::gameSceneResized()
{
    auto width = ui->gameView->width();
    auto height = ui->gameView->height();
    scene->setSceneRect(-width / 2, 0, width, height);
    ui->gameView->fitInView(scene->itemsBoundingRect(), Qt::AspectRatioMode::KeepAspectRatio);
    ui->gameView->centerOn(0, 0);
}


