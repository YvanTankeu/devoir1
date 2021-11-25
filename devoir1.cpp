/*
  Titre      : Produire les factures
  Auteur     : Yvan Tankeu
  Date       : 22/11/2021
  Description: SYSTÈME DE FACTURATION POUR LE CLUB MED
  Version    : 0.0.1
*/

#include <iostream>
#include "fonctions.h"

//Constante min et max pour la fonction de controle des entiers
const int MIN_SEJOUR(1);
const int MAX_SEJOUR(14);
const int MIN_ENFANT(0);
const int MAX_ENFANT(12);
const int MIN_AGE_ENFANT(0);
const int MAX_AGE_ENFANT(12);

const double TAXE(0.15);

using namespace std;

int main()
{
  // Déclaration des variables et initialisation
  // des variables
  int choix(5), dureeSejour(0), nbrEnfant(0), ageEnfant(0);

  double tarif(0), tarifSejour(0), tarifApresRabais(0), totalFacture(0),
      rabaisPouEnfant(0), pourcentageDeRabaisParEnfant, totalPourcentRabaisEnfant(0), taxeTotal(0),
      montantTotal(0), nombreTotalFacture(0);

  string nomClient(""), typeSejourMot("Régulier");

  char typeSejour, typeSejourConvertir;

  // Affichage du menu et traitement de données
  while (choix > 0 and choix < 4 || choix > 4)
  {
    system("clear"); //effacer l'ecran

    // Afficher le menu
    menu();
    cin >> choix;
    

    // Traitement par choix
    switch (choix)
    {
    case 1:
      // Effacer l ecran
      system("clear");
      cout << "\n=== ENTRER DES INFORMATIONS ===\n\n";
      cout << "\nEntrez le nom du client : ";
      cin >> nomClient;

      cout << "\nEntrez la durée du sejour (un nombre entier "
           << "entre 1 et 14) : ";
      cin >> dureeSejour;
      lireValiderEntierEntre(MIN_SEJOUR, MAX_SEJOUR, dureeSejour);

      // Traitement et validation des données concernant les séjours
      cout << "Entrez le type de sejour (R - régulier ou T - tout"
           << " inclus) : ";
      cin >> typeSejour;

      typeSejourConvertir = toupper(typeSejour);

      if (typeSejour == 'T')
      {
        typeSejourMot == "Tout inclus";
      }

      // Appel de fonction pour la validation du caractère
      lireValider2Char(typeSejourConvertir);

      cout << "\nEntrez le nombre d'enfant(s) (un nombre entier entre"
           << " 0 et 12) : ";
      cin >> nbrEnfant;

      // Appel de fonction pour la validation du nombre d'enfant
      lireValiderEntierEntre(MIN_ENFANT, MAX_ENFANT, nbrEnfant);
      if(nbrEnfant != 0){
          for (int i = 1; i < nbrEnfant + 1; i++)
        {
          cout << "Entrez l'age (moins de 12) de l'enfant #" << i << " : ";
          cin >> ageEnfant;

          // Validation de l'age des enfants
          lireValiderEntierEntre(MIN_AGE_ENFANT, MAX_AGE_ENFANT, ageEnfant);

          totalPourcentRabaisEnfant = totalPourcentRabaisEnfant + (retourRabaisEnfant(ageEnfant)) * 100;
        }
      }
      

      /*
         Traitement du sejour s'il est régulier ou non
         via la fonction retour sejour qui nous renvera la
         le tarif du sejour en fonction du type de sejour et le nombre
         de jour que va durer le séjour
      */
      tarifSejour = retourTarifSejour(typeSejour, dureeSejour);

      // coût de rabais pour les enfants
      rabaisPouEnfant = (tarifSejour * totalPourcentRabaisEnfant) / 100;
      tarifApresRabais = tarifSejour - rabaisPouEnfant; // coût après rabais pour les enfants
      taxeTotal = tarifApresRabais * TAXE;              // coût une fois la taxe appliqué
      montantTotal = tarifApresRabais + taxeTotal;      // Montant total à payer
      
      while(getchar() != '\n');
      menuPrincipal();
      
      break;
      
    case 2:
      //effacer l'ecran
      system("clear");
      cout << "\n\t\t\t\tCLUB MED FACTURE"
           << "\n\nNom du client: " << nomClient
           << "\nDurée du sejour: " << dureeSejour
           << "\nType de sejour: " << typeSejourMot
           << "\nNombre d'enfants: " << nbrEnfant
           << "\nCoût du sejour: " << tarifSejour << " $"
           << "\n\nRabais pour enfants (" << totalPourcentRabaisEnfant << " %"
           << "): " << rabaisPouEnfant << " $"
           << "\n\n==========="
           << "\nSous-total: " << tarifApresRabais << " $"
           << "\nTaxe (" << TAXE * 100 << " %"
           << "): " << taxeTotal << " $"
           << "\n==========="
           << "\n\nMontant à payer: " << montantTotal << " $\n";

      nombreTotalFacture = nombreTotalFacture + 1;
      totalFacture = totalFacture + montantTotal;

      while(getchar() != '\n');
      menuPrincipal();

      break;

    case 3:
      //effacer l'ecran
      system("clear");
      // Affiche du récapitulatif de la journée
      afficheRecapitulatif(nombreTotalFacture, totalFacture);

      while(getchar() != '\n');
      menuPrincipal();
      
      break;

    case 4:
      cout << "\nMerci d'avoir utilisé le logiciel de qualité crée par eltankeu01\n";
    }
  }
}