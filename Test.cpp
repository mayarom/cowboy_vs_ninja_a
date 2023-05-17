#include "doctest.h"
#include "sources/Character.hpp"
#include "sources/Team.hpp"
#include "sources/Point.hpp"

TEST_CASE("Testing Character class")
{
    ariel::Point pos(0, 0);
    ariel::Character character("Test Character", pos);

    CHECK(character.isAlive() == true);
    CHECK(character.getName() == "Test Character");
    character.damage(10);
    CHECK(character.isAlive() == false);
}

TEST_CASE("Testing Cowboy class")
{
    ariel::Point pos(0, 0);
    ariel::Cowboy cowboy("Test Cowboy", pos);

    CHECK(cowboy.isAlive() == true);
    CHECK(cowboy.getName() == "Test Cowboy");
    cowboy.damage(10);
    CHECK(cowboy.isAlive() == false);
}

TEST_CASE("Testing Ninja class")
{
    ariel::Point pos(0, 0);
    ariel::Ninja ninja("Test Ninja", pos, 5);

    CHECK(ninja.isAlive() == true);
    CHECK(ninja.getName() == "Test Ninja");
    ninja.damage(10);
    CHECK(ninja.isAlive() == false);
}

TEST_CASE("Testing Team class")
{
    ariel::Point pos(0, 0);
    ariel::Character leader("Leader", pos);
    ariel::Team team(&leader);

    CHECK(team.stillAlive() == 1);
    ariel::Character newCharacter("New Character", pos);
    team.add(&newCharacter);
    CHECK(team.stillAlive() == 2);
    newCharacter.damage(10);
    CHECK(team.stillAlive() == 1);
}

TEST_CASE("Testing Point class")
{
    ariel::Point pos(0, 0);
    CHECK(pos.getX() == 0);
    CHECK(pos.getY() == 0);
    pos.setX(1);
    pos.setY(2);
    CHECK(pos.getX() == 1);
    CHECK(pos.getY() == 2);
}
TEST_CASE("Testing YoungNinja class")
{
    ariel::Point pos(0, 0);
    ariel::YoungNinja youngNinja("Test YoungNinja", pos);

    CHECK(youngNinja.isAlive() == true);
    CHECK(youngNinja.getName() == "Test YoungNinja");
    youngNinja.damage(10);
    CHECK(youngNinja.isAlive() == false);
}

TEST_CASE("Testing OldNinja class")
{
    ariel::Point pos(0, 0);
    ariel::OldNinja oldNinja("Test OldNinja", pos);

    CHECK(oldNinja.isAlive() == true);
    CHECK(oldNinja.getName() == "Test OldNinja");
    oldNinja.damage(10);
    CHECK(oldNinja.isAlive() == false);
}

TEST_CASE("Testing TrainedNinja class")
{
    ariel::Point pos(0, 0);
    ariel::TrainedNinja trainedNinja("Test TrainedNinja", pos);

    CHECK(trainedNinja.isAlive() == true);
    CHECK(trainedNinja.getName() == "Test TrainedNinja");
    trainedNinja.damage(10);
    CHECK(trainedNinja.isAlive() == false);
}

TEST_CASE("Testing Point class distance calculation")
{
    ariel::Point pos1(0, 0);
    ariel::Point pos2(3, 4); // A point at (3,4) is 5 units away from origin (0,0) - Pythagorean theorem

    CHECK(pos1.distance(pos2) == doctest::Approx(5.0));
}

TEST_CASE("Testing attacking mechanics")
{
    ariel::Point pos(0, 0);
    ariel::Cowboy cowboy("Test Cowboy", pos);
    ariel::Ninja ninja("Test Ninja", pos, 5);

    CHECK(cowboy.isAlive() == true);
    CHECK(ninja.isAlive() == true);

    cowboy.attack(&ninja);
    ninja.attack(&cowboy);

    // Check if they are still alive after one attack (assuming one attack doesn't kill them)
    CHECK(cowboy.isAlive() == true);
    CHECK(ninja.isAlive() == true);
}
