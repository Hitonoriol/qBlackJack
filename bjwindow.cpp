#include "bjwindow.h"
#include "ui_bjwindow.h"

#include "resources.h"
#include "card.h"

BJWindow::BJWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BJWindow),
    scene(new QGraphicsScene)
{
    Resources::load();
    ui->setupUi(this);
    ui->gameView->setScene(scene);

    /* Test cards */
    auto cardA = new Card(Card::Suit::HEARTS, Card::Value::TEN);
    auto cardB = new Card(Card::Suit::SPADES, Card::Value::ACE);

    scene->addItem(cardA);
    scene->addItem(cardB);

    cardA->setPos(0, 0);
    cardB->setPos(100, 0);
}

BJWindow::~BJWindow()
{
    delete ui;
}


