/*
  Titre      : Fonctions
  Auteur     : Yvan Tankeu
  Date       : 22/11/2021
  Description: Fonctions propres au programme de facturation qui devront être utilisé dans le main
  Version    : 0.0.1
*/

#include <iostream>

using namespace std;

void voidValiderUneEntre(int pEntre)
{
  do
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Votre entree est incorrecte."
         << "\nS.V.P. reessayez : ";
  } while (!(cin >> pEntre));
}

 void lireValiderEntierEntre(int pBorn1, int pBorne2, int pNbrAController)
  {
    while (pNbrAController < pBorn1 || pNbrAController > pBorne2)
    {
      voidValiderUneEntre(pNbrAController);
    }
  }

int main()
{


  /*char typeSejour;

    cout << "\nEntrer le type de sejour (R - régulier ou T - tout inclus) : ";
    cin >> typeSejour;
    char majChar; // déclation de la variable pour stocker les majuscules venant du paramètre pChar
    majChar = toupper(typeSejour);

    // controle de  poids
    while (majChar != 'R' && majChar != 'T')
    {
        cout << "Votre entree est incorrecte."
             << "S.V.P. reessayez : "; // Poids du joueur en cours d'enregistrement
        cin >> majChar;                // Donnée poids stockée dans la variable poids
    }*/

  int dureSejour;

  cout << "\nEntrer la durée du sejour (un nombre entier entre 1 et 14): ";
  cin >> dureSejour;
  lireValiderEntierEntre(1,14,dureSejour);
}

