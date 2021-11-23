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

/*// Déclation et définition de la fonction  LireValiderEntierEntre ) à fin de valider le caratère
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
}*/

// Déclation et définition de la fonction  LireValiderEntierEntre ) à fin de valider le caratère
void lireValider2Char(char pChar)
{
  /*char majChar;             // déclation de la variable pour stocker les majuscules venant du paramètre pChar
  majChar = toupper(pChar); //conversion en majusucule*/

  // controle de charatère
  do 
  {
    cout << "Votre entree est incorrecte."
         << "S.V.P. reessayez : ";
    cin >> pChar;
  }while (pChar != 'R' && pChar != 'T');
}

// Déclation et définition de la fonction  LireValiderEntierEntre  à fin de valider les données sur la durée du séjour
void lireValiderEntierEntre(int pDureeSejour)
{
  // aussi longtemps que l'ulilisateur entrera un entier non compris entre 1 et 14 on en validera pas
  while (pDureeSejour < 1 || pDureeSejour > 14)
  {
    /*
      efface le flux, appelle une fonction d'ignorance. Cette fonction efface un nombre 
      déterminé de caractères, jusqu'à un caractère de nouvelle ligne. Ensuite, elle demande 
      une meilleure entrée
    */
    do
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Votre entree est incorrecte."
           << "\nS.V.P. reessayez : ";
    } while (!(cin >> pDureeSejour));
  }
}

// Déclation et définition de la fonction  LireValiderEntierEntre  à fin de valider le nombre d'enfant
void validerNbEnfant(int pNbEnfant)
{
  // aussi longtemps que l'ulilisateur entrera un entier non compris entre 0 et 12 ans inclusivement on en validera pas
  while (pNbEnfant < 0 || pNbEnfant > 12)
  {
    do
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Votre entree est incorrecte."
           << "S.V.P. reessayez : ";
    } while (!(cin >> pNbEnfant));
  }
}

// Déclation et définition de la fonction  LireValiderEntierEntre  à fin de valider l'age des enfants
void validerAgeEnfant(int pAgeEnfant)
{
  // aussi longtemps que l'ulilisateur entrera un entier non compris entre 0 et 12 ans inclusivement on en validera pas
  while (pAgeEnfant < 0 || pAgeEnfant > 12)
  {
    do
    {
      cin.clear();
      cin.ignore(100, '\n');
      cout << "Votre entree est incorrecte."
           << "S.V.P. reessayez : ";
    } while (!(cin >> pAgeEnfant));
  }
}

// renvoie le rabais pour les enfants
float retourRabaisEnfant(int pAgeEnfant)
{
  if (pAgeEnfant <= 5){
    return 0.04;
  }else if(pAgeEnfant <= 8 )
  {
    return 0.03;
  }else
  {
    return 0.02;
  }
}
