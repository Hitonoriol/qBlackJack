#ifndef QUTIL_H
#define QUTIL_H

#include <QGraphicsScene>
#include <QGraphicsObject>
#include <QPropertyAnimation>
#include <QTimer>

/* Make a property animation for a QGraphicsObject */
QPropertyAnimation* makePropertyAnimation(
    QGraphicsObject *obj, const QByteArray& propName, QGraphicsScene *scene
);

template<typename F>
void doLater(F &&action, int waitMsec)
{
    QTimer::singleShot(waitMsec, action);
}

#endif // QUTIL_H
