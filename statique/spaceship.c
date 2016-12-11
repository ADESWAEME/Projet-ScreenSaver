#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <conio.h>
#include "affichage.h"

#define ANSI_COLOR_RED "\033[22;31m"//définit la couleur rouge

void main()
{
	char *filename= "spaceship.pbm";//définit le fichier dans lequel on va prendre l'image
	char *color= ANSI_COLOR_RED;//définit couleur de l'image
	affichage(&filename,20,15,&color);//voir affichage.h
	getch();//attend que l'utilisateur appuie sur une touche avant de fermé le programme.
	system("clear");//néttoie le terminal avant de redonner la main à l'utilateur
	exit(0);//ferm le programme
}


