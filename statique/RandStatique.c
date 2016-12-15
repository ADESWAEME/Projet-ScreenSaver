#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main ()
{

        int i ;                 // Variable entier i
        system ("clear");       // Permet de supprimer le contenu affiché par le termnial
        srand (time(NULL));     // Donne le pramètre temps qui change la val
        i=rand()%3;             // Choix entre trois nombres soit: 0,1 ou 2
        printf ("%d,\n",i);     // Résultat du choix aléatoire

                if (i==0)       // Condition SI
                        {
		                system("./castle"); // Instruction à suivre
    			}

                if (i==1)       // Condition SI
                        {
			        system("./spaceship"); //Instruction à suivre
			}
                if (i==2)       // Condition SI
                    	{
                                system("./exia");       // Instruction à suivre
                        }

return 0;
}


