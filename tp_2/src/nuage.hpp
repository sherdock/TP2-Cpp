#ifndef TP2_ZZ3_NUAGE_HPP
#define TP2_ZZ3_NUAGE_HPP

#include <vector>
// #include "point.hpp"
#include "cartesien.hpp"
#include "polaire.hpp"

template <typename T>
class Nuage
{

public:
    using TemplateVector = typename std::vector<T>;
    using iterator = typename TemplateVector::iterator;
    using const_iterator = typename TemplateVector::const_iterator; //![1]

    TemplateVector vecteur_points;

    size_t size() const;
    void ajouter(T *);
    void ajouter(const T &);
    const_iterator begin() const;
    const_iterator end() const;

    iterator begin();
    iterator end();

    // Point &operator[](unsigned int const);
};

// Cartesien barycentre(Nuage const &nuage);

// struct BarycentreCartesien
// {
//     Cartesien operator()(const Nuage &nuage) const;
// };

// struct BarycentrePolaire
// {
//     Polaire operator()(const Nuage &nuage) const;
// };

#include "nuage_implementation.cxx"

#endif
