#include <iostream>
#include "point.hpp"

std::ostream &Point::afficher(std::ostream &flux) const
{
    return flux;
}

std::ostream &operator<<(std::ostream &flux, const Point &point)
{
    point.afficher(flux);
    return flux;
}
