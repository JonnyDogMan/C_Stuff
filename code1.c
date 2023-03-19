#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
	printf("Input 3 numbers\n");
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);

	if(b % a == 0 && c % a == 0)
	{
		printf("The second 2 numbers are divisble by the first one");
	}
	else
	{
		printf("The second 2 numbers are not divisble by the first one");
	}
	if(b > a && c > b)
	{
		printf(" and the numbers are in increasing order");
		
	}
	else
	{
		printf(" and the numbers are not in increasing order");
	}
   return(0);
}
