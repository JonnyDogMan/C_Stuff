#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#define DELAY 30000


int main(void) {

	initscr();
	curs_set(FALSE); 
	noecho();

	int x = 0;
	int y = 10;
	
	int maxY = 0;
	int maxX = 0;
	
	getmaxyx(stdscr,maxY,maxX);
	
	y = maxY;
	
	int direction = 1;
	
	while(1)
	{
		clear();
		mvprintw(y,x,"o");
		refresh();
		
		usleep(DELAY);
		x += direction;
		
		if(x == maxX || x == 0)
		{
			direction *= -1;
		}

		
	}
	

	
	endwin();

	return 0;

}

