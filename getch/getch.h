/*
 * getch.h - a implementation of getch() and getche() 
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#ifndef GETCH_H
#define GETCH_H

static struct termios old, new;

void init_termios(int echo);
void reset_termios();

char getch_(int echo);
char getch();
char getche();

/* initialize new terminal i/o settings */
void init_termios(int echo) {
	tcgetattr(0, &old); /* grab old terminal i/o settings */
	new = old; /* make new settings same as old settings */
       	new.c_lflag &= ~ICANON; /* disable buffered i/o */
	new.c_lflag &= echo ? ECHO : ~ECHO; /* set echo mode */
	tcsetattr(0, TCSANOW, &new); /* use these new terminal i/o settings now */
}

/* restore old terminal i/o settings */
void reset_termios(void) {
	tcsetattr(0, TCSANOW, &old);
}

/* read 1 character - echo defines echo mode */
char getch_(int echo) {
	char ch;
	initTermios(echo);
	ch = getchar();
	resetTermios();
	return ch;
}

/* read 1 character without echo */
char getch() { return getch_(0); }

/* read 1 character with echo */
char getche() { return getch_(1); }

#endif
