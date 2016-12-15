#include <ncurses.h>
#include <unistd.h>
#include "kbhit.h"
#define DELAY 30000

int main(int argc, char *argv[])
{
	int x = 40, y = 12;
	int max_y = 0, max_x = 0;
	int next_x = 0;
	int next_y = 0;
	int directionx = 1;
	int directiony = 0;
	char c;
	int continuer=1;
	initscr();
	raw();
	noecho();
	curs_set(FALSE);
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);

 	getmaxyx(stdscr, max_y, max_x);

	while(continuer!=0)
	{
		while(continuer==1)
		{
			clear();
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
			mvprintw(y-1, x-3, "#");
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

			if (next_x >= max_x)
			{
				x=0;
			}
			else {x+= directionx;}
		}

		while(continuer==2)
		{
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

		while(continuer==3)
		{
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

		while(continuer==4)
		{
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
		}
	}
	endwin();
}
