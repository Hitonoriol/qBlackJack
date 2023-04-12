#ifndef BJWINDOW_H
#define BJWINDOW_H

#include "blackjack.h"

#include "scene.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class BJWindow; }
QT_END_NAMESPACE

class BJWindow : public QMainWindow

{
    Q_OBJECT

public:
    BJWindow(QWidget *parent = nullptr);
    ~BJWindow();

private:
    Ui::BJWindow *ui;
    Scene *scene;
    std::unique_ptr<BlackJack> blackJack;
};

#endif // BJWINDOW_H
