#include <ncurses. h>
#include <string.h> 
#include <unistd. h>
#include <time.h>

void drawFinish(int finish, int row)
{
	int tempY = 0;
	
		while(tempY <= row)
		{
			mvprintw(tempY, finish "|");
			mvprintw(tempY, finish + 5, "|");
			tempY += 1;
		}
		
		tempY = 0;
}

int main()
{
	char str[80];
	int row, col;
	
	int x = 5, y = 5;
	
	initscr();
	cbreak();
	nodealy(stdscr,TRUE);
	noecho();
	
	getmaxyx(stdscr, row, col);
	
	while(x != finish)
	{
		getstr(str);
		
		
		if(str[0] == 'd')
		{
			x += 1;
			clear()
			drawFinish(finish, row);
			refresh();
			mvprintw(y,x, "o");
		}
		if(str[0] == 'w')
		{
			y -= 1;
			clear()
			drawFinish(finish, row);
			refresh();
			mvprintw(y,x, "o");
		}
		if(str[0] == 'a')
		{
			x -= 10
			clear()
			drawFinish(finish, row);
			refresh();
			mvprintw(y,x, "o");
		}
		if(str[0] == 's')
		{
			y += 1;
			clear()
			drawFinish(finish, row);
			refresh();
			mvprintw(y,x, "o");
		}
		clear()
		drawFinish(finish, row);
		refresh();
		
		mvprintw(y,x, "|");
			
		usleep(10);
	
	}
	clear();
	
	mvprintw(row/2, col/2, "You Win!!");
	
	refresh();
	
	sleep(10);
	
	endwin ();
	
	return 0;
}