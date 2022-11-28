//---------------------------------------------------------
// Cours          : PRG1_E
// Laboratoire    : Tondeuse
// Fichier        : annexe.cpp
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

#include "annexe.h" // En-tete correspondante (contient les definitions des
                    // fonctions)
#include <random>

using namespace std;

/**
 * Permet de generer un nombre aleatoire
 * repri du git
 * https://github.com/gmbreguet/PRG1_DEMO/blob/main/04_Fonctions/04_random.cpp
 *
 * @return nombre aleatoire
 */
#include <iostream>   // cout & cin

using namespace std;

/**
 *  renvoie un nombre aleatoire compris entre deux valeurs
 * @param min minimum de la plage
 * @param max maximum de la plage
 * @return nombre   nombre aleatoire obtenu
 */

int randomNumber(int min,int max)
{
    random_device rand_dev;
    default_random_engine generator(rand_dev());
    uniform_int_distribution<int> distr(min, max);
    return distr(generator);
}
/**
 * permet d'attendre que l'utilisateur appuie sur une touche donnee
 * @param touche
 * @param message
 */
void attendreQuitter(const char& touche, const string& message){
    char toucheActuelle;
    cout << message << endl;
    // attente que l'utilisateur clique la bonne touche
    while(toucheActuelle != touche);
    cin>>toucheActuelle;

}