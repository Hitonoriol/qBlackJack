#include "scene.h"

Scene::Scene() {}

void Scene::add(QGraphicsItem *item)
{
    item->setY(lastY);
    lastY += item->boundingRect().size().height();
    addItem(item);
}

