#pragma once

#include "Character.h"

struct Dragon : Character
{
    Dragon(std::string name_, int hp_, int armor_, int attackDamage_ = 80);
    void attack(Character& other) override;
    const std::string& getName() override;
    std::string getStats() override;
private:
    const std::string name;
};

