all: exec

Lefichiermain.o: main.c Fonction.h Multijoueur.c Sauvegarde.c sauvegarde.h constante.h structure.h ecrandedemarrage
               gcc -c main.c -o main.o
structure.o : constante.h structure.h
               gcc -c structure.h -o structure.o
Sauvegarde.o : constante.h Sauvegarde.h
               gcc -c Sauvegarde.h -o Sauvegarde.o
structure.o : structure.h constante.h
               gcc -c structure.h -o structure.o
constante.o : constante.h 
             gcc -c constante.c -o constante.o
ecrandedemarrage.o : constance.h  
           gcc -c ecrandedemarrage.c -o ecrandedemarrage.o

rm -f *.o
rm exec 


              
