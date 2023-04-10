
#ifndef BJWINDOW_H
#define BJWINDOW_H

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
};

#endif // BJWINDOW_H
