

#include "essentials.h"
#include "functions.h"
#include "splash.h"
#include "game_screen.h"
#include "randomizer.h"

// small caps = 97 - 122
// capital = 65 - 90

void screenResolution()
{
    char row2[] = {row, '\0'};
    char column2[] = {column, '\0'};
    char str1[] = "MODE ";
    strcat(str1, column2);
    strcat(str1, ",");
    strcat(str1, row2);
    system(str1);
}

int main(void)
{
    
    screenResolution(); // column - row


    //nl;
    //logo(); // the gamepad logo
    //title(); // name of the project
    //credits(); // my damn name
    //nl;

    files_directory();  // retrieve the credentials

	int user = login();
	(user == 0) ? log_in() : registration();

    // all OK !!!

    //clear;
    //controller();
    //log_in();
    
    //welcome();
    
    
    game2();




	return 0;

}
