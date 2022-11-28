//---------------------------------------------------------
// Cours          : PRG1_E
// Laboratoire    : Tondeuse
// Fichier        : tondeuse.cpp
// Auteur(s)      : Sonnard Nicolas
//                  Villegas Castrillon Adrian
// Date           : 2022/11/28
// But            : Programme permettant de simuler une tondeuse a gason
//                  la tondeuse ira dans un direction aleatoire.
//                  Attention parfois elle sera face a un obstacle
//                  celle-ci sera capable de changer sa direction.
//                  Se referer au document "Labo_Tondeuse.pdf" pour toute explication
// Modifications  : N/A
// Remarque(s)    : TODO.
// Versions       : g++ 9.4.0
//                  CMake 3.16.3
//                  C++ standard 20 (CMakeLists.txt)
//---------------------------------------------------------

#include "tondeuse.h" // En-tete correspondante (contient les definitions des
                      // fonctions)
#include "annexe.h"   // Outils externes
#include <iostream>   // cout & cin

using namespace std;

// Constantes pour le random
const int RANGE_FROM = 0,
          RANGE_TO = 3;
const int PAS = 1;

// Constantes pour les differentes directions
const short BAS = 0,
            GAUCHE = 1,
            HAUT = 2,
            DROIT = 3;

/**
 * Efface le contenu de la console et affiche le terrain dans l'etat actuel.
 * @param terrain Terrain à afficher
 */
void afficherTerrain(const Terrain& terrain)
{
    system("cls");
    for (const Ligne& ligne : terrain)
    {
        for (char j : ligne)
            cout << ' ' << j;
        cout << endl;
    }
    cout << endl;
}

/**
 * Retourne la valeur d'une case demandee
 * @param terrain Terrain ou chercher la case
 * @param position Position à chercher
 * @return Valeur de la case demandee
 */
char retournerCase(const Terrain& terrain, Tondeuse position){
    return (char) terrain[(size_t) position[LIGNE]][(size_t) position[COLONNE]];
}
/**
 * Obtenir une nouvelle position aleatoire valide
 * @param positionActuel Position actuel de la tondeuse
 * @param terrain Terrain ou se deplacer
 * @return Prochaine position de la tondeuse
 */
Tondeuse prochainPosition(const Tondeuse& positionActuel, const Terrain& terrain)
{
    Tondeuse nouvellePostion;
    do
    {
        nouvellePostion = positionActuel;

        // Obtenir une direction aleatoire et calculer nouvelle position
        switch (randomNumber(RANGE_FROM,RANGE_TO))
        {
            case BAS:
                nouvellePostion[LIGNE] = positionActuel[LIGNE] + PAS;
                break;
            case GAUCHE:
                nouvellePostion[COLONNE] = positionActuel[COLONNE] - PAS;
                break;
            case HAUT:
                nouvellePostion[LIGNE] = positionActuel[LIGNE] - PAS;
                break;
            case DROIT:
                nouvellePostion[COLONNE] = positionActuel[COLONNE] + PAS;
                break;
        }

        // Valider la nouvelle position, si il y a un obstacle ou une limite on
        // refait
    } while ( retournerCase(terrain, nouvellePostion) == LIMITE ||
        retournerCase(terrain, nouvellePostion) == OBSTACLE);

    return nouvellePostion;
}

/**
 * Coupe l'herbe haute du terrain
 * @param tondeuse Tondeuse avec la position ou elle peut couper
 * @param terrain Terrain ou couper
 * @return Terrain coupe
 */

Terrain couper(const Tondeuse& tondeuse,Terrain terrain)
{
    if (retournerCase(terrain, tondeuse) == HERBE)
        terrain[(size_t) tondeuse[LIGNE]][(size_t) tondeuse[COLONNE]] = COUPE;
    return terrain;
}

/**
 * Tondre un terrain done avec une tondeuse un nombre de pass definie
 * @param terrain Terrain a tondre
 * @param tondeuse Tondeuse avec la position initiale
 * @param nbrePas Nombre de pas a tondre/passer
 * @param afficherEvolution Afficher ou pas la mise a jour du terrain
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
    }

    afficherTerrain(terrain);
    attendreQuitter('q', "Appuyer sur la touche 'q' pour quitter");
}
