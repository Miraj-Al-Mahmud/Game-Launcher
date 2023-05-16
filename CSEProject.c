

#include "essentials.h"
#include "functions.h"
#include "splash.h"
#include "game_screen.h"
#include "randomizer.h"
#include "tic_tac_toe.h"

// small caps = 97 - 122
// capital = 65 - 90



void screenResolution(int col, int r)
{
    char row2[] = {r, '\0'};
    char column2[] = {col, '\0'};
    char str1[] = "MODE ";
    strcat(str1, column2);
    strcat(str1, ",");
    strcat(str1, row2);
    system(str1);
}

void animations(int key)
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
    animations(0);
    c;
    nl;
    files_directory();  // retrieve the credentials
	int user = login();
	(user == 0) ? log_in(0) : log_in(1);
    
    
    int master_flag = 0;
    int last_played = -1;
    while (master_flag==0)
    {
        fflush(stdout);
        int cho = controller();
        // attendance for another variable for game palyed
        if (cho==1)
        {
            // or tic tac toe
            while(1)
            {
                wheel++;
                main_game_controller(wheel);
                c;nl;nl;nl;
                last_played = 1;
                hall_of_fame(last_played);
                nl;nl;nl;
                int v = liked();
                if (v==1) {c;break;}
            
            }
            //main_game_controller();
        }
        else if (cho==2)
        {   // for number guessing game
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
