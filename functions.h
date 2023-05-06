
// Libraries
#include "essentials.h"

// display dots animation
void dots(void) { for (int i = 0; i < 5; ++i) { s(1); printf(" .");} }

// login or registration
int login(void)
{
	printf("\t\t\tType 'L' to Login and 'R' to Resister >>> ");
	char user = getch();
	if (user == 'L' || user == 'l')
	{
		green;
		printf("L");
		nl; printf("\t\t\t\t\tYou pressed 'L'");
		s(2);
		nl; printf("\t\t\tRedirecting to the LOG IN screen");
		dots();
		return 0;
	}
	else if (user == 'R' || user == 'r')
	{
		cyan;
		printf("R");
		nl; printf("\t\t\t\t\tYou pressed 'R'");
		s(2);
		nl; printf("\t\t\tRedirecting to the REGISTRATION screen");
		dots();
		return 1;
	}
	else
	{
		red;
		nl; printf("\rYou pressed the wrong key. Please follow the instructions");
		nl; system("pause"); system("cls");
		login();
	}


}

// Students info
struct info
{
    int ID;
    char name[30];
    int pin;
    long mobile;
};

void fileManager(void)
{
    // Directory of the file
    FILE *fptr = fopen("users.txt","r");

    struct info allNames[100];

	char names[30];
	// fgets(names, 100, fptr);
	// fscanf(fptr, "%s", names);
	int i = 0;
	while (fgets(names, 30, fptr) != NULL)
    {
        // printf("%s",names);
        printf("%s",names);
        strcpy(allNames[i].name,names);
        i++;
    }

    for(int j =0; j<100; ++j)
    {
        printf(allNames[j].name);
    }


	// puts(names);
}

void log_in(void)
{

}

void files_directory(void)
{
    #include <dirent.h>
    int nameLength = 10;
    int names[50][nameLength]; // array of all names
    int nameID = 0;
    DIR *d;
    struct dirent *dir;
    d = opendir("./users");
    if (d)
    {
        while ((dir = readdir(d)) != NULL)
        {
            //printf("%s\n", dir->d_name);
            char temp[nameLength];
            int start = 0;
            if (strlen(dir->d_name) > 3)
            {
                while(dir->d_name[start]!='.') // exttrat the ids till '.txt'
                {
                    temp[start] = dir->d_name[start];
                    start++;
                }
            }
            strcpy(names[nameID],temp);
            nameID++;
        }
        closedir(d);
    }
    for(int i=0;i<3;i++) printf("%s\n",names[i]);
}


void registration()
{

}
