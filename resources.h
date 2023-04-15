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

    static std::shared_ptr<SpriteSheet> defaultCardSheet;

public:
    static std::shared_ptr<SpriteSheet> cardSheet;
    static QString
        balanceString,
        betString,
        handString,

        bustMsg,
        winMsg,
        lossMsg,
        pushMsg;

    static QString readFile(const QString&);

    static void loadCardSheet(const QString&);
    static void resetCardSheet();
};

#endif // RESOURCES_H
