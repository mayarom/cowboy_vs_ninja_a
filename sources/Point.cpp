// Point.cpp
#include "Point.hpp"
#include <cmath>
#include <iomanip>

namespace ariel
{
    Point::Point(double x, double y) : x(x), y(y) {}

    double Point::getX() const
    {
        return x;
    }

    double Point::getY() const
    {
        return y;
    }

    double Point::distance(const Point &other) const
    {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    std::ostream &operator<<(std::ostream &out, const Point &point)
    {
        out << "(" << std::fixed << std::setprecision(1) << point.getX() << ", " << point.getY() << ")";
        return out;
    }

    std::string Point::print() const
    {
        std::stringstream ss;
        ss << "(" << std::fixed << std::setprecision(1) << x << ", " << y << ")";
        return ss.str();
    }

    void Point::setX(double newX)
    {
        this->x = newX;
    }

    void Point::setY(double newY)
    {
        this->y = newY;
    }
}
