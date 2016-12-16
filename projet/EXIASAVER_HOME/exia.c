#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "centrage.h"
#include "conio.h"
#include <sys/wait.h>

int main (int argc, char *argv[])	// appel de la fonction du programme

{

        FILE* fichier = NULL;	// création du pointeur qui est initialisé à NULL
        system("clear");        // Efface tous se qui est sur le terminal pour plus de clarté
        fichier = fopen("exia.pbm","r");       // Ouverture du fichier 'ImageStatique'


        char ligne [255];	// Initialisation de la chaîne
        int i = 0;      //Caractère qui représente un espace : ' '
        int n = 35;     // Caractère de la tabla ASCII : #


	        while (fgets(ligne,255,fichier) != NULL)        // Boucle qui affiche chaque ligne du fichier sélectionné

	                {
        	                hauteur(24);	// définit la hauteur de 24 caractères

	                        for (i=0; i<80; i++)	// boucle for qui va afficher tous les caractères pendant que i < 80
        	                        {
                	                        longueur(80);	// définit la longueur de 80 caractère
                        	                if(ligne[i] == '1')	// condition
                                	                {
                                        	                printf("%c",n);	// instruction à suivre 
      	                                          }
        	                                if(ligne[i] == '0')	// condition
                	                                {
                        	                                printf(" ");	//instruction
                                	                }

                        	        }
                       		 printf("\n");	// revenir à la ligne


	                }


        	getch();	// attente d'un caratère envoyer avant de continuer le programme

	
	system("clear");	// permet de nettoyer le terminal
        exit(0);	// arrêt du programme

}
