#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "sauvegarde.h"

int chargerNiveauSauvegarde() {
    FILE *fichier = fopen("save.txt", "r");//futur sauvegarde si elle existe
    if (fichier == NULL) {
        return 1;
}

int niveau = 1;
    fscanf(fichier, "niveau=%d", &niveau);
    fclose(fichier);
    return niveau;
}

void sauvegarderNiveau(int niveau) {
    FILE *fichier = fopen("save.txt", "w");
    if (fichier == NULL) {
        printf("Erreur lors de la sauvegarde !\n");
        return;
    }

    fprintf(fichier, "niveau=%d\n", niveau);
    fclose(fichier);
    printf("Sauvegarde effectuée (niveau %d).\n", niveau);

}
