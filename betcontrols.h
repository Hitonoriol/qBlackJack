#ifndef BETCONTROLS_H
#define BETCONTROLS_H

#include "blackjack.h"

#include <QWidget>

namespace Ui {
class BetControls;
}

class BetControls : public QWidget
{
    Q_OBJECT

public:
    explicit BetControls(BlackJack&);
    ~BetControls();

    void balanceUpdated();

private slots:
    void placeBet();

private:
    Ui::BetControls *ui;
    BlackJack &blackJack;
};

#endif // BETCONTROLS_H
