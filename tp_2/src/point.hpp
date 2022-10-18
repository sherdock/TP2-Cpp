#ifndef TP1_ZZ3_POINT_HPP
#define TP1_ZZ3_POINT_HPP

#include <iostream>
#include <sstream>

class Cartesien;
class Polaire;
class Point
{
public:
    virtual std::ostream &afficher(std::ostream &) const; //! [4]
    // TODO: virtual void afficher(){}; alternative pour éviter vtable

    friend std::ostream &operator<<(std::ostream &flux, const Point &);
    virtual void convertir(Cartesien &) const = 0;
    virtual void convertir(Polaire &) const = 0;
};

#endif