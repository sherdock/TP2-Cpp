// #include <iostream>
// #include <algorithm>
// #include <iterator>
// #include "Nuage.hpp"

// template <typename T>

template <typename T>
size_t Nuage<T>::size() const
{
    return vecteur_points.size();
}

template <typename T>
void Nuage<T>::ajouter(const T &point)
{
    vecteur_points.push_back(point);
}

template <typename T>
void Nuage<T>::ajouter(T *point)
{
    vecteur_points.push_back(point);
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::begin() const
{
    return vecteur_points.begin();
}

template <typename T>
typename Nuage<T>::const_iterator Nuage<T>::end() const
{
    return vecteur_points.end();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::begin()
{
    return vecteur_points.begin();
}

template <typename T>
typename Nuage<T>::iterator Nuage<T>::end()
{
    return vecteur_points.end();
}

// Point &Nuage<T>::operator[](unsigned int const index)
// {
//     return *vecteur_points[index];
// }
template <typename T>
T barycentre_v1(const Nuage<T> &nuage)
{
    T barycentre;
    auto total = nuage.size();
    double x = 0;
    double y = 0;
    if (total > 0)
    {

        for (auto point : nuage)
        {
            Cartesien tmp;
            point.convertir(tmp);
            x += tmp.getX();
            y += tmp.getY();
        }
        barycentre = Cartesien(x / total, y / total);
    }

    return barycentre;
}

template <>
Polaire barycentre_v1<Polaire>(const Nuage<Polaire> &nuage)
{
    double a = 0.0;
    double d = 0.0;
    int n = 0;

    for (const Polaire &p : nuage)
    {
        a += p.getAngle();
        d += p.getDistance();
        ++n;
    }

    return (n == 0 ? Polaire() : Polaire(a / n, d / n)); // Formule fausse bien entendu !
}

// Cartesien BarycentreCartesien::operator()(const Nuage<T> &Nuage<T>) const
// {
//     return barycentre(Nuage<T>);
// }

// Polaire BarycentrePolaire::operator()(const Nuage<T> &Nuage<T>) const
// {
//     Polaire p = {};
//     barycentre(Nuage<T>).convertir(p);
//     return p;
// }
