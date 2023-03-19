#include <ncurses.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define DELAY 30000

int bulletY = -1;


int fireBullet(int x, int y)
{
	mvprintw(y,x, ".");
	
	refresh();
	
	bulletY = y;
	
	return x;
}
int main()
{
	//Enemy
	int enemyX = 1;
	int enemyY = 2;
	int maxEnemyY = 0;
	int maxEnemyX = 0;
	int direction = 1;
	
	getmaxyx(stdscr,maxEnemyY,maxEnemyX);
	
	maxEnemyX = 158;
	
	//Bullet
	char str[80];
	int row, col;
	int bulletX;
	int x = 0;
	int y = 20;
	
	time_t start, end;
	double secondsPassed;
	
	initscr();
	cbreak();
	nodelay(stdscr, TRUE);
	noecho();
	mvprintw(y,x, "w");
	curs_set(FALSE);
	
	time(&start);
	
	getmaxyx(stdscr, row, col);
	while(1)
	{
		time(&end);
		secondsPassed = difftime(end,start);
		usleep(DELAY);
		
		mvprintw(enemyY, enemyX, " ");
		getstr(str);
		
		if(secondsPassed >= 1)
		{
			enemyX += direction;
			time(&start);
			
		}
		
		if(enemyX == maxEnemyX || enemyX == 0)
		{
			direction *= -1;
		}
		
		if(enemyX == bulletX && enemyY == bulletY)
		{
			mvprintw(enemyY, enemyX, " ");
			enemyY = -1;
		}
		
		if(bulletY != -1)
		{
			if(bulletY == 0)
			{
				mvprintw(bulletY, bulletX, " ");
				bulletY -= 1;
			}
			else
			{
				mvprintw(bulletY,bulletX, " ");
		
				bulletY -= 1;
		
				mvprintw(bulletY,bulletX, ".");
			}
		}
		if(str[0] == 'd')
		{
			mvprintw(y,x, " ");
			
			x +=1;
			
			mvprintw(y,x, "w");
		}
		if(str[0] == 'a')
		{
			mvprintw(y,x, " ");
			
			x -=1;
			
			mvprintw(y,x, "w");
		}
		if(str[0] == ' ' && bulletY == -1)
		{
			bulletX = fireBullet(x,y -1);
		}

		mvprintw(enemyY,enemyX,"o");
		refresh();
	}	
	
	endwin();
	
	return 0;
}
