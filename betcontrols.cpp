#include "betcontrols.h"
#include "ui_betcontrols.h"

BetControls::BetControls(BlackJack &blackJack) :
    QWidget(),
    ui(new Ui::BetControls),
    blackJack(blackJack)
{
    ui->setupUi(this);
    ui->betSlider->setMinimum(1);
    ui->betSpinBox->setMinimum(1);
    balanceUpdated();
}

BetControls::~BetControls()
{
    delete ui;
}

void BetControls::balanceUpdated()
{
    auto balance = blackJack.getBalance();
    ui->betSlider->setMaximum(balance);
    ui->betSpinBox->setMaximum(balance);
}

void BetControls::placeBet()
{
    qDebug() << "placeBet()";
    blackJack.placeBet(ui->betSlider->value());
}
