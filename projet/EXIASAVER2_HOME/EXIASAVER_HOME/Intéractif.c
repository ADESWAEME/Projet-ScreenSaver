#include <ncurses.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "kbhit.h"
#define DELAY 30000

int main(int argc, char *argv[])
{
	FILE* fichierst=fopen("stat.txt","r+");
	int x, y ;//initialise les variable servant de coordonnées
	int max_y = 0, max_x = 0;//initialise les variable servant pour définir le bord de l'écran
	int next_x = 0;
	int next_y = 0;//initialise les variable lié au mouvement de l'avion
	int directionx ;
	int directiony ;//initialise les variable lié à la direction que prend l'avion
	char c;//variable servant au switch
	int continuer;//variable servant pour la boucle
	srand (time(NULL));
	x=rand()%80;
	y=rand()%24;
	fseek(fichierst,0,SEEK_END);
	fprintf(fichierst,"%dx%d",y,x);
	continuer=rand()%3+1;//donne au variablex,y et continuer un nombre random
	initscr();
	raw();//permet de passer en mode raw grace à la bibliothèque ncurses
	noecho();//permet de ne pas avoir de problème avec l'anfoncement des touche
	curs_set(FALSE);
	nodelay(stdscr, TRUE);//permet au getch() de ne pas avoir à attendre q'une touche soit enfoncé
	keypad(stdscr, TRUE);//initialise les touche du clavier

 	getmaxyx(stdscr, max_y, max_x);//définit les bord du terminal

	while(continuer!=0)//boucle primaire du programme (tant qu'on en sort pas le programme continue)
	{
		while(continuer==1)//boucle secondaire, chaque boucle constitue un direction
		{
			directionx=1;//variable lié à la direction que prend l'avion
			directiony=0;
			clear();//= system("clear")
			mvprintw(y, x, "#");
			mvprintw(y, x+1, "#");
			mvprintw(y, x+2, "#");
			mvprintw(y, x-1, "#");
			mvprintw(y, x-2, "#");
			mvprintw(y, x-3, "#");
			mvprintw(y-1, x, "#");
			mvprintw(y-2, x-1, "#");
			mvprintw(y+2, x-1, "#");
			mvprintw(y+1, x, "#");
			mvprintw(y-1, x-3, "#");// inprime l'avion sur le terminal dans la bonne direction
			refresh();//rafraichie l'affichage de l'avion après un changement de coordonnée
			usleep(DELAY);// attente avant que la boucle continue
			if (kbhit())//SI une touche est enfoncée
			{
				c=getch();
				switch(c){//switch permettant de changer de boucle si l'une des touche à l'intérieur est appuyée
					case('x'):
						continuer=0;
						break;
					case('z'):
						directionx=0;
						directiony=-1;
						continuer=2;
						break;
					case('q'):
						directionx=-1;
						directiony=0;
						continuer=3;
						break;
					case('s'):
						directionx=0;
						directiony=1;
						continuer=4;
						break;
					default:  break;
				}

			}
			next_x = x + directionx;
			next_y = y + directiony;// définie les nouvelle coordonnée x et y

			if (next_x >= max_x)//cas ou l'avion commence à sortir de l'écran
			{
				x=0;
			}
			else {x+= directionx;}
		}

		while(continuer==2)//idem que la boucle while(continuer==1)
		{
			directionx=0;
			directiony=-1;
			clear();
			mvprintw(y, x, "#");
			mvprintw(y+1, x, "#");
			mvprintw(y+2, x, "#");
			mvprintw(y+3, x, "#");
			mvprintw(y-1, x, "#");
			mvprintw(y-2, x, "#");
			mvprintw(y, x-1, "#");
			mvprintw(y+1, x-2, "#");
			mvprintw(y+1, x+2, "#");
			mvprintw(y, x+1, "#");
			mvprintw(y+3, x-1, "#");
			refresh();
			usleep(DELAY);
			if (kbhit())
			{
				c=getch();
				switch(c){
					case('x'):
						continuer=0;
						break;
					case('d'):
						directionx=1;
						directiony=0;
						continuer=1;
						break;
					case('q'):
						directionx=-1;
						directiony=0;
						continuer=3;
						break;
					case('s'):
						directionx=0;
						directiony=1;
						continuer=4;
						break;
					default: break;
				}
			}

			next_x = x + directionx;
			next_y = y + directiony;

			if (next_y <= 0)
			{
				y=max_y;
			}
			else {y+= directiony;}
		}

		while(continuer==3)//idem
		{
			directionx=-1;
			directiony=0;
			clear();
			mvprintw(y, x, "#");
			mvprintw(y, x-1, "#");
			mvprintw(y, x-2, "#");
			mvprintw(y, x+1, "#");
			mvprintw(y, x+2, "#");
			mvprintw(y, x+3, "#");
			mvprintw(y-1, x, "#");
			mvprintw(y-2, x+1, "#");
			mvprintw(y+2, x+1, "#");
			mvprintw(y+1, x, "#");
			mvprintw(y-1, x+3, "#");
			refresh();
			usleep(DELAY);
			if (kbhit())
			{
				c=getch();
				switch(c){
					case('x'):
						continuer=0;
						break;
					case('z'):
						directionx=0;
						directiony=-1;
						continuer=2;
						break;
					case('d'):
						directionx=1;
						directiony=0;
						continuer=1;
						break;
					case('s'):
						directionx=0;
						directiony=1;
						continuer=4;
						break;
					default:  break;
				}
			}
			next_x = x + directionx;
			next_y = y + directiony;

			if (next_x <= 0)
			{
				x=max_x;
			}
			else{x+=directionx;}
		}

		while(continuer==4)//idem
		{
			directionx=0;
			directiony=1;
			clear();
			mvprintw(y, x, "#");
			mvprintw(y-1, x, "#");
			mvprintw(y-2, x, "#");
				mvprintw(y-3, x, "#");
			mvprintw(y+1, x, "#");
			mvprintw(y+2, x, "#");
			mvprintw(y, x-1, "#");
			mvprintw(y, x+1, "#");
			mvprintw(y-1, x-2, "#");
			mvprintw(y-1, x+2, "#");
			mvprintw(y-3, x+1, "#");
			refresh();
			usleep(DELAY);
			if (kbhit())
			{
				c=getch();
				switch(c){
					case('x'):
						continuer=0;
						break;
					case('z'):
						directionx=0;
						directiony=-1;
						continuer=2;
						break;
					case('q'):
						directionx=-1;
						directiony=0;
						continuer=3;
						break;
					case('d'):
						directionx=1;
						directiony=0;
						continuer=1;
						break;
					default:  break;
				}
			}
			next_x = x + directionx;
			next_y = y + directiony;

			if(next_y >= max_y)
			{
				y=0;
			}
			else{y+= directiony;}
		}//sorti de la boucle quand continuer==0
	}
	endwin();//sort du mode raw
}
