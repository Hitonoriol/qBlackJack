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
#include <QScrollBar>
#include <QFileDialog>

BJWindow::BJWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BJWindow),
    scene(new Scene),
    blackJack(std::make_unique<BlackJack>())
{
    Resources::load();
    ui->setupUi(this);
    ui->gameView->verticalScrollBar()->blockSignals(true);

    betControls = new BetControls(*this);
    gameControls = new GameControls(*this);
    gameInfo = new GameInfo(*this);
    dealerHandInfo = new HandInfo(blackJack->getDealerHand());
    playerHandInfo = new HandInfo(blackJack->getPlayerHand());
    showBetControls();

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

void BJWindow::doStartGame(int bet)
{
    resetCards();
    playerHandInfo->handIsUpdating();
    dealerHandInfo->handIsUpdating();
    if (blackJack->startGame(bet, [this]{gameStarted();})) {
        Resources::audio->playBetSound();
        showGameControls();
        disableControls();
    }
    else
        Dialog::error("Error", "Bet amount is invalid!");
}

void BJWindow::gameStarted()
{
    qDebug() << "Game started!";
    enableControls();
    gameInfo->infoUpdated();
    playerHandInfo->handUpdated();
    dealerHandInfo->handUpdated();
    if (!blackJack->isGameInProgress())
        gameEnded();
}

void BJWindow::doHit()
{
    Resources::audio->playClickSound();
    playerHandInfo->handIsUpdating();
    disableControls();
    blackJack->hit([this] {
        playerHandInfo->handUpdated();
        dealerHandInfo->handUpdated();
        enableControls();
        if (!blackJack->isGameInProgress())
            gameEnded();
    });
    scene->center();
    gameSceneResized();
}

void BJWindow::doStand()
{
    Resources::audio->playClickSound();
    notify("Dealer's turn");
    dealerHandInfo->handIsUpdating();
    disableControls();
    blackJack->stand([this] {
        update();
        playerHandInfo->handUpdated();
        dealerHandInfo->handUpdated();
        gameEnded();
    });
    scene->center();
    gameSceneResized();
}

void BJWindow::gameEnded()
{
    if (blackJack->getBalance() > 0)
        enableControls();

    showBetControls();
    betControls->balanceUpdated();
    gameInfo->infoUpdated();

    switch(blackJack->getGameState()) {
    case BlackJack::GameState::Bust:
        Dialog::warning(
            "Bust",
            notify(Resources::bustMsg.arg(blackJack->getBet()))
        );
        break;

    case BlackJack::GameState::Loss:
        Dialog::warning(
            "Loss",
            notify(Resources::lossMsg.arg(blackJack->getBet()))
        );
        break;

    case BlackJack::GameState::Push:
        Dialog::info(
            "Push",
            notify(Resources::pushMsg)
        );
        break;

    case BlackJack::GameState::BlackJack:
        Dialog::info(
            "BlackJack",
            notify(Resources::winMsg.arg(blackJack->winAmount()))
        );
        break;

    case BlackJack::GameState::Win:
        Dialog::info(
            "Win",
            notify(Resources::winMsg.arg(blackJack->winAmount()))
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

void BJWindow::showGameControls(bool show)
{
    notify(show ? "Your turn." : "Place a bet to begin the game.");
    gameControls->setVisible(show);
    betControls->setVisible(!show);
}

void BJWindow::showBetControls()
{
    showGameControls(false);
}

void BJWindow::enableControls(bool value)
{
    gameControls->setEnabled(value);
    betControls->setEnabled(value);
}

void BJWindow::disableControls()
{
    enableControls(false);
}

void BJWindow::resetCards()
{
    blackJack->getDealerHand().prepareToDraw();
    blackJack->getPlayerHand().prepareToDraw();
}

void BJWindow::gameSceneResized()
{
    auto width = ui->gameView->width();
    auto height = ui->gameView->height();
    scene->setSceneRect(-width / 2, 0, width, height);
    ui->gameView->fitInView(scene->itemsBoundingRect(), Qt::AspectRatioMode::KeepAspectRatio);
    ui->gameView->centerOn(0, 0);
}

const QString& BJWindow::notify(const QString &message)
{
    ui->statusbar->showMessage(message);
    return message;
}

void BJWindow::doChangeCardSkin()
{
    auto fileName = QFileDialog::getOpenFileName(this,
        "Open Card Skin",
        "./",
        "Image Files (*.png *.jpg *.bmp)"
    );
    try {
        QFile sheetFile(fileName);
        if (!fileName.isEmpty() && sheetFile.exists())
            Resources::loadCardSheet(fileName);
        else
            Dialog::error("Error", "Couldn't open specified card skin file");
    } catch (...) {
        Dialog::error("Error", "An exception has occurred while trying to load the card skin");
        Resources::resetCardSheet();
    }
    scene->update();
}

void BJWindow::doResetSkin()
{
    Resources::resetCardSheet();
    scene->update();
}

void BJWindow::doResetGame()
{
    if (blackJack->isGameInProgress()) {
        showBetControls();
        resetCards();
    }

    enableControls();
    blackJack->resetBalance();
    gameInfo->infoUpdated();
    betControls->balanceUpdated();
}

void BJWindow::doSetMusicEnabled(bool enabled)
{
    auto &player = Resources::audio->getBgMusicPlayer();
    if (!enabled)
        player.stop();
    else
        player.play();
}

void BJWindow::doSetSoundEffectsEnabled(bool enabled)
{
    Resources::audio->enableSoundEffects(enabled);
}


