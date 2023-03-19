#include <stdlib.h>
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

int bulletY; 


int fireBullet(int x, int y) 
{

	mvprintw(y, x, ".");
	
	refresh();
	
	bulletY = y -5;
	
	return x;
}

int main()
{
	time_t start, end, enemyStart, enemyEnd;
	double secondsPassed;
	
	int row, col;
	int x = 0;
	int y = 20;
	
	char str[80];
	
	noecho();

	int enemyX = 7;
	int enemyY = 4;
	
	int maxEnemyY = 0;
	int maxEnemyX = 0;
	
	getmaxyx(stdscr,maxEnemyY,maxEnemyX);
	
	int direction = 1;
	
	initscr();
	row = maxEnemyY;
	col = maxEnemyX;
	cbreak();
	nodelay(stdscr, TRUE);
	noecho();
	curs_set(0);
	
	mvprintw(y,x,"w");
	
	int bulletX;
	
	bulletY = -1;
	
	time(&start);
	time(&enemyStart);
	
	while(1)
	{
		refresh();
		mvprintw(enemyY,enemyX, " ");
		
		getstr(str);
		
		time(&end);
		time(&enemyEnd);
		
		mvprintw(0,0, " ");
		
		secondsPassed = difftime(end,start);
		
		mvprintw(enemyY, enemyX, "Q");
		if(difftime(enemyEnd, enemyStart) >= 1.0)
		{
			mvprintw(enemyY, enemyX, " ");
			enemyX += direction;
			time(&enemyStart);
		}
	
		if(enemyX == maxEnemyX || enemyX == 0)
		{
			direction *= -1;
		}
		
		if(bulletY != -1 && secondsPassed >= 1)
		{
		
			if(bulletY == 0)
			{
				mvprintw(bulletY,bulletX, " ");
				bulletY = -1;
			}
			
			else 
			{
				mvprintw(bulletY,bulletX, " ");
				
				bulletY -= 1;
				
				mvprintw(bulletY,bulletX, ".");
			}
			
			time(&start);
		}
		
	
		if(str[0] == 'd')
		{
			mvprintw(y,x, " ");
		
			x += 1;
		
			mvprintw(y,x,"w");
		}
			if(str[0] == 'a')
		{
			mvprintw(y,x, " ");
		
			x -= 1;
		
			mvprintw(y,x,"w");
		}
		if(str[0] == ' ' && bulletY == -1)
		{
			bulletX = fireBullet(x,y);
			time(&start);
		}
	}
	
	endwin();

	return 0;

}

