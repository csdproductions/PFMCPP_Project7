#pragma once

#include "Character.h"
#include "AttackItem.h"

struct DragonSlayer : Character
{
    DragonSlayer(std::string name_, int hp_, int armor_, int attackDamage_ = 4);
    void attack(Character& other) override;
    const std::string& getName() override;
    std::string getStats() override;
private:
    const std::string name;
    std::unique_ptr<Item> attackItem { new AttackItem() };
};
