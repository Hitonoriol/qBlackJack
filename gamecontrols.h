#ifndef GAMECONTROLS_H
#define GAMECONTROLS_H

#include "blackjack.h"

#include <QWidget>

namespace Ui {
class GameControls;
}

class GameControls : public QWidget
{
    Q_OBJECT

public:
    explicit GameControls(BlackJack&);
    ~GameControls();

private slots:
    void hit();
    void stand();

private:
    Ui::GameControls *ui;
    BlackJack &blackJack;
};

#endif // GAMECONTROLS_H
