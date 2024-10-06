#ifndef TIC_TAC_TOE_H
#define TIC_TAC_TOE_H

#define TAILLE_GRILLE 3

void afficher_grille(char grille[TAILLE_GRILLE][TAILLE_GRILLE]);
int coup_valide(char grille[TAILLE_GRILLE][TAILLE_GRILLE], int coup);
void jouer_coup(char grille[TAILLE_GRILLE][TAILLE_GRILLE], int coup, char symbole);
int verifier_victoire(char grille[TAILLE_GRILLE][TAILLE_GRILLE], char symbole);
int grille_pleine(char grille[TAILLE_GRILLE][TAILLE_GRILLE]);
int coup_ordinateur(char grille[TAILLE_GRILLE][TAILLE_GRILLE]);

#endif