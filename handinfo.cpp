#include "handinfo.h"
#include "ui_handinfo.h"

#include "hand.h"
#include "resources.h"

HandInfo::HandInfo(Hand &hand) :
    QWidget(),
    ui(new Ui::HandInfo),
    hand(hand)
{
    ui->setupUi(this);
}

HandInfo::~HandInfo()
{
    delete ui;
}

void HandInfo::handUpdated()
{
    ui->infoLabel->setText(Resources::handString.arg(
        hand.lastCard().isVisible() ? hand.evaluate() : hand.firstCard().getScore()
    ));
}