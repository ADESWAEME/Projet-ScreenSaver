#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "conio.h"
#include "affichage.h"

#define ANSI_COLOR_BLUE "\033[22;34m"//définie la couleur bleu

void main()
{
	char *filename= "castle.pbm";//introduit le nom du fichier dans un pointeur pour l'envoyé dans affichage.h
	char *color= ANSI_COLOR_BLUE;//définir la couleur de l'image

	affichage(&filename,20,20,&color);//voir affichage.h
	getch();//permet d'attendre que l'utilisateur appuie sur n'importe quel touche du clavier avant de sortir du programme (ps:voir conio.h)
	system("clear");//néttoie l'affichage du terminal avant de redonner la main à l'utilisateur.
	exit(0);//sorti du programme
}


