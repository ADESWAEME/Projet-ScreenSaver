#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include "centrage.h"
#include "conio.h"


int main (int argc, char *argv[])

{

        FILE* fichier = NULL;
        system("clear");        // Efface tous se qui est sur le terminal pour plus de clarté
        fichier = fopen("exia.pbm","r");       // Ouverture du fichier 'ImageStatique'

        char ligne [255];
        int i = 0;      //Caractère qui représente un espace : ' '
        int n = 35;     // Caractère de la tabla ASCII : #


        while (fgets(ligne,255,fichier) != NULL)        // Boucle qui affiche chaque ligne du fichier sélectionné

                {
                        hauteur(24);

                        for (i=0; i<80; i++)
                                {
                                        longueur(80);
                                        if(ligne[i] == '1')
                                                {
                                                        printf("%c",n);
                                                }
                                        if(ligne[i] == '0')
                                                {
                                                        printf(" ");
                                                }

                                }
                        printf("\n");


                }


        getch();
        system("clear");
        exit(0);

}
