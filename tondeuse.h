//---------------------------------------------------------
// Cours          : PRG1_E
// Laboratoire    : Tondeuse
// Fichier        : tondeuse.h
// Auteur(s)      : Sonnard Nicolas
//                  Villegas Castrillon Adrian
// Date           : 2022/11/28
// But            : TODO.
// Modifications  : N/A
// Remarque(s)    : TODO.
// Versions       : g++ 9.4.0
//                  CMake 3.16.3
//                  C++ standard 20 (CMakeLists.txt)
//---------------------------------------------------------

#ifndef LABO_TONDEUSE_TONDEUSE_H
#define LABO_TONDEUSE_TONDEUSE_H

#include <vector> // std::vector

using Ligne = std::vector<int>;
using Terrain = std::vector<Ligne>;
using Tondeuse = std::vector<int>;

/**
 *
 * @param terrain
 * @param tondeuse
 * @param nbrePass
 * @param afficherEvolution
 */
void tondre(Terrain,
            Tondeuse,
            int nbrePass,
            bool afficherEvolution);

#endif //LABO_TONDEUSE_TONDEUSE_H
