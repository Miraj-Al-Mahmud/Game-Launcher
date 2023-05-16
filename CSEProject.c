
// This is the main file of the project

#include "essentials.h"
#include "functions.h"
#include "splash.h"
#include "game_screen.h"
#include "randomizer.h"
#include "tic_tac_toe.h"

void screenResolution(int col, int r) // determines the screen size of different sessions
{
    char row2[] = {r, '\0'};
    char column2[] = {col, '\0'};
    char str1[] = "MODE ";
    strcat(str1, column2);
    strcat(str1, ",");
    strcat(str1, row2); // combine all the strings to form a command
    system(str1); // execute the command
}

void animations(int key) // pre animated screen toggler
{
    if(key==1)
    {
        //screenResolution(100,45); // column - row
        system("MODE 90,45");
        nl;
        logo(); // the gamepad logo
        title(); // name of the project
        credits(); // my damn name
    }
}

int main(void)
{
    c;
    animations(true); // enable - disable animation
    nl;
    files_directory();  // retrieve the credentials
	int user = login();
	(user == 0) ? log_in(0) : log_in(1); // login - registration screen
    // next phase of the game, the main part
    int master_flag = 0;
    int last_played = -1; // last played game
    while (master_flag==0)
    {
        fflush(stdout); // erase the memory [ Not sure if it works !!! ]
        int cho = controller();
        if (cho==1) // for tic tac toe
        {
            while(1)
            {
                wheel++;
                main_game_controller(wheel); // screen for A.I. and user
                c;nl;nl;nl;
                last_played = 1;
                hall_of_fame(last_played); // data collect
                nl;nl;nl;
                int v = liked(); // play again
                if (v==1) {c;break;}
            
            }
        }
        else if (cho==2) // for number guessing game
        {   
            while(1)
            {
                wheel++;
                game2(wheel);
                c;nl;nl;nl;
                last_played = 2;
                hall_of_fame(last_played);
                nl;nl;nl;
                int v = liked();
                if (v==1) {c;break;}
            }
        }
        else if (cho==3) {break;}
    }
	return 0;
}
