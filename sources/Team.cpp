#include "Team.hpp"
#include <iostream>

using namespace std;

namespace ariel
{
    Team::Team(Character *leader) : generator(std::random_device()()), distribution(0, this->characters.size() - 1)
    {
        this->characters.push_back(leader);
    }

    void Team::add(Character *character)
    {
        this->characters.push_back(character);
        this->distribution = std::uniform_int_distribution<std::vector<Character *>::size_type>(0, this->characters.size() - 1);
    }

    int Team::stillAlive() const
    {
        int count = 0;
        for (Character *character : this->characters)
        {
            if (character->isAlive())
            {
                count++;
            }
        }
        return count;
    }

    void Team::attack(Team *enemies)
    {
        if (enemies->characters.empty())
        {
            return; // No enemies to attack.
        }

        std::vector<Character *>::size_type random_index = this->distribution(this->generator);
        for (Character *character : this->characters)
        {
            if (character->isAlive())
            {
                character->attack(enemies->characters[random_index]);
            }
        }
    }

    void Team::print() const
    {
        std::cout << "Team members:" << std::endl;
        for (Character *character : this->characters)
        {
            std::cout << character->print() << std::endl;
        }
    }

}
