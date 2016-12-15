
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

void longueur(int l) //permet de centrer dans le sens de la longueur en fonction de la taille des ligne du fichier PBM
{
	if (l<80) //SI la taille de la ligne est plus petite que la taille en longueur du terminal (80)
		{
		int const n=(80-l)/2; //calcul de n qui servira au centrage
		int i; //variable servant pour la boucle POUR

		for(i=0; i<n; i++) //boucle rajoutant n fois ' ' afin de centrer la ligne
		{
			printf(" ");
		}
	}
}

void hauteur(int h)// permet de centrer l'image en hauteur
{
	if (h<24)//SI le nombre de ligne du fichier PBM ne dépasse pas le nombre de ligne du terminal (24)
	{
		int const n=((24-h)/2)-2;//calcul de n
		int i;//variable utilisée dans la boucle POUR

		for(i=0; i<n; i++)//fait n fois un retour à la ligne pour centrer l'image
		{
			printf("\n");
		}
	}
}

