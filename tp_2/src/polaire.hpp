#ifndef TP1_ZZ3_POLAIRE_HPP
#define TP1_ZZ3_POLAIRE_HPP

#include <iostream>
#include "point.hpp"

class Cartesien;

class Polaire : public Point
{
    double angle;
    double distance;

public:
    Polaire();
    Polaire(double, double);
    Polaire(const Cartesien &);
    ~Polaire();
    std::ostream &afficher(std::ostream &) const;
    double getAngle() const;
    double getDistance() const;
    void setAngle(double);
    void setDistance(double);
    friend std::ostream &operator<<(std::ostream &, const Polaire &);
    void convertir(Cartesien &) const override;
    void convertir(Polaire &) const override;
};

#endif