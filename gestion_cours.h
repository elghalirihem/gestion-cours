#ifndef COURS_H
#define COURS_H

#define MAX_STRING 100
#define MAX_COURS 100
#define MAX_MEMBRES 1000

// Structure pour la date
typedef struct {
    int jour;
    int mois;
    int annee;
} Date;

// Structure pour un cours sportif
typedef struct {
    int id;
    char nom[MAX_STRING];
    char type[MAX_STRING];
    char coach[MAX_STRING];
    char niveaux[MAX_STRING];
    Date date;
    char horaire[MAX_STRING];
    char lieu[MAX_STRING];
    int nb_places;
    char disponibilite[MAX_STRING]; // "jour" ou "soir"
    char conseils[MAX_STRING];
    int est_nouveau; // 0 ou 1
} Cours;

// Structure pour un membre
typedef struct {
    char cin[MAX_STRING];
    char mot_de_passe[MAX_STRING];
    char nom_prenom[MAX_STRING];
    Date date_naissance;
    char sexe[MAX_STRING];
    char adresse[MAX_STRING];
    char telephone[MAX_STRING];
    char email[MAX_STRING];
    char type_cours[MAX_STRING];
    Date date_abonnement;
} Membre;

// Déclarations des fonctions pour les cours
void ajouter_cours(Cours *cours, int *nb_cours);
void modifier_cours(Cours *cours, int nb_cours, int id);
int rechercher_cours_par_id(Cours *cours, int nb_cours, int id);
int rechercher_cours_par_nom(Cours *cours, int nb_cours, char *nom);
int rechercher_cours_par_type(Cours *cours, int nb_cours, char *type);
void supprimer_cours(Cours *cours, int *nb_cours, int id);
void sauvegarder_cours(Cours *cours, int nb_cours);
void charger_cours(Cours *cours, int *nb_cours);

// Déclarations des fonctions pour les membres
void inscrire_membre(Membre *membre, int *nb_membres);
int authentifier_membre(Membre *membre, int nb_membres, char *cin, char *mot_de_passe);
void sauvegarder_membres(Membre *membre, int nb_membres);
void charger_membres(Membre *membre, int *nb_membres);

#endif


