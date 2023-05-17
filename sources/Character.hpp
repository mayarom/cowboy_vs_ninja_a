#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include "Point.hpp"

namespace ariel {

    class Character {
    protected:
        std::string name;
        Point position;
        int health;
        bool alive;

    public:
        Character(const std::string& name, const Point& position);
        Character(const Character& other) = default;
        Character& operator=(const Character& other) = default;
        Character(Character&& other) = default;
        Character& operator=(Character&& other) = default;
        virtual ~Character() = default;

        std::string getName() const;
        bool isAlive() const;
        void damage(int amount);
        void setLocation(const Point& newPosition);
        virtual std::string print() const;
        friend std::ostream& operator<<(std::ostream& out, const Character& character);
        virtual void attack(Character* enemy);
    };

    class Cowboy : public Character {
    private:
        int bullets;

    public:
        Cowboy(const std::string& name, const Point& position);
        void reload();
        void attack(Character* enemy) override;
        void shoot(Character* enemy);
        std::string print() const override;
    };

    class Ninja : public Character {
    protected:
        int speed;

    public:
        Ninja(const std::string& name, const Point& position, int speed);
        void attack(Character* enemy) override;
        void slash(Character* enemy);
        void move(Character* enemy);  // New member function
        std::string print() const override;
    };

    class YoungNinja : public Ninja {
    public:
        YoungNinja(const std::string& name, const Point& position);
    };

    class OldNinja : public Ninja {
    public:
        OldNinja(const std::string& name, const Point& position);
    };

    class TrainedNinja : public Ninja {
    public:
        TrainedNinja(const std::string& name, const Point& position);
    };

} // namespace ariel

#endif // CHARACTER_HPP
