
#include "essentials.h"

#define upper_limit 10


int main_number = -1;
int tempArray[10] = {0}; // for storing this game's specific scores 1 - 5


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


void gather_previous_scores() // gather scores from the file
{ // atoi -> string to number
	for(int i=1; i<=10; i++)
	{
		int temp_score = atoi(scores[i]);
		tempArray[i-1] = temp_score;
	}
}


void ass()
{
	char file_name_final[] = "users/";
    strcat(file_name_final,identity);
    strcat(file_name_final,".txt");
    FILE *sc = fopen(file_name_final,"w");
    fprintf(sc,"%s\n",scores[0]);
    for(int i=0; i<10; i++) {fprintf(sc, "%d\n", tempArray[i]);}
    fclose(sc);
	
}




void game2()
{
	int flag = 0;
	rng();
	int chances = 5;	
	while (chances>0)
	{
		nl;
		printf("Guess the number between 1 - %d ( %d/5 chances remaining ) >>> ",upper_limit,chances);
		int num; scanf("%d",&num);
		nl;
		if (num==main_number) {green; strcenter("Matched. Your'e really GENIUS !!!"); flag = 1; break;}
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
	// format > total played - won - lost - percentage of winning - least number of moves - 5 rules
	// for(int i=0; i<15; i++) printf("%s",scores[i]);
	// last 5 ones of scores
	gather_previous_scores();
	tempArray[5]++; // total played
	if (chances>=0 && flag==1) tempArray[6]++; // for winning
	else tempArray[7]++; // for losing
	tempArray[8] = (tempArray[6]*100) / tempArray[5];
	tempArray[9] = 5-chances+1; // no of moves
	
	//for(int i=5; i<10; i++) printf("%d",tempArray[i]);
	
	
	ass();
	
	
	
	
}



