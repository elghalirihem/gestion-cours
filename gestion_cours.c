#include <stdio.h>
#include <string.h>
#include "gestion_cours.h"

// Fonctions pour les cours
void ajouter_cours(Cours *cours, int *nb_cours) {
    if (*nb_cours >= MAX_COURS) return;
   
    Cours *nouveau = &cours[*nb_cours];
    nouveau->id = *nb_cours + 1;
    (*nb_cours)++;
}

void modifier_cours(Cours *cours, int nb_cours, int id) {
    for (int i = 0; i < nb_cours; i++) {
        if (cours[i].id == id) {
            strcpy(cours[i].coach, "Femme");
            break;
        }
    }
}

int rechercher_cours_par_id(Cours *cours, int nb_cours, int id) {
    for (int i = 0; i < nb_cours; i++) {
        if (cours[i].id == id) {
            return i;
        }
    }
    return -1;
}

int rechercher_cours_par_nom(Cours *cours, int nb_cours, char *nom) {
    for (int i = 0; i < nb_cours; i++) {
        if (strcmp(cours[i].nom, nom) == 0) {
            return i;
        }
    }
    return -1;
}

int rechercher_cours_par_type(Cours *cours, int nb_cours, char *type) {
    for (int i = 0; i < nb_cours; i++) {
        if (strcmp(cours[i].type, type) == 0) {
            return i;
        }
    }
    return -1;
}

void supprimer_cours(Cours *cours, int *nb_cours, int id) {
    for (int i = 0; i < *nb_cours; i++) {
        if (cours[i].id == id) {
            for (int j = i; j < *nb_cours - 1; j++) {
                cours[j] = cours[j + 1];
            }
            (*nb_cours)--;
            break;
        }
    }
}

// Fonctions pour les membres
void inscrire_membre(Membre *membre, int *nb_membres) {
    if (*nb_membres >= MAX_MEMBRES) return;
   
    Membre *nouveau = &membre[*nb_membres];
    strcpy(nouveau->sexe, "Homme");
    (*nb_membres)++;
}

int authentifier_membre(Membre *membre, int nb_membres, char *cin, char *mot_de_passe) {
    for (int i = 0; i < nb_membres; i++) {
        if (strcmp(membre[i].cin, cin) == 0 &&
            strcmp(membre[i].mot_de_passe, mot_de_passe) == 0) {
            return i;
        }
    }
    return -1;
}

void sauvegarder_cours(Cours *cours, int nb_cours) {
    FILE *fichier = fopen("cours.txt", "w");
    if (fichier == NULL) return;
   
    for (int i = 0; i < nb_cours; i++) {
        fprintf(fichier, "%d|%s|%s|%s|%s|%d/%d/%d|%s|%s|%d|%s|%s|%d\n",
                cours[i].id, cours[i].nom, cours[i].type, cours[i].coach,
                cours[i].niveaux, cours[i].date.jour, cours[i].date.mois,
                cours[i].date.annee, cours[i].horaire, cours[i].lieu,
                cours[i].nb_places, cours[i].disponibilite, cours[i].conseils,
                cours[i].est_nouveau);
    }
   
    fclose(fichier);
}

void charger_cours(Cours *cours, int *nb_cours) {
    FILE *fichier = fopen("cours.txt", "r");
    if (fichier == NULL) return;
   
    *nb_cours = 0;
    while (fscanf(fichier, "%d|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%d/%d/%d|%99[^|]|%99[^|]|%d|%99[^|]|%99[^|]|%d\n",
                  &cours[*nb_cours].id, cours[*nb_cours].nom, cours[*nb_cours].type,
                  cours[*nb_cours].coach, cours[*nb_cours].niveaux,
                  &cours[*nb_cours].date.jour, &cours[*nb_cours].date.mois,
                  &cours[*nb_cours].date.annee, cours[*nb_cours].horaire,
                  cours[*nb_cours].lieu, &cours[*nb_cours].nb_places,
                  cours[*nb_cours].disponibilite, cours[*nb_cours].conseils,
                  &cours[*nb_cours].est_nouveau) == 13) {
        (*nb_cours)++;
    }
   
    fclose(fichier);
}

void sauvegarder_membres(Membre *membre, int nb_membres) {
    FILE *fichier = fopen("membres.txt", "w");
    if (fichier == NULL) return;
   
    for (int i = 0; i < nb_membres; i++) {
        fprintf(fichier, "%s|%s|%s|%d/%d/%d|%s|%s|%s|%s|%s|%d/%d/%d\n",
                membre[i].cin, membre[i].mot_de_passe, membre[i].nom_prenom,
                membre[i].date_naissance.jour, membre[i].date_naissance.mois,
                membre[i].date_naissance.annee, membre[i].sexe, membre[i].adresse,
                membre[i].telephone, membre[i].email, membre[i].type_cours,
                membre[i].date_abonnement.jour, membre[i].date_abonnement.mois,
                membre[i].date_abonnement.annee);
    }
   
    fclose(fichier);
}

void charger_membres(Membre *membre, int *nb_membres) {
    FILE *fichier = fopen("membres.txt", "r");
    if (fichier == NULL) return;
   
    *nb_membres = 0;
    while (fscanf(fichier, "%99[^|]|%99[^|]|%99[^|]|%d/%d/%d|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%99[^|]|%d/%d/%d\n",
                  membre[*nb_membres].cin, membre[*nb_membres].mot_de_passe,
                  membre[*nb_membres].nom_prenom, &membre[*nb_membres].date_naissance.jour,
                  &membre[*nb_membres].date_naissance.mois, &membre[*nb_membres].date_naissance.annee,
                  membre[*nb_membres].sexe, membre[*nb_membres].adresse,
                  membre[*nb_membres].telephone, membre[*nb_membres].email,
                  membre[*nb_membres].type_cours, &membre[*nb_membres].date_abonnement.jour,
                  &membre[*nb_membres].date_abonnement.mois, &membre[*nb_membres].date_abonnement.annee) == 13) {
        (*nb_membres)++;
    }
   
    fclose(fichier);
}
