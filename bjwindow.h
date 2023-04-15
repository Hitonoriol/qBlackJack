#ifndef BJWINDOW_H
#define BJWINDOW_H

#include "blackjack.h"

#include "scene.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BJWindow; }
QT_END_NAMESPACE

class BetControls;
class GameControls;
class GameInfo;
class HandInfo;

class BJWindow : public QMainWindow
{
    Q_OBJECT

public:
    BJWindow(QWidget *parent = nullptr);
    ~BJWindow();

    void resizeEvent(QResizeEvent*) override;

    void doStartGame(int bet);
    void gameStarted();
    void doHit();
    void doStand();
    void gameEnded();

    BlackJack &getBlackJack();

private:
    Ui::BJWindow *ui;
    Scene *scene;

    std::unique_ptr<BlackJack> blackJack;
    BetControls *betControls;
    GameControls *gameControls;
    GameInfo *gameInfo;
    HandInfo *dealerHandInfo, *playerHandInfo;

    static constexpr double LABEL_PADDING = 30;

    void showGameControls(bool show = true);
    void showBetControls();
    void enableControls(bool value = true);
    void disableControls();

    void resetCards();

    void gameSceneResized();

    const QString& notify(const QString&);

private slots:
    void doChangeCardSkin();
    void doResetSkin();
    void doResetGame();
};

#endif // BJWINDOW_H
