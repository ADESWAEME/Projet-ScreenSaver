#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>



int main(int argc, char *argv[])


{

	int i;
	char *arguments1[] = { "Statique", NULL };
	char *arguments2[] = {"Intéractif", NULL};
	char *arguments3[] = {"dynamique", NULL};
	FILE* fichierst=fopen("stat.txt","r+");
	system("clear");
	srand(time(NULL));
	i=rand()%3;


	 if (argv[1]!=NULL){




		if(strcmp(argv[1],"exiasaver1")==0){i=0;}
		if(strcmp(argv[1],"exiasaver2")==0){i=2;}
		if(strcmp(argv[1],"exiasaver3")==0){i=1;}


	}

		else{

			if (i==0)
				{
					fseek(fichierst,0,SEEK_END);
					fprintf(fichierst,"(1);");
					fclose(fichierst);
					if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/Statique", arguments1)) {

						perror("execv");
						return EXIT_FAILURE;
					}

				}



			if (i==1)
                		{
					fseek(fichierst,0,SEEK_END);
					fprintf(fichierst,"(3);");
					fclose(fichierst);
                       			if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/Intéractif", arguments2))  {

                 		               perror("execv");
                        		        return EXIT_FAILURE;
	               		        }

		    		}


			if (i==2)
		                {
					fseek(fichierst,0,SEEK_END);
					fprintf(fichierst,"(2);5x3\n");
				        fclose(fichierst);
					if (execv("/home/alexandra/Documents/CESI/U2/Projet/Projet-ScreenSaver/projet/EXIASAVER_HOME/dynamique", arguments3)) {

                                		perror("execv");
                                		return EXIT_FAILURE;
                        		}
               			}
			}



   	 return EXIT_SUCCESS;

}

