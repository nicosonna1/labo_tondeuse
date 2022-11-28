//---------------------------------------------------------
// Cours          : PRG1_E
// Laboratoire    : Tondeuse
// Fichier        : tondeuse.cpp
// Auteur(s)      : Sonnard Nicolas
//                  Villegas Castrillon Adrian
// Date           : 2022/11/28
// But            : Prgramme permettant de simuler un tondeuse a gason
//                  la tondeuse ira dans un direction aleatoire.
//                  Attention parfois elle sera face a un obstacle
//                  celle-ci sera capable de changer sa direction.
//                  Se referer au document  "Labo_Tondeuse.pdf" pour toute explication
// Modifications  : N/A
// Remarque(s)    : TODO.
// Versions       : g++ 9.4.0
//                  CMake 3.16.3
//                  C++ standard 20 (CMakeLists.txt)
//---------------------------------------------------------

#include "tondeuse.h"

#include <iomanip>  // setw(..)
#include <iostream> // cout & cin
#include <random>

using namespace std;

// Pour le random plus tard
const int RANGE_FROM = 0,
          RANGE_TO = 3;

 //  constante des differentes directions
const short BAS = 0,
            GAUCHE = 1,
            HAUT = 2,
            DROIT = 3;
/**
 *  afficher le terrain a l'utilisateur
 *
 * @param terrain
 */
void afficherTerrain(Terrain terrain)
{
    system("cls");
    for (Ligne ligne : terrain)
    {
        for (char j : ligne)
            cout << ' ' << j;
        cout << endl;
    }
    cout << endl;
}
/**
 * permet de generer un nombre aleatoir
 * @return nombre aleatoire
 */
int randomPosition()
{
    random_device rand_dev;
    default_random_engine generator(rand_dev());
    uniform_int_distribution<int> distr(RANGE_FROM, RANGE_TO);
    return distr(generator);
}
/**
 *  retourne la valeur d'une case demandee
 * @param terrain
 * @param position
 * @return
 */
char retournerCase(Terrain terrain, Tondeuse position){
    return terrain[position[LIGNE]][position[COLONNE]];
}
/**
 *
 * @param tondeuse
 * @param terrain
 * @return prochaine prostion de la tondeuse
 */
Tondeuse prochainPosition(Tondeuse tondeuse, Terrain terrain)
{
    Tondeuse nouvellePostion  = tondeuse;
    int ligneTondeuse,
        colonneTondeuse;
    do
    {
        ligneTondeuse=tondeuse[0];
        colonneTondeuse=tondeuse[1];
        // Obtenir une direction aleatoire et calculer nouvelle position
        switch (randomPosition())
        {
            case BAS:
                nouvellePostion[LIGNE] = ligneTondeuse +1;
                break;
            case GAUCHE:
                nouvellePostion[COLONNE] = colonneTondeuse -1;
                break;
            case HAUT:
                nouvellePostion[LIGNE] = ligneTondeuse -1;
                break;
            case DROIT:
                nouvellePostion[COLONNE] = colonneTondeuse +1;
                break;
        }

        // Valider la nouvelle position
    } while ( retournerCase(terrain, nouvellePostion) == LIMITE ||
        retournerCase(terrain, nouvellePostion) == OBSTACLE);

    return nouvellePostion;
}
/**
 * Coupe l'herbe du terrain --> permet de remplacer l'herbe non coupee
 * par de l'herbe coupee
 *
 * @param tondeuse
 * @param terrain
 * @return terrain
 */

Terrain couper(Tondeuse tondeuse, Terrain terrain)
{
    if (retournerCase(terrain, tondeuse) == HERBE)
        terrain[tondeuse[LIGNE]][tondeuse[COLONNE]] = 'O';
    return terrain;
}
/**
 *  fonction principale du programme
 *  elle appelera les sous programme afin de :
 *  - afficher le terrain
 *  - tondre le terrain
 *  - possibilite d'afficher l'evolution de la tonte
 * @param terrain
 * @param tondeuse
 * @param nbrePas
 * @param afficherEvolution
 */
void tondre(Terrain terrain, Tondeuse tondeuse, int nbrePas, bool afficherEvolution)
{
    afficherTerrain(terrain);
    for (int i = 0; i < nbrePas; ++i)
    {
        tondeuse = prochainPosition(tondeuse, terrain);
        terrain = couper(tondeuse, terrain);
        if (afficherEvolution)
            afficherTerrain(terrain);
        cout << i << endl;
    }
    afficherTerrain(terrain);
}
