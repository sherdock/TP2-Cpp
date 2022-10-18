#include <iostream>
#include <algorithm>
#include <iterator>
#include "nuage.hpp"

using iterator = Points::iterator;
using const_iterator = Points::const_iterator;
size_t Nuage::size() const
{
    return vecteur_points.size();
}
void Nuage::ajouter(Point &point)
{
    vecteur_points.push_back(&point);
}

void Nuage::ajouter(Point *point)
{
    vecteur_points.push_back(point);
}
const_iterator Nuage::begin() const
{
    return vecteur_points.begin();
}

const_iterator Nuage::end() const
{
    return vecteur_points.end();
}

iterator Nuage::begin()
{
    return vecteur_points.begin();
}

iterator Nuage::end()
{
    return vecteur_points.end();
}

Point &Nuage::operator[](unsigned int const index)
{
    return *vecteur_points[index];
}

Cartesien barycentre(Nuage const &nuage)
{
    auto total = nuage.size();
    double x = 0;
    double y = 0;
    for (Point *point : nuage)
    {
        Cartesien tmp;
        point->convertir(tmp);
        x += tmp.getX();
        y += tmp.getY();
    }

    return {x / total, y / total};
}

Cartesien BarycentreCartesien::operator()(const Nuage &nuage) const
{
    return barycentre(nuage);
}

Polaire BarycentrePolaire::operator()(const Nuage &nuage) const
{
    Polaire p = {};
    barycentre(nuage).convertir(p);
    return p;
}
