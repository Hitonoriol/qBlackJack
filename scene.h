#ifndef SCENE_H
#define SCENE_H

#include <QGraphicsScene>
#include <QGraphicsItem>

class Scene : public QGraphicsScene
{
private:
    double lastY;

public:
    Scene();

    void add(QGraphicsItem*);
};

#endif // SCENE_H
