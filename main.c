#include <stdio.h>
#include "gestion_cours.h"

int main() {
    Cours cours[MAX_COURS];
    Membre membres[MAX_MEMBRES];
    int nb_cours = 0;
    int nb_membres = 0;
   
    // Test des fonctions
    ajouter_cours(cours, &nb_cours);
    inscrire_membre(membres, &nb_membres);
   
    // Sauvegarde
    sauvegarder_cours(cours, nb_cours);
    sauvegarder_membres(membres, nb_membres);
   
    return 0;
}
