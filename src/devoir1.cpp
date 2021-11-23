/*
  Titre      : produire les factures
  Auteur     : Yvan Tankeu
  Date       : 22/11/2021
  Description: Un programme pour facture
  Version    : 0.0.1
*/

#include <iostream>
#include "fonctions.h"

//Constante pour les differents Tarifs réguliers
const int TARIF_REGULIER_3_JOUR(250);
const int TARIF_REGULIER_9_JOUR(240);
const int TARIF_REGULIER_15_JOUR(220);

//Constante pour les differents Tarifs tout inclus
const int TARIF_INCLUS_3_JOUR(350);
const int TARIF_INCLUS_9_JOUR(340);
const int TARIF_INCLUS_15_JOUR(320);

//Constante pour les differents rabais pour les enfants
const float TARIF_ENFANT_MOINS_6_ANS(0.04);
const float TARIF_ENFANT_MOINS_9_ANS(0.03);
const float TARIF_ENFANT_MOINS_13_ANS(0.02);
const float TAXE(0.15);

using namespace std;

int main()
{

  // Déclaration des variables et initialisation
  // des variables
  int choix(5), dureeSejour(0), nbrEnfant(0), sommeFacture(0),ageEnfant(0);

  float tarif(0), tarifSejour(0), tarifApresRabais(0), totalFacture(0),
      rabaisPouEnfant(0), totalPourcentRabaisEnfant(0), taxeTotal(0),
      montantTotal(0);

  string nomClient("");

  char typeSejour, typeSejourConvertir;

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
      cout << "\n=== ENTRER DES INFORMATIONS ===\n\n";
      cout << "\nEntrer le nom du client : ";
      cin >> nomClient;

      cout << "\nEntrer la durée du sejour (un nombre entier "
           << "entre 1 et 14) : ";
      cin >> dureeSejour;
      lireValiderEntierEntre(dureeSejour);

      // Traitement et validation des données concernant les séjours
      cout << "Entrer le type de sejour (R - régulier ou T - tout"
           << " inclus) : ";
      cin >> typeSejour;
      typeSejourConvertir = toupper(typeSejour);

      // Appel de fonction pour la validation du caractère
      lireValider2Char(typeSejour);
      cout << "\nEntrer le nombre d'enfant(s) (un nombre entier entre"
           << " 0 et 12) : ";
      cin >> nbrEnfant;

      // Appel de fonction pour la validation du nombre d'enfant
      validerNbEnfant(nbrEnfant);
      for (int i = 1; i < nbrEnfant + 1; i++)
      {
        cout << "Entrer l'age (moins de 12) de l'enfant #" << i << " : ";
        cin >> ageEnfant;

        // Appel de fonction pour la validation de l'ahe des enfants
        validerAgeEnfant(ageEnfant);
      }

      // Traitement du sejour s'il est régulier ou non
      // via la fonction retour sejour qui nous renvera la
      // le tarif du sejour en fonction du type de sejour et le nombre
      // de jour que va durer le séjour
      tarifSejour = retourTarifSejour(typeSejour, dureeSejour);
      /*if (typeSejour == 'R')
      {
        if (dureeSejour <= 3)
        {
          tarif = TARIF_REGULIER_3_JOUR * dureeSejour;
        }
        else if (dureeSejour <= 7)
        {
          tarif = TARIF_REGULIER_9_JOUR * dureeSejour;
        }
        else
        {
          tarif = TARIF_REGULIER_15_JOUR * dureeSejour;
        }
      }
      else
      {
        if (dureeSejour <= 3)
        {
          tarif = TARIF_INCLUS_3_JOUR * dureeSejour;
        }
        else if (dureeSejour <= 7)
        {
          tarif = TARIF_INCLUS_9_JOUR * dureeSejour;
        }
        else
        {
          tarif = TARIF_INCLUS_15_JOUR * dureeSejour;
        }
      }*/

      //Traitement en fonction des enfants
      // grace à la boucle on a le pourcentage total de rabais des enfants
      for (int i = 0; i < nbrEnfant; i++)
      {
        // Trouver le pourcentage de rabais en pourcent
        totalPourcentRabaisEnfant = totalPourcentRabaisEnfant + (retourRabaisEnfant(ageEnfant)) * 100;
        /*if (ageEnfant <= 5)
        {
          totalPourcentRabaisEnfant = totalPourcentRabaisEnfant + retourRabaisEnfant(ageEnfant);
        }
        else if (ageEnfant <= 8)
        {
          totalPourcentRabaisEnfant = totalPourcentRabaisEnfant + retourRabaisEnfant(ageEnfant);
        }
        else{
          totalPourcentRabaisEnfant = totalPourcentRabaisEnfant + retourRabaisEnfant(ageEnfant);
        }*/
      }

      // coût de rabais pour les enfants
      rabaisPouEnfant = (tarifSejour * totalPourcentRabaisEnfant) / 100;
      tarifApresRabais = tarifSejour - rabaisPouEnfant; // coût après rabais pour les enfants
      taxeTotal = tarifApresRabais * TAXE;              // coût une fois la taxe appliqué
      montantTotal = tarifApresRabais + taxeTotal;      // Montant total à payer

    case 2:
      cout << "\nEntrer le nom du client : ";
      cin >> nomClient;

      sommeFacture = sommeFacture + 1;
      totalFacture = totalFacture + 1;
    }
  }
}