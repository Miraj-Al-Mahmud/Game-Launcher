
#include "essentials.h"
#define upper_limit 10

int main_number = -1;
static int tempArray[10] = {0}; // for storing this game's specific scores 1 - 10

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
	for(int i=2; i<=11; i++)
	{
		int temp_score = atoi(version2[found_index][i]);
		tempArray[i-2] = temp_score;
	}
	
}




void ass()
{
	if (wheel==1)
	{
		for (int i = 0; i < total_registered_users; ++i) version2[i][11][strlen(version2[i][11])-1] = '\0';
	}
	

	//system("MODE 200,200");
	for (int i = 0; i < total_registered_users; ++i)
	{
		for(int j=0; j<12; j++)	printf("%s---", version2[i][j]);
		nl;
	}
	
	
	
	
	//strcpy(xxx[0],version2[0][0]);
	
	
	
	
	/*
	for (int i = 0; i <= 9; ++i)
	{
		char tes[][nameLength] = {tempArray[i],'\0'};// convert to string
		strcpy(version2[found_index][i+2], tes);
		//strcpy(version3[0][i], tes);
		printf("%s ",tes);
	}
	
	
	
		
	*/
	
		
    FILE *sc = fopen("docs.txt","w");
    for(int i=0; i<total_registered_users; i++)
    {
    	if (i!=found_index)
    	{
    	for(int j=0; j<12; j++)
    	{
    		
    			if(j!=11) fprintf(sc, "%s,", version2[i][j]);
    		    else fprintf(sc, "%s\n", version2[i][j]);
    	}
    	}
    	
    }
    //fclose(sc);
    //FILE *sc = fopen("docs.txt","a");
    fprintf(sc, "%s,", version2[found_index][0]); // username
    fprintf(sc, "%s,", version2[found_index][1]); // password
    for (int i = 0; i <= 9; ++i)
    {
    	if(i!=9) fprintf(sc,"%d,",tempArray[i]);
    	else fprintf(sc,"%d\n",tempArray[i]);
    }
    fclose(sc);
	
}


void stats(int start) // user statistics
{
	nl;
	printf("Total played = %d times", tempArray[start]); nl; start++;
	printf("Won = %d times", tempArray[start]); nl; start++;
	printf("Lost = %d times", tempArray[start]); nl; start++;
	printf("Win Loss ratio = %d%%",tempArray[start]); nl; start++;
	printf("Personal best = %d",tempArray[start]); nl;
}


int liked()
{
	int ver = 0;
	strcenter("Play again ??? 'Y' / 'N' >>> ");
	char aa = getch();
	nl;
	if (aa=='Y' || aa=='y') strcenter("YES");
	else if (aa=='N' || aa=='n') { ver = 1; strcenter("NO"); }
	return ver;
}




void game2(int wheel)
{
	system("MODE 110,30");
	int flag = 0;
	rng();
	if (wheel==1) gather_previous_scores(); // only for the first time
	//gather_previous_scores();
	stats(5);
	int chances = 5;	
	while (chances>0)
	{
		nl;
		printf("Guess the number between 1 - %d ( %d/5 chances remaining ) >>> ",upper_limit,chances);
		int num; scanf("%d",&num);
		nl;
		if (num==main_number)
		{
			green;
			strcenter("Matched. Your'e really GENIUS !!!");
			flag = 1;
			break;
		}
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
	
	tempArray[5]++; // total played
	if (chances>=0 && flag==1) tempArray[6]++; // for winning
	else tempArray[7]++; // for losing
	tempArray[8] = (tempArray[6]*100) / tempArray[5];
	if(6-chances<tempArray[9]) {tempArray[9] = 6-chances;} // no of moves personal best
	
	//for(int i=5; i<10; i++) printf("%d",tempArray[i]);
	

	
	
	ass();
	
	
	
}






