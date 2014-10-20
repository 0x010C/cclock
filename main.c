#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ncurses.h>

#define HEIGHT getmaxy(stdscr)/2-3
#define MIDDLE getmaxx(stdscr)/2

void afficher(int num, int offset)
{
	switch(num)
	{
		case 0:
			mvprintw(HEIGHT+0,MIDDLE+offset,"####");
			mvprintw(HEIGHT+1,MIDDLE+offset,"#  #");
			mvprintw(HEIGHT+2,MIDDLE+offset,"#  #");
			mvprintw(HEIGHT+3,MIDDLE+offset,"#  #");
			mvprintw(HEIGHT+4,MIDDLE+offset,"#  #");
			mvprintw(HEIGHT+5,MIDDLE+offset,"#  #");
			mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;

		case 1:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"   #");
			break;

		case 2:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"#   ");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"#   ");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;

		case 3:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+3,MIDDLE+offset," ###");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;

		case 4:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"   #");
			break;

		case 5:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"#   ");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"#   ");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;

		case 6:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"#   ");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"#   ");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;

		case 7:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+3,MIDDLE+offset," ###");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"   #");
			break;

		case 8:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;

		case 9:
                        mvprintw(HEIGHT+0,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+1,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+2,MIDDLE+offset,"#  #");
                        mvprintw(HEIGHT+3,MIDDLE+offset,"####");
                        mvprintw(HEIGHT+4,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+5,MIDDLE+offset,"   #");
                        mvprintw(HEIGHT+6,MIDDLE+offset,"####");
			break;
	}
}

void afficherSec(int sec)
{
	int i=1;
	mvprintw(0,0,"%2d",sec);
	mvprintw(HEIGHT-1,MIDDLE,"#");
	for(;i<=sec && i<=11;i++)
		mvprintw(HEIGHT-1,MIDDLE+i,"#");
	for(;i<=sec && i<=19;i++)
		mvprintw(HEIGHT-1+(i-11),MIDDLE+11,"#");
	for(;i<=sec && i<=41;i++)
		mvprintw(HEIGHT+7,MIDDLE+11-(i-19),"#");
	for(;i<=sec && i<=49;i++)
		mvprintw(HEIGHT+7-(i-41),MIDDLE-11,"#");
	for(;i<=sec;i++)
		mvprintw(HEIGHT-1,MIDDLE-11+(i-49),"#");
}

int main()
{
	time_t tempsBrute;
	struct tm tempsLisible;

	initscr();
        noecho();
        keypad(stdscr, TRUE);
        curs_set(0);
        start_color();
        nodelay(stdscr, TRUE);

        /*Mise en place des paires de couleurs*/
        init_pair(1, COLOR_WHITE, COLOR_BLACK); /* Fond */
        init_pair(2, COLOR_YELLOW, COLOR_BLACK); /* Sélectionné */

	while(getch() != 'q')
	{
		time(&tempsBrute);
		gmtime_r(&tempsBrute, &tempsLisible);
		tempsLisible.tm_hour += 2 + (tempsLisible.tm_isdst != -1)*tempsLisible.tm_isdst;
		clear(); /* TODO: enlever a terme le clear */

		mvprintw(1,1,"#%d#%d#",A_BOLD, A_NORMAL);
		attron(A_BOLD);
		attron(COLOR_PAIR(2));
		afficher(tempsLisible.tm_hour/10,-10);
		afficher(tempsLisible.tm_hour%10,-5);
		afficher(tempsLisible.tm_min/10,+2);
		afficher(tempsLisible.tm_min%10,+7);

                mvprintw(HEIGHT+2,MIDDLE,"#");
                mvprintw(HEIGHT+4,MIDDLE,"#");

                attroff(A_BOLD);

		afficherSec(tempsLisible.tm_sec);

		attroff(COLOR_PAIR(2));

		refresh();
		sleep(1);
	}

	endwin();

	return 0;
}
