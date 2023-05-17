#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>
#include <string>

namespace ariel
{

    class Point
    {
    private:
        double x;
        double y;

    public:
        Point(double coordinate_x = 0, double coordinate_y = 0);
        Point(const Point& other) = default;
        Point& operator=(const Point& other) = default;
        Point(Point&& other) = default;
        Point& operator=(Point&& other) = default;
        ~Point() = default;

        double getX() const;
        double getY() const;
        void setX(double newX);
        void setY(double newY);

        double distance(const Point &other) const;
        std::string print() const;
    };

} // namespace ariel

#endif // POINT_HPP
