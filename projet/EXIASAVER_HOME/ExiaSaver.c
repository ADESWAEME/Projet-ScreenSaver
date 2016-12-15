#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "processtime.h"

int main (int argc, char *argv[])

{

	char *arguments[]={"ScreenSaver",NULL};
	char *arguments7[]={"stat",NULL};
	system("clear");	//Permet de supprimer le contenu du terminal
	if(strcmp(argv[1],"-stat")==0) //SI le paramètre -stat est mis
	{
		if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/stat",arguments7)){
			perror("execv");
			return EXIT_FAILURE;
			}
	}
	else{
		process_time();
		if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/ScreenSaver",arguments)){
			perror("execv");
			return EXIT_FAILURE;
		}
	}

	return EXIT_SUCCESS;

}

