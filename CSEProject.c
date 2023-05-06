

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
    system("MODE 100,40"); // column - row
    nl;
    //logo(); // the gamepad logo
    //title(); // name of the project
    //credits(); // my damn name
    nl;

	// fileManager();

    // testing
    files_directory();
	int user = login();
	(user == 0) ? log_in() : registration();



	return 0;

}
