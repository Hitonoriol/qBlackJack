#include "resources.h"

#include "spritesheet.h"

#include <QFile>

std::shared_ptr<SpriteSheet> Resources::cardSheet;
QString
    Resources::balanceString("Balance: $%1"),
    Resources::betString("Bet: $%1"),
    Resources::handString("Hand score: %1"),
    Resources::bustMsg("You busted and lost your bet of $%1."),
    Resources::winMsg("Congratulations! You won $%1!"),
    Resources::lossMsg("You lost your bet of $%1."),
    Resources::pushMsg("Dealer has an equivalent hand. Your bet is refunded.");

void Resources::load()
{
    cardSheet = std::make_shared<SpriteSheet>(":/textures/cards.png", 13, 5);
}

QString Resources::readFile(const QString &path)
{
    QFile file(path);
    file.open(QFile::ReadOnly);
    return {file.readAll()};
}
