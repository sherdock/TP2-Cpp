#ifndef TP1_ZZ3_CARTESIEN_HPP
#define TP1_ZZ3_CARTESIEN_HPP

#include <iostream>
#include "point.hpp"

class Polaire;

class Cartesien : public Point //![3]
{
    double coordX;
    double coordY;

public:
    Cartesien();
    Cartesien(double, double);
    Cartesien(Polaire &);
    ~Cartesien();
    std::ostream &afficher(std::ostream &) const;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    friend std::ostream &operator<<(std::ostream &, const Cartesien &);
    void convertir(Polaire &) const;
    void convertir(Cartesien &) const;
};

#endif