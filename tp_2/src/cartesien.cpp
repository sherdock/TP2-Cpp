#include <iostream>
#include <cmath>
#include "Cartesien.hpp"
#include "polaire.hpp"

#define M_PI 3.14159265358979323846

Cartesien::Cartesien() : coordX(0.0), coordY(0.0)
{
}

Cartesien::Cartesien(double x, double y) : coordX(x), coordY(y)
{
}
Cartesien::Cartesien(const Polaire &polaire)
{
    double angle = polaire.getAngle();
    double distance = polaire.getDistance();
    double x = distance * cos(angle * M_PI / 180);
    double y = distance * sin(angle * M_PI / 180);
    coordX = x;
    coordY = y;
}
Cartesien::~Cartesien()
{
    // std::cout << "Dans le destructeur Cartesien" << std::endl;
}

double Cartesien::getX() const
{
    return coordX;
}

double Cartesien::getY() const
{
    return coordY;
}

void Cartesien::setX(double x)
{
    coordX = x;
}

void Cartesien::setY(double y)
{
    coordY = y;
}

std::ostream &Cartesien::afficher(std::ostream &flux) const
{
    return (flux << "(x=" << coordX << ";y=" << coordY << ")");
}

std::ostream &operator<<(std::ostream &flux, const Cartesien &cartesien)
{
    cartesien.afficher(flux);
    return flux;
}

void Cartesien::convertir(Polaire &polaire) const
{
    double anglePolaire = std::atan2(coordY, coordX);
    anglePolaire = anglePolaire * 180 / M_PI;
    double distancePolaire = sqrt(coordX * coordX + coordY * coordY);
    polaire.setAngle(anglePolaire);
    polaire.setDistance(distancePolaire);
}

void Cartesien::convertir(Cartesien &cart) const
{
    cart.setX(coordX);
    cart.setY(coordY);
}