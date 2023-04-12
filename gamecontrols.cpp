#include "gamecontrols.h"
#include "ui_gamecontrols.h"

GameControls::GameControls(BlackJack &blackJack) :
    QWidget(),
    ui(new Ui::GameControls),
    blackJack(blackJack)
{
    ui->setupUi(this);
}

GameControls::~GameControls()
{
    delete ui;
}

void GameControls::hit()
{
    blackJack.hit();
}

void GameControls::stand()
{
    blackJack.stand();
}
