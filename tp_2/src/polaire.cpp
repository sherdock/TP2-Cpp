#include <iostream>
#include <cmath>
#include "polaire.hpp"
#include "cartesien.hpp"

#define M_PI 3.14159265358979323846

Polaire::Polaire() : angle(0.0), distance(0.0)
{
}

Polaire::Polaire(double a, double d) : angle(a), distance(d)
{
}
Polaire::Polaire(const Cartesien &cart)
{
    double coordX = cart.getX();
    double coordY = cart.getY();
    double anglePolaire = std::atan2(coordY, coordX);
    anglePolaire = anglePolaire * 180 / M_PI;
    double distancePolaire = sqrt(coordX * coordX + coordY * coordY);

    angle = anglePolaire;
    distance = distancePolaire;
}

Polaire::~Polaire()
{
    // std::cout << "Dans le destructeur" << std::endl;
}

double Polaire::getAngle() const
{
    return angle;
}

double Polaire::getDistance() const
{
    return distance;
}

//! undefined reference to `vtable for Point/Polaire
//! Cause : Les méthodes virtuelles doivent être définies
//! (dans le .cpp ou directement dans le .hpp)

void Polaire::setAngle(double a)
{
    angle = a;
}

void Polaire::setDistance(double d)
{
    distance = d;
}

//! Ne marche pas avec le std::stringstream car très sprécifique
//! Voir l'arbre : https://en.cppreference.com/w/cpp/io
std::ostream &Polaire::afficher(std::ostream &flux) const
{
    return (flux << "(a=" << angle << ";d=" << distance << ")");
}

std::ostream &operator<<(std::ostream &flux, const Polaire &polaire)
{
    polaire.afficher(flux);
    return flux;
}

void Polaire::convertir(Cartesien &cart) const
{
    double x = distance * cos(angle * M_PI / 180);
    double y = distance * sin(angle * M_PI / 180);
    cart.setX(x);
    cart.setY(y);
}

void Polaire::convertir(Polaire &pol) const
{
    pol.setAngle(angle);
    pol.setDistance(distance);
}
