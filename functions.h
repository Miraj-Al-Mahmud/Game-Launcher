
// Libraries
#include "essentials.h"
#define nameLength 12
#define userLimit 50
char names[userLimit][nameLength]; // array of all names
char IDS[userLimit][nameLength];
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

int valid(char userInput[]) // search in the database
{
    int flag = 0;
    for(int j=0; j<=userLimit; j++)
    {
        if(flag == 0)
        {
            if(strcmp(IDS[j],userInput) == 1 && strlen(IDS[j]) == strlen(userInput))
            {
                flag = 1;
                break;
            }
        }
    }
    return flag;
}

void log_in(void)
{
    p("Enter the ID >>> ");
    char userInput[nameLength];
    scanf("%s",userInput);
    int flag = valid(userInput);
    if (flag) p("Found");
    else p("Not found");

}

void files_directory(void) // extract the ids from the created files
{
    #include <dirent.h>
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
            if (strlen(dir->d_name) > 9)
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

    int tempArray = 0;
    for(int i=0; i<=userLimit; i++)
    {
        if(strlen(names[i])>=8)
        {
            strcpy(IDS[tempArray],names[i]);
            tempArray++;
        }
    }
}


void registration()
{

}
