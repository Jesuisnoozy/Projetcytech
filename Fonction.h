#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include <fcntl.h> // Pour Créer des fichiers (Je sais que y'a pas que ça mais j'en vois surtout cette utilité) 
#include <unistd.h> // Pour supprimer des fichiers (idem)
int main(){
    char tab[51][95];   
    for(int i = 0; i < 51; i++) {
      for(int j = 0; j < 90; j++) {
            tab[i][j] = ' ';
            if (i == 0 || i == 49) {
                tab[i][j] = '_';
            }
            if (j == 0 || j == 89) {
                tab[i][j] = '|';
            }
            if ((i == 0 || i == 50 ) && (j == 0 || j == 89)){
               tab[i][j] = ' ' ;
            }
            if ((i > 20 && i < 30) && (j > 25 && j < 70)){
                tab[i][j]='X';
            }
            if ((i > 21 && i < 29) && (j > 26 && j < 69)){
                tab[i][j]=' ';
            }
            if ((i > 8 && i < 18) && (j > 25 && j < 70)){
                tab[i][j]='X';
            }
            if ((i > 9 && i < 17) && (j > 26 && j < 69)){
                tab[i][j]=' ';
            }    
            if ((i > 32 && i < 42) && (j > 25 && j < 70)){
                tab[i][j]='X';
            }
            if ((i > 33 && i < 41) && (j > 26 && j < 69)){
                tab[i][j]=' ';    
            }
            strcpy(tab[25],"|                         X               Continuer                  X                   |"); 
            strcpy(tab[13],"|                         X          Créer une sauvegarde            X                   |");
            strcpy(tab[37],"|                         X                 Paramètre                X                   |");
            tab[13][89]='|';
            tab[37][90]='|';
          
        }
       }
    for(int i = 0; i < 51; i++) {
        for(int j = 0; j < 90; j++) {
            printf("%c", tab[i][j]);
        }
        printf("\n");  
        }
    return 0;
}
