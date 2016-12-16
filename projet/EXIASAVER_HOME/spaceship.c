#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include "conio.h"
#include "affichage.h"
#include <sys/wait.h>

#define ANSI_COLOR_RED "\033[22;31m"//définit la couleur rouge

void main ()

{
        char *filename= "spaceship.pbm";//introduit le nom du fichier dans un pointeur pour l'env$
        char *color= ANSI_COLOR_RED;//définir la couleur de l'image
        pid_t pid;
        pid = fork();

        if (pid == 0){

        affichage(&filename,20,20,&color);//voir affichage.h
        getch();//permet d'attendre que l'utilisateur appuie sur n'importe quel touche du clav$

                }

        else{

                wait(NULL);
                system("clear");//néttoie l'affichage du terminal avant de redonner la main à $
                exit(0);//sorti du programme

        }
}


