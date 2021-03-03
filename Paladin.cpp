#include "Paladin.h"

#include "Utility.h"

Paladin::Paladin(std::string name_, int hp_, int armor_, int attackDamage_) : 
Character(hp_, armor_, attackDamage_), 
name(name_)
{
    helpfulItems = makeHelpfulItems(randomNum());
    defensiveItems = makeDefensiveItems(randomNum());   
}

const std::string& Paladin::getName()
{
    return name;
}

std::string Paladin::getStats()
{
    return getCharacterStats(this);
}
