
// Actual IN GAME screen

#include "essentials.h"

static int a = 0;

void gameTitle()
{
	system("MODE 110,20");
	nl;nl;nl;
	strcenter("= C H O O S E    Y O U R    G A M E =");
	nl;nl;nl;
}

void first_screen() // default & first
{
	gameTitle();
	cyan;	
	strcenter(">>>          1. TIC TAC TOE          <<<"); 
	strcenter("2. NUMBER GUESSING GAME"); 
	strcenter("3. EXIT");
	nl;
	strcenter("You selected TIC TAC TOE. Press ENTER to continue");	
}

void second_screen() // second
{
	gameTitle();
	green;	
	strcenter("1. TIC TAC TOE"); 
	strcenter(">>>     2. NUMBER GUESSING GAME     <<<");  // 5
	strcenter("3. EXIT");	
	nl;
	strcenter("You selected NUMBER GUESSING GAME. Press ENTER to continue");
}


void third_screen() // third
{
	gameTitle();
	red;
	strcenter("1. TIC TAC TOE"); 
	strcenter("2. NUMBER GUESSING GAME"); 
	strcenter(">>>             3. EXIT             <<<");	 // 13
	nl;
	strcenter("You want to leave the game. Press ENTER to continue");
}


int controller() // navigate by user input in real time
{
	char inp;
	first_screen();
	while(1)
	{
		inp = getch();
		if (inp=='1') {a = 1; c; first_screen();}
		else if (inp=='2') {a =2 ;c; second_screen();}
		else if (inp=='3') {a = 3; c; third_screen();}
		else if (inp=='\n' || inp=='\r') {nl; strcenter("Please wait ..."); s(2); break;}
	}
	if (a==1) return 1;
	else if (a==2) return 2;
	else if (a==3) return 3;

}
