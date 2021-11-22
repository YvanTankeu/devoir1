/*
  Titre      : produire les factures
  Auteur     : Yvan Tankeu
  Date       : 22/11/2021
  Description: Le Club Med veut qu’on leur développe un programme pour produire ses factures
  Version    : 0.0.1
*/

#include <iostream>
#include "fonctions.h"

using namespace std;

// Déclaration des variables et initialisation des variables
int choix(5), dureeSejour(0), nbrEnfant(0), ageEnfant(0);
string nomCleint("");
char typeSejour;

int main()
{
  // Affichage du menu et traitement de données
  while (choix > 0 and choix < 4 || choix > 4)
  {
    // appel de fonction menu pour l'affiche du menu
    menu();
    cin >> choix;

    // Traitement par choix
    switch (choix)
    {
    case 1:
      cout << "\nEntrer le nom du client:";
      cin >> nomCleint;
      cout << "\n\nEntrer la durée du sejour (un nombre entier entre 1 et 14) : ";
      cin >> dureeSejour;

      // Traitement et validation des données concernant les séjours
      cout << "\nEntrer le type de sejour (R - régulier ou T - tout inclus) : ";
      cin >> typeSejour;
      LireValiderEntierEntre(typeSejour);
      
      cout << "\n\nEntrer le nombre d'enfant(s) (un nombre entier entre 0 et 12) : ";
      cin >> nbrEnfant;
      for (int i = 0; i < nbrEnfant + 1; i++)
      {
        cout << "\n\nEntrer l'age (moins de 12) de l'enfant #" << i ;
        cin >> ageEnfant;
      }
      
    }
  }
}