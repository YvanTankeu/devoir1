/*
  Titre      : Fonctions
  Auteur     : Yvan Tankeu
  Date       : 22/11/2021
  Description: Fonctions propres au programme de facturation qui devront être utilisé dans le main
  Version    : 0.0.1
*/

#include <iostream>

using namespace std;

// Déclaration et définition de la fonction qui affichera le menu pour notre programme
void menu()
{
  // Menu à afficher
  cout << "\n1 – Entrer des informations de facturation.\n"
       << "2 – Calculer et afficher la facture\n"
       << "3 – Afficher les grands totaux de facturation pour la journée\n"
       << "4 – Terminer le programme"
       << "\n\nEntrez votre choix (1,2,3 ou 4) : ";
}

// Déclation et définition de la fonction  LireValiderEntierEntre ) à fin de valider le caratère
bool LireValiderEntierEntre(char pChar)
{
  char majChar; // déclation de la variable pour stocker les majuscules venant du paramètre pChar
  majChar = toupper(pChar);
  if (pChar == 'R' && pChar == 'T')
  {
    return 1;
  }
  else
  {
    return 0;
  }
}