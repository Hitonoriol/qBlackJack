#include "bjwindow.h"
#include "ui_bjwindow.h"
#include "gamecontrols.h"
#include "betcontrols.h"

#include "resources.h"

#include "deck.h"
#include "hand.h"

#include <QGraphicsProxyWidget>
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>

BJWindow::BJWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::BJWindow),
    scene(new Scene)
{
    Resources::load();
    ui->setupUi(this);
    scene->setSceneRect(0, 0, ui->gameView->width(), ui->gameView->height());
    ui->gameView->fitInView(scene->sceneRect());

    blackJack = std::make_unique<BlackJack>(*scene);
    auto layout = new QGraphicsLinearLayout(Qt::Orientation::Vertical);
    auto form = new QGraphicsWidget;
    auto betControls = new BetControls(*blackJack);
    auto gameControls = new GameControls(*blackJack);
    layout->setSpacing(0);
    layout->setContentsMargins(0, 0, 0, 0);
    layout->addItem(scene->addWidget(betControls));
    layout->addItem(scene->addWidget(gameControls));
    form->setLayout(layout);
    scene->add(form);
    ui->gameView->setScene(scene);

    /* Mark scene origin */
    scene->addRect({0, 0, 10, 10}, QPen(Qt::black), QBrush(Qt::red));
}

BJWindow::~BJWindow()
{
    delete ui;
}


