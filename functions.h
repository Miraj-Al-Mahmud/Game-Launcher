
// Libraries
#include "essentials.h"
#define nameLength 12
#define userLimit 50
char names[userLimit][nameLength]; // array of all names
char IDS[userLimit][nameLength];
char userPassword[20];
char scores[5][20];

void fileManager(char userInput[]) // process the users pass, scores of games
{
    // Directory of the file
    char textFile[] = ".txt"; // extension for textfile
    char usersFolder[] = "users/"; // addition to folder
    strcat(userInput,textFile); // adding text
    strcat(usersFolder, userInput); // adding folder
    printf("%s",usersFolder);

    FILE *fptr = fopen(usersFolder,"r");
    //fgets(pass, 100, fptr);
    //fscanf(fptr,"%s", pass);

    char pass[20];
	int i = 0;
	while (fgets(pass, 20, fptr) != NULL)
    {
        printf("%s",pass);
        strcpy(scores[i],pass);
        i++;
    }
    // printf("%d",strlen(pass));
    validPass(userInput);

}

int validID(char userInput[]) // search in the database
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

int validPass(char userInput[])
{
    p("Enter your password >>> ");
    char userPass[20];
    scanf("%s",userPass);
    int length = strlen(scores[0]);
    scores[0][length-1] = '\0';
    if(strcmp(userPass,scores[0])==0) p("matched");
    else p("Not matched");
    printf("%s %s -",scores[0], userPass);
}

void log_in(void)
{
    p("Enter the ID >>> ");
    char userInput[nameLength];
    scanf("%s",userInput);
    int flag = validID(userInput);
    if (flag) return fileManager(userInput);
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
