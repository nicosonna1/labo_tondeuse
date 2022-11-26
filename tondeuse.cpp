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

#include <iomanip> // setw(..)
#include <iostream> // cout & cin
#include <random>

using namespace std;

const int RANGE_FROM = 0,
          RANGE_TO = 3;

// Pour le random plus tard
const short BAS = 0,
            GAUCHE = 1,
            HAUT = 2,
            DROIT = 3;


void afficherTerrain(Terrain terrain) {
    system("cls");
    for(Ligne ligne: terrain){
        for(char j: ligne)
            cout << ' ' << j;
        cout << endl;
    }
}

int randomPosition(const int min, const int max)
{
    random_device                  rand_dev;
    default_random_engine          generator(rand_dev());
    uniform_int_distribution<int>  distr(RANGE_FROM, RANGE_TO);
    return distr(generator);
}

Tondeuse prochainPosition(Tondeuse tondeuse, Terrain terrain){
    Tondeuse nouvellePostion ;
    int random;

    //  0 1
    // {5,7}

    do {
        nouvellePostion = tondeuse;
        // Obtenir la direction --> un random entre 0 est 3
        // Calculer nouvelle position
        switch (randomPosition(0,1)) {
            case BAS:
                nouvellePostion[LIGNE] = ++nouvellePostion[LIGNE];
                break;
            case GAUCHE:
                nouvellePostion[COLONNE] = --nouvellePostion[COLONNE];
                break;
            case HAUT:
                nouvellePostion[LIGNE] = --nouvellePostion[LIGNE];
                break;
            case DROIT:
                nouvellePostion[COLONNE] = ++nouvellePostion[COLONNE];
                break;
        }

        // Valider la nouvelle position
    } while (terrain[nouvellePostion[LIGNE]][nouvellePostion[COLONNE]] == LIMITE ||
    terrain[nouvellePostion[LIGNE]][nouvellePostion[COLONNE]] == OBSTACLE );

    return nouvellePostion;
}

void couper(Tondeuse tondeuse, Terrain terrain) {
    if(terrain[tondeuse[LIGNE]][tondeuse[COLONNE]]==HERBE)
        terrain[tondeuse[LIGNE]][tondeuse[COLONNE]]=COUPE;
}

void tondre(Terrain terrain, Tondeuse tondeuse, int nbrePas, bool afficherEvolution){
    afficherTerrain(terrain);
    for (int i = 0; i < nbrePas; ++i) {
        tondeuse = prochainPosition(tondeuse, terrain);
        couper(tondeuse, terrain);
        if (afficherEvolution)
            afficherTerrain(terrain);
    }
    afficherTerrain(terrain);
}
