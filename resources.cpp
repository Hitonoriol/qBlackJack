#include "resources.h"

#include "spritesheet.h"

std::shared_ptr<SpriteSheet> Resources::cardSheet;

void Resources::load()
{
    cardSheet = std::make_shared<SpriteSheet>(":/textures/cards.png", 13, 5);
}
