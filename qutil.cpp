#include "qutil.h"

QPropertyAnimation* makePropertyAnimation(
    QGraphicsObject *obj, const QByteArray &propName, QGraphicsScene *scene
)
{
    auto anim = new QPropertyAnimation(obj, propName);
    QObject::connect(
        anim, QPropertyAnimation::valueChanged,
        [scene](auto&) {
            scene->update();
        }
    );
    return anim;
}
