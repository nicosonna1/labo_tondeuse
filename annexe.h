//---------------------------------------------------------
// Cours          : PRG1_E
// Laboratoire    : Tondeuse
// Fichier        : annexe.h
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

#ifndef LABO_TONDEUSE_ANNEXE_H
#define LABO_TONDEUSE_ANNEXE_H

#include <string> // std::string

/**
 * Retourne un nombre aleatoire entre deux valeurs compris
 * @param min Limite inferieur
 * @param max Limite superieur
 * @return Nombre aleatoire a retourner
 */
int randomNumber(int min,int max);

/**
 * Affiche un message de fin du programme, et attents que l'utilisateur entre une
 * touche donnee
 * @param touche Touche pour finaliser
 * @param message Message a afficher
 */
void attendreQuitter(const char& touche, const std::string& message);

#endif //LABO_TONDEUSE_ANNEXE_H