#ifndef RESOURCES_H
#define RESOURCES_H

#include <memory>

class SpriteSheet;

class Resources
{
private:
    friend class BJWindow;
    static void load();

public:
    static std::shared_ptr<SpriteSheet> cardSheet;
};

#endif // RESOURCES_H
