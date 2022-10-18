#ifndef TP1_ZZ3_NUAGE_HPP
#define TP1_ZZ3_NUAGE_HPP

#include <vector>
#include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

using Type = Point *;
using Points = std::vector<Type>;

class Nuage
{
    Points vecteur_points;

public:
    using iterator = Points::iterator;
    using const_iterator = Points::const_iterator;
    size_t size() const;
    void ajouter(Point *);
    void ajouter(Point &);
    const_iterator begin() const;
    const_iterator end() const;

    iterator begin();
    iterator end();

    Point &operator[](unsigned int const);
};

Cartesien barycentre(Nuage const &nuage);

struct BarycentreCartesien
{
    Cartesien operator()(const Nuage &nuage) const;
};

struct BarycentrePolaire
{
    Polaire operator()(const Nuage &nuage) const;
};

#endif
