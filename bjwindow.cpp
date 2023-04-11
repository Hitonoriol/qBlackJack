#include "bjwindow.h"
#include "ui_bjwindow.h"

#include "resources.h"

#include "deck.h"
#include "hand.h"

BJWindow::BJWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BJWindow),
    scene(new QGraphicsScene)
{
    Resources::load();
    ui->setupUi(this);
    ui->gameView->setScene(scene);

    /* Test `Deck` and `Hand` abstractions */
    Deck deck;
    auto handA = new Hand, handB = new Hand;

    handA->draw(deck, 3);
    handB->draw(deck, 2);
    handA->lastCard().hide();

    handB->setY(-Resources::cardSheet->getRegionHeight());

    scene->addItem(handA);
    scene->addItem(handB);
}

BJWindow::~BJWindow()
{
    delete ui;
}


