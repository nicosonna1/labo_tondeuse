//---------------------------------------------------------
// Cours          : PRG1_E
// Laboratoire    : Tondeuse
// Fichier        : tondeuse.cpp
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

#include "tondeuse.h"
#include <random>

const short gauche=0,
            bas   =1,
            droite=2,
            haut  =3;


// pour le random plus tard
distr(RANGE_FROM, RANGE_TO)

void tondre(terrain,tondeuse,10'000,true){


}

void afficher(const vector<int>& vecteur, int nombreColonnes) {
    for (size_t i = 0; i < vecteur.size(); ++i) {
        cout << setw(LARGEUR_CELLULE) << vecteur[i] << " ";

        if (nombreColonnes != 0 && (i + 1) % nombreColonnes == 0) {
            cout << endl;
        }
    }
}