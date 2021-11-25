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

int main(void)
{
  int m;
  if(m = 3 ){
    //cin >> toupper(m);
  }
  printf("Appuyez sur une touche pour afficher le menu...\n" );
  while(getchar() != '\n');
}



