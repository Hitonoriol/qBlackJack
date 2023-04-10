
#ifndef BJWINDOW_H
#define BJWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>


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
    QGraphicsScene *scene;
};

#endif // BJWINDOW_H
