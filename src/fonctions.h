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

// Déclation et définition de la fonction  voidValiderUneEntre qui controle les types 
//de données et valides uniquement ceux qui sont correctes  
void voidValiderUneEntre(int pEntre)
{
  do
  {
    cin.clear();
    cin.ignore(100, '\n');
    cout << "Votre entrée est incorrecte."
         << "\nS.V.P. reessayez : ";
  } while (!(cin >> pEntre));
}

// Déclation et définition de la fonction  LireValiderEntierEntre ) à fin de valider le caratère
void lireValider2Char(char pChar)
{
  /*char majChar;             // déclation de la variable pour stocker les majuscules venant du paramètre pChar
  majChar = toupper(pChar); //conversion en majusucule*/

  // controle de charatère
  while (pChar != 'R' && pChar != 'T')
  {
    cout << "Votre entrée est incorrecte."
         << "S.V.P. reessayez : ";
    cin >> pChar;
  } 
}

// Déclation et définition de la fonction  LireValiderEntierEntre  à fin de 
//valider les données sur la durée du séjour
void lireValiderEntierEntre(int pBorn1, int pBorne2, int pNbrAController)
  {
    while (pNbrAController < pBorn1 || pNbrAController > pBorne2)
    {
      voidValiderUneEntre(pNbrAController);
    }
  } 

// renvoie le rabais pour les enfants
double retourRabaisEnfant(int pAgeEnfant)
{
  //Constante pour les differents rabais pour les enfants
const double TARIF_ENFANT_MOINS_6_ANS(0.04);
const double TARIF_ENFANT_MOINS_9_ANS(0.03);
const double TARIF_ENFANT_MOINS_13_ANS(0.02);
  if (pAgeEnfant <= 5)
  {
    return TARIF_ENFANT_MOINS_6_ANS;
  }
  else if (pAgeEnfant <= 8)
  {
    return TARIF_ENFANT_MOINS_9_ANS;
  }
  else
  {
    return TARIF_ENFANT_MOINS_13_ANS;
  }
}

double retourTarifSejour(char pTypeSejour, int pDureeSejour)
{
  //Constante pour les differents Tarifs réguliers
  const int TARIF_REGULIER_3_JOUR(250);
  const int TARIF_REGULIER_7_JOUR(240);
  const int TARIF_REGULIER_14_JOUR(220);

  //Constante pour les differents Tarifs tout inclus
  const int TARIF_INCLUS_3_JOUR(350);
  const int TARIF_INCLUS_7_JOUR(340);
  const int TARIF_INCLUS_14_JOUR(320);

  if (pTypeSejour == 'R')
  {
    if (pDureeSejour <= 3)
    {
      return TARIF_REGULIER_3_JOUR * pDureeSejour;
    }
    else if (pDureeSejour <= 7)
    {
      return TARIF_REGULIER_7_JOUR * pDureeSejour;
    }
    else
    {
      return TARIF_REGULIER_14_JOUR * pDureeSejour;
    }
  }
  else
  {
    if (pDureeSejour <= 3)
    {
      return TARIF_INCLUS_3_JOUR * pDureeSejour;
    }
    else if (pDureeSejour <= 7)
    {
      return TARIF_INCLUS_7_JOUR * pDureeSejour;
    }
    else
    {
      return TARIF_INCLUS_14_JOUR * pDureeSejour;
    }
  }
}
