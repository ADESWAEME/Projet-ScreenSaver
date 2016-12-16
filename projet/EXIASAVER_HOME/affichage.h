#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "centrage.h"
#include <dirent.h>

#define ANSI_COLOR_RESET "\033[01;37m"//définit la couleur de base de l'affichage

void affichage(char **filename,int h,int l,char **color)
{
	DIR * rep = NULL;
	rep = opendir("/home/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/");
	FILE *fichier=fopen(*filename,"r"); //ouvre le fichier contenant l'image
	char ligne[80]; //définit le maximum de charactère sur une ligne
	int n=35;	//numéro en décimale sur la table ASCII du signe "#"
	int i=0;	//valeur servant pour la boucle d'affichage
	system("clear");	//éfface tous ce qui est inscrit dans le terminal

	hauteur(h); //voir centrage.h
	while(fgets(ligne,255,fichier)!=NULL) //début de la boucle TANT QUE le fichier PBM contient des charactère
	{
		longueur(l); //voir centrage.h
		for(i=0; i<79; i++) //début de la boucle POUR tout les charactère écrit sur une ligne (jusqu'à 80 charactère)
		{
			if(ligne[i]=='1')
			{
				if(ligne[0]=='#'){}
				else{printf("%s%c%s",*color,n,ANSI_COLOR_RESET);} //SI le charctère sur la ligne est un '1' le transforme en '#' de la couleur précisée a part si c'est une ligne de description(commence par '#')
			}
			if(ligne[i]=='0'){printf(" ");}//SI le charactère est un'0' le transforme en ' '
		}
		printf("\n");//va à la ligne quand une ligne est fini.
	}
	fclose(fichier);//ferme le fichier pour éviter les problème
	closedir(rep); //ferme le dossier
}


