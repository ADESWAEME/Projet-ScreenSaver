#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main ()

{

	char *arguments[]={"ScreenSaver",NULL};
	system("clear");	//Permet de supprimer le contenu du terminal

	if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/ScreenSaver",arguments)){

			perror("execv");
			return EXIT_FAILURE;
		}


	return EXIT_SUCCESS;

}

