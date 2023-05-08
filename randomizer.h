
#include "essentials.h"
#define upper_limit 10


int main_number = -1;


void rng()
{
	srand(time(NULL));
	int x = (rand() % upper_limit) + 1;  // + 1 for ignoring the 0
	main_number = x;
}

void greetings(int chances)
{
	if(chances >= 3) strcenter("Try Again !!!");
	else if (chances == 2) strcenter("Last chance ... GOOD LUCK!!!"); 
	else if (chances == 1) strcenter("Better Luck next time!!!");
}


void game2()
{
	rng();
	int chances = 5;	
	while (chances>0)
	{
		nl;
		printf("Guess the number between 1 - %d ( %d/5 chances remaining ) >>> ",upper_limit,chances);
		int num; scanf("%d",&num);
		nl;
		if (num==main_number) {green; strcenter("Matched. Your'e really GENIUS !!!"); break;}
		else 
		{
			if(abs(num-main_number)<=2) yellow;
			else if(abs(num-main_number)>2 && abs(num-main_number)<5) cyan;
			else red;
			greetings(chances);
			chances--;
		}
		
	}
	
	// add to file immediately
	// format > total played - won - lost - percentage
}