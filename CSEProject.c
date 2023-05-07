

#include "essentials.h"
#include "functions.h"
#include "splash.h"

// small caps = 97 - 122
// capital = 65 - 90

// void logo();
// void dots();
// int login();

int main(void)
{
    system("MODE 100,35"); // column - row


    //nl;
    //logo(); // the gamepad logo
    //title(); // name of the project
    //credits(); // my damn name
    //nl;

    files_directory();  // retrieve the credentials

	//int user = login();
	//(user == 0) ? log_in() : registration();

    // all OK !!!

    //clear;

    log_in();
    //welcome();




	return 0;

}
