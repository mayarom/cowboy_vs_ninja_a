#include "Character.hpp"
#include <iostream>
#include <sstream>

namespace ariel
{

    // Character
    Character::Character(const std::string &name, const Point &position)
        : name(name), position(position), health(100), alive(true) {}

    bool Character::isAlive() const
    {
        return health > 0;
    }

    void Character::damage(int amount)
    {
        health -= amount;
        if (health <= 0)
        {
            alive = false;
        }
    }

    void Character::setLocation(const Point &newPosition)
    {
        position = newPosition;
    }

    std::string Character::getName() const
    {
        return name;
    }

    std::string Character::print() const
    {
        std::stringstream ss;
        ss << "Character " << name << " has " << health << " health.";
        return ss.str();
    }

    std::ostream &operator<<(std::ostream &out, const Character &character)
    {
        return out << character.print() << std::endl;
    }

    void Character::attack(Character *enemy)
    {
        // Implementation specific to the Character class
        // ...
    }

    // Cowboy
    Cowboy::Cowboy(const std::string &name, const Point &position)
        : Character(name, position), bullets(6) {}

    void Cowboy::reload()
    {
        bullets = 6;
    }

    void Cowboy::attack(Character *enemy)
    {
        if (bullets > 0)
        {
            enemy->damage(10); // Reduce enemy's health by 10.
            bullets--;
        }
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (bullets > 0)
        {
            std::cout << name << " shoots " << enemy->getName() << std::endl;
            enemy->damage(20);
            bullets--;
        }
    }

    std::string Cowboy::print() const
    {
        std::stringstream ss;
        ss << "Cowboy " << getName() << " has " << health << " health and " << bullets << " bullets left.";
        return ss.str();
    }

    // Ninja
    Ninja::Ninja(const std::string &name, const Point &position, int speed)
        : Character(name, position), speed(speed) {}

    void Ninja::attack(Character *enemy)
    {
        std::cout << name << " attacks " << enemy->getName() << std::endl;
        enemy->damage(15);
    }

    void Ninja::slash(Character *enemy)
    {
        std::cout << name << " slashes " << enemy->getName() << std::endl;
        enemy->damage(30);
    }

    void Ninja::move(Character *enemy)
    {
        // Assume the Ninja moves faster than the enemy and can always reduce the distance by its speed value.
        // Implementation specific to the Ninja class
        // ...
    }

    std::string Ninja::print() const
    {
        std::stringstream ss;
        ss << "Ninja " << getName() << " has " << health << " health and speed " << speed;
        return ss.str();
    }

    // YoungNinja
    YoungNinja::YoungNinja(const std::string &name, const Point &position)
        : Ninja(name, position, 10) {}

    // OldNinja
    OldNinja::OldNinja(const std::string &name, const Point &position)
        : Ninja(name, position, 5) {}

    // TrainedNinja
    TrainedNinja::TrainedNinja(const std::string &name, const Point &position)
        : Ninja(name, position, 15) {}

} // namespace ariel
