#include <stdio.h>

#include <stdlib.h>

#include <unistd.h>

#include <time.h>


int main(int argc, char *argv[])

{

    /* Tableau de char contenant les arguments (là aucun : le nom du

       programme et NULL sont obligatoires)  */

	int i;
	char *arguments4[] = { "spaceship", NULL };
	char *arguments5[] = {"exia", NULL};
	char *arguments6[] = {"castle", NULL};
	FILE* fichierst=fopen("stat.txt","r+");
	system("clear");
	srand(time(NULL));
	i=rand()%3;



	if (i==0)
		{
			fseek(fichierst,0,SEEK_END);
			fprintf(fichierst,"spaceship.pbm\n");
			fclose(fichierst);
			if (execv("spaceship", arguments4)) {

				perror("execv");
				return EXIT_FAILURE;
			}

		}



	if (i==1)
                {
			fseek(fichierst,0,SEEK_END);
			fprintf(fichierst,"exia.pbm\n");
                       	fclose(fichierst);
			if (execv("exia", arguments5)) {

                                perror("execv");
                                return EXIT_FAILURE;
                        }

                }

	if (i==2)
                {
			fseek(fichierst,0,SEEK_END);
			fprintf(fichierst,"castle.pbm\n");
                        fclose(fichierst);
			if (execv("castle", arguments6)) {

                                perror("execv");
                                return EXIT_FAILURE;
                        }

                }


    return EXIT_SUCCESS;

}
