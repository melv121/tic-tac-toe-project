#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "tic-tac-toe.h"

void afficher_grille(char grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
    printf("\n");
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            printf(" %c ", grille[i][j]);
            if (j < TAILLE_GRILLE - 1) printf("|");
        }
        printf("\n");
        if (i < TAILLE_GRILLE - 1) printf("-----------\n");
    }
    printf("\n");
}

int coup_valide(char grille[TAILLE_GRILLE][TAILLE_GRILLE], int coup) {
    int ligne = (coup - 1) / TAILLE_GRILLE;
    int colonne = (coup - 1) % TAILLE_GRILLE;
    return (coup >= 1 && coup <= 9 && grille[ligne][colonne] == ' ');
}

void jouer_coup(char grille[TAILLE_GRILLE][TAILLE_GRILLE], int coup, char symbole) {
    int ligne = (coup - 1) / TAILLE_GRILLE;
    int colonne = (coup - 1) % TAILLE_GRILLE;
    grille[ligne][colonne] = symbole;
}

int verifier_victoire(char grille[TAILLE_GRILLE][TAILLE_GRILLE], char symbole) {
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        if (grille[i][0] == symbole && grille[i][1] == symbole && grille[i][2] == symbole) return 1;
        if (grille[0][i] == symbole && grille[1][i] == symbole && grille[2][i] == symbole) return 1;
    }
    if (grille[0][0] == symbole && grille[1][1] == symbole && grille[2][2] == symbole) return 1;
    if (grille[0][2] == symbole && grille[1][1] == symbole && grille[2][0] == symbole) return 1;
    return 0;
}

int grille_pleine(char grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            if (grille[i][j] == ' ') return 0;
        }
    }
    return 1;
}

int coup_ordinateur(char grille[TAILLE_GRILLE][TAILLE_GRILLE]) {
    int coup;
    do {
        coup = rand() % 9 + 1;
    } while (!coup_valide(grille, coup));
    return coup;
}

int main() {
    char grille[TAILLE_GRILLE][TAILLE_GRILLE];
    int coup;
    char joueur = 'X', ordinateur = 'O';

    srand(time(NULL));

    for (int i = 0; i < TAILLE_GRILLE; i++) {
        for (int j = 0; j < TAILLE_GRILLE; j++) {
            grille[i][j] = ' ';
        }
    }

    printf("Bienvenue au jeu de Morpion !\n");
    printf("Vous êtes le joueur X. Entrez un numéro de 1 à 9 pour jouer.\n");

    while (1) {
        afficher_grille(grille);

        do {
            printf("Votre tour (1-9): ");
            scanf("%d", &coup);
        } while (!coup_valide(grille, coup));

        jouer_coup(grille, coup, joueur);

        if (verifier_victoire(grille, joueur)) {
            afficher_grille(grille);
            printf("Félicitations ! Vous avez gagné !\n");
            break;
        }

        if (grille_pleine(grille)) {
            afficher_grille(grille);
            printf("Match nul !\n");
            break;
        }

        coup = coup_ordinateur(grille);
        jouer_coup(grille, coup, ordinateur);
        printf("L'ordinateur a joué en case %d\n", coup);

        if (verifier_victoire(grille, ordinateur)) {
            afficher_grille(grille);
            printf("L'ordinateur a gagné !\n");
            break;
        }

        if (grille_pleine(grille)) {
            afficher_grille(grille);
            printf("Match nul !\n");
            break;
        }
    }

    return 0;
}