#pragma once
#include "Character.hpp"
#include <vector>
#include <random>

namespace ariel
{
    class Team
    {
    private:
        std::vector<Character *> characters;
        std::default_random_engine generator;
        std::uniform_int_distribution<std::vector<Character *>::size_type> distribution;

    public:
        Team(Character *leader);
        Team(const Team &other) = default;
        Team &operator=(const Team &other) = default;
        Team(Team &&other) = default;
        Team &operator=(Team &&other) = default;
        ~Team() = default;

        void add(Character *character);
        int stillAlive() const;
        void attack(Team *enemies);
        void print() const;
    };
}
