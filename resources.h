#ifndef RESOURCES_H
#define RESOURCES_H

#include <QString>
#include <memory>

class SpriteSheet;

class Resources
{
private:
    friend class BJWindow;
    static void load();

public:
    static std::shared_ptr<SpriteSheet> cardSheet;
    static QString
        balanceString,
        betString,
        handString;

    static QString readFile(const QString&);
};

#endif // RESOURCES_H
