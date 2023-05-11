
#include "essentials.h"
#define adjustment p("\n\n\n\n\n")
// options are ->
// Tic - Tac - Toe
// Number Guessing Game
// Exit

static int a = 0;

void gameTitle() {strcenter("=============== CHOOSE YOUR GAME ==============="); nl;nl;nl;}

void first_screen() // default
{
	adjustment;
	gameTitle();
	cyan;	
	strcenter(">>>          1. TIC TAC TOE          <<<"); 
	strcenter("2. NUMBER GUESSING GAME"); 
	strcenter("3. EXIT");
	nl;
	strcenter("You selected TIC TAC TOE. Press ENTER to continue");	
}

void second_screen() // default
{
	adjustment;
	gameTitle();
	green;	
	strcenter("1. TIC TAC TOE"); 
	strcenter(">>>     2. NUMBER GUESSING GAME     <<<");  // 5
	strcenter("3. EXIT");	
	nl;
	strcenter("You selected NUMBER GUESSING GAME. Press ENTER to continue");
}


void third_screen() // default
{
	adjustment;
	gameTitle();
	red;
	strcenter("1. TIC TAC TOE"); 
	strcenter("2. NUMBER GUESSING GAME"); 
	strcenter(">>>             3. EXIT             <<<");	 // 13
	nl;
	strcenter("You want to leave the game. Press ENTER to continue");
}



int controller()
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
	//printf("%c\n",inp); // did not understand
	if (a==1) return 1;
	else if (a==2) return 2;
	else if (a==3) return 3;

}
