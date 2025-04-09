#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


int main(){
   int position=0;
   int choix;
   int avancer;
   int victoire;
   
   
   printf("Niveau initial: 0\n");
   while(position!=13){
   
   if(victoire==1){
    
   printf("Passez au prochain niveau:\n");
   
   switch(position){
         case 0:
             printf("Niveau actuel: 0\n");
             
             do{
                 printf("Choississez entre secteur 1 ou 2.\n");
                 scanf("%d", &choix);
             }while((choix!=1)&&(choix!=2));
             if(choix==1){
                 position=1;
                 }
             else{
                 position=2;
                 }
             
            
             break;   
             
          case 1:
             printf("Niveau actuel: 1\n");
             do{
                 printf("Choississez entre 3 ou 4.\n");
                 scanf("%d", &choix);
             }while((choix!=3)&&(choix!=4));
             if(choix==3){
                 position=3;
                 }
             else{
                 position=4;
                 }
             
          
             break;
             
          case 2:
             printf("Niveau actuel: 2\n");
             
             do{
                 printf("Choississez entre 5 ou 6.\n");
                 scanf("%d", &choix);
             }while((choix!=5)&&(choix!=6));
             if(choix==5){
                 position=5;
                 }
             else{
                 position=6;
                 }
               

             break;    
             
             
           case 3:
             printf("Niveau actuel: 3\n");
            
             do{
                 printf("Choississez entre 7 ou 8.\n");
                 scanf("%d", &choix);
             }while((choix!=7)&&(choix!=8));
             if(choix==7){
                 position=7;
                 printf("Niveau secret, position actuel: 7\n");
                 }
             else{
                 position=8;
                 }
               
              
             break;
             
           case 4:
             printf("Niveau actuel: 4\n");
             
             do{
                 printf("Choississez entre 8 ou 9.\n");
                 scanf("%d", &choix);
             }while((choix!=8)&&(choix!=9));
             if(choix==8){
                 position=8;
                 }
             else{
                 position=9;
                 }
               
              
             break;
             
            case 5:
             printf("Niveau actuel: 5\n");
             
             do{
                 printf("Choississez entre 9 ou 10.\n");
                 scanf("%d", &choix);
             }while((choix!=10)&&(choix!=9));
             if(choix==10){
                 position=10;
                 }
             else{
                 position=9;
                 }
              
              
             break;
             
            case 6:
             printf("Niveau actuel: 6\n");
             position=10;
             
             break;
             
           case 8:
             printf("Niveau actuel: 8\n");
             position=11;
           
             break;
             
           case 9:
             printf("Niveau actuel: 9\n");
            
             do{
                 printf("Choississez entre 11 ou 12.\n");
                 scanf("%d", &choix);
             }while((choix!=11)&&(choix!=12));
             if(choix==11){
                 position=11;
                 }
             else{
                 position=12;
                 }
               
              
             break;
             
           case 10:
             printf("Niveau actuel: 10\n");
             position=12;
             
             
             break; 
             
           case 11:
             printf("Niveau actuel: 11\n");
             position=13;
             
             break;
             
              
           case 12:
             printf("Niveau actuel: 12\n");
             position=13;
             
             break;
             
           case 13:
             printf("Niveau actuel: 13\n");
             position=13;
             
             break;
             
           default:
              printf("erreur de secteur\n"); 
             
              exit(100);

             
             return position;
    
      }
      
      printf("Niveau actuel: %d\n", position);
      }
      
      else{
         printf("Niveau invaincu, réessayez!\n");
         printf("Niveau actuel: %d\n", position);
         
         }
         
      return 0;
      }
