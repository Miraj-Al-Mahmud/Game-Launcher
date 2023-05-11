

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


int main(void)
{
    
    c;
    //screenResolution(100,45); // column - row
    system("MODE 90,45");
    nl;
    logo(); // the gamepad logo
    title(); // name of the project
    credits(); // my damn name
    nl;
    files_directory();  // retrieve the credentials
	int user = login();
	(user == 0) ? log_in() : registration();
    c;
    
    
    int master_flag = 0;
    while (master_flag==0)
    {
        int cho = controller();
        int wheel = 0; // how many times played the game
        if (cho==1)
        {
            // or tic tac toe
            while(1)
            {
                c;
                wheel++;
                main_game_controller(wheel);
                int v = liked();
                if (v==1) {c;break;}
            }
            //main_game_controller();
        }
        else if (cho==2)
        {   // for number guessing game
            while(1)
            {
                c;
                wheel++;
                game2(wheel);
                int v = liked();
                if (v==1) {c;break;}
            }
        }
        else if (cho==3) {break;}
    }

    
    
    //files_directory();
    //leaderboard();    
    //assembler();    

 


	return 0;

}
