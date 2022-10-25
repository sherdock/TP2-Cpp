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
    Polaire barycentre;
    double a = 0.0;
    double d = 0.0;
    auto total = nuage.size();
    if (total > 0)
    {
        for (const Polaire &p : nuage)
        {
            a += p.getAngle();
            d += p.getDistance();
        }
        barycentre = Polaire(a / total, d / total);
    }

    return barycentre;
}

// C::value_type : type de ce qui est stocké dans le C
// On peut donc se passer du typename T
template <typename C>
typename C::value_type barycentre_v2(const C &conteneur)
{

    typename C::value_type barycentre;
    double x = 0.0;
    double y = 0.0;
    auto total = conteneur.size();

    if (total > 0)
    {
        for (auto point : conteneur)
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

// template <typename C>
// Polaire barycentre_v2<Polaire>(const C<Polaire> &conteneur)
// {
//     Polaire barycentre;
//     double a = 0.0;
//     double d = 0.0;
//     auto total = conteneur.size();
//     if (total > 0)
//     {
//         for (const Polaire &p : conteneur)
//         {
//             a += p.getAngle();
//             d += p.getDistance();
//         }
//         barycentre = Polaire(a / total, d / total);
//     }

//     return barycentre;
// }