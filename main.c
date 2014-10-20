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

void modele1(int h, int m, int s, int c1, int c2)
{
	if(c1%2 == 1)
		attron(A_BOLD);
	else
		attroff(A_BOLD);
	attron(COLOR_PAIR(1+c1-(c1%2)));

	afficher(h/10,-10);
	afficher(h%10,-5);
	afficher(m/10,+2);
	afficher(m%10,+7);

	mvprintw(HEIGHT+2,MIDDLE,"#");
	mvprintw(HEIGHT+4,MIDDLE,"#");

	if(c2%2 == 1)
		attron(A_BOLD);
	else
		attroff(A_BOLD);
	attron(COLOR_PAIR(1+c2-(c2%2)));

	afficherSec(s);
}

void modele2(int h, int m, int s, int c1, int c2)
{
	afficher(8,-10);
        afficher(8,-5);
        afficher(8,+2);
        afficher(8,+7);
}

int main(int argc, char **argv)
{
	time_t tempsBrute;
	struct tm tempsLisible;
	/* Variables d'usage */
	int buf, i;
	/* Variables de stoquage des paramètres */
	int c1 = 9, c2 = 10;
	void (*modele)(int, int, int, int, int) = modele1;

	/* Initialisation et paramétrage de ncurses */
	initscr();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	start_color();
	nodelay(stdscr, TRUE);

	/*Mise en place des paires de couleurs*/
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(7, COLOR_BLUE, COLOR_BLACK);
	init_pair(9, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_GREEN, COLOR_BLACK);
	init_pair(13, COLOR_RED, COLOR_BLACK);

	/* Gestion des paramètres */
	for(i=1;i<argc;i++)
	{
		/* Si le paramètre est "-c1" */
		if(strcmp(argv[i],"-c1") == 0 && i+1<argc)
		{
			i++;
			buf = atoi(argv[i]);
			if(buf > 0 && buf < 15)
				c1 = buf;
		}
		else if(strcmp(argv[i],"-c2") == 0 && i+1<argc)
		{
			i++;
			buf = atoi(argv[i]);
			if(buf > 0 && buf < 15)
				c2 = buf;
		}
		else if(strcmp(argv[i], "-m") == 0 && i+1<argc)
		{
			i++;
			buf = atoi(argv[i]);
			if(buf > 0 && buf < 3)
			{
				switch(buf)
				{
					case 1:
						modele = modele1;
						break;
					case 2:
						modele = modele2;
						break;
				}
			}
		}
		else
			fprintf(stderr, "Error : Invalid Parameter \"%s\"\n", argv[i]);
	}

	/* On boucle tant que l'utilisateur n'appuye pas sur "q" */
	while(getch() != 'q')
	{
		/* Récupération du temps */
		time(&tempsBrute);
		/* Convertion en quelque chose de lisible */
		gmtime_r(&tempsBrute, &tempsLisible);
		/* Application éventuel de l'heure d'été */
		tempsLisible.tm_hour += 2 + (tempsLisible.tm_isdst != -1)*tempsLisible.tm_isdst;
		/* Effacage de l'écran pour éviter les problème lors de redimentionnements */
		clear(); /* TODO: enlever a terme le clear */

		/* Apel de la fonction d'affichage de l'heure en fonction du modèle choisi */
		(*modele)(tempsLisible.tm_hour, tempsLisible.tm_min, tempsLisible.tm_sec, c1, c2);

		refresh();
		sleep(1);
	}

	endwin();

	return 0;
}
