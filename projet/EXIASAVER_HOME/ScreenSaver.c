#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main(int argc, char *argv[])

{

	int i;
	char *arguments1[] = { "Statique", NULL };
	char *arguments2[] = {"Intéractif", NULL};
	char *arguments3[] = {"dynamique", NULL};

	system("clear");
	srand(time(NULL));
	i=rand()%3;



	if (i==0)
		{
			if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/Statique", arguments1)) {

				perror("execv");
				return EXIT_FAILURE;
			}

		}



	if (i==1)
                {
                        if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/Intéractif", arguments2))  {

                                perror("execv");
                                return EXIT_FAILURE;
                        }

                }

	if (i==2)
                {
                        if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/dynamique", arguments3)) {

                                perror("execv");
                                return EXIT_FAILURE;
                        }

                }



    return EXIT_SUCCESS;

}
