#include "DragonSlayer.h"
#include "Dragon.h"

#include "Utility.h"

DragonSlayer::DragonSlayer(std::string name_, int hp_, int armor_, int attackDamage_) : 
Character(hp_, armor_, attackDamage_), 
name(name_)
{
    helpfulItems = makeHelpfulItems(randomNum());
    defensiveItems = makeDefensiveItems(randomNum());   
}

const std::string& DragonSlayer::getName()
{
    return name;
}

std::string DragonSlayer::getStats()
{
    return getCharacterStats(this);
}

void DragonSlayer::attack(Character& other)
{
    std::cout << name << " is attacking " << other.getName() << " !!" << std::endl;
    if( auto* dragon = dynamic_cast<Dragon*>(&other) )
    {
        //assert(false);
        //DragonSlayers get a 10x boost when attacking dragons, from their attack item.
        
        // check if attack item is valid
        if(attackItem != nullptr)
        {
            //so they should USE their attack item before attacking the dragon... 
            attackItem->use(this);
            //note that items are single-use only, so you need to reset it after use.  
            //look in the Character class for how the other item types are reset after use.
            attackItem.reset();
        }
            

        while( dragon->getHP() > 0 )
        {
          dragon->takeDamage(attackDamage);
        }
    }
        
    Character::attack(other);
        
}
