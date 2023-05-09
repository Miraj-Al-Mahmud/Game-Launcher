
// Libraries
#include "essentials.h"


void fileManager(char userInput[]) // process the users pass, scores of games
{
    // Directory of the file
    char textFile[] = ".txt"; // extension for textfile
    char usersFolder[] = "users/"; // addition to folder
    strcat(userInput,textFile); // adding text
    strcat(usersFolder, userInput); // adding folder
    // printf("%s",usersFolder);

    FILE *fptr = fopen(usersFolder,"r");
    //fgets(pass, 100, fptr);
    //fscanf(fptr,"%s", pass);

    char pass[20];
	int i = 0;
	while (fgets(pass, 20, fptr) != NULL)
    {
        // printf("%s",pass);
        strcpy(scores[i],pass);
        i++;
    }
    // printf("%d",strlen(pass));
    validPass(userInput);
    fclose(fptr);

}

int validID(char userInput[]) // search in the database
{
    int flag = 0;
    for(int j=0; j<=userLimit; j++)
    {
        if(flag == 0)
        {
            if(strcmp(IDS[j],userInput) == 0 && strlen(IDS[j]) == strlen(userInput))
            {
                flag = 1;
                break;
            }
        }
    }
    strcpy(identity, userInput); // copy the username for later use
    return flag;

}

const char* incognito() // for user privacy
{
    static char temp[20] = ""; // static for global variable
    while(1)
    {
        char pr = getch();
        char str[2] = {pr,'\0'};
        if ( pr == '\r' || pr == '\n') break;
        else
        {
            if (pr!='\b') { strcat(temp,str); p("#");} // try not to go into this shit
            else p("\r");
        }

    }
    //nl;printf("%s",temp);
    //return temp[20];
    return temp;
}


int validPass(char userInput[])
{
    space;cyan;
    p("Enter your password >>> ");
    //char userPass[20];
    const char *userPass = incognito();
    // scanf("%s",userPass); // incognito

    int length = strlen(scores[0]);
    scores[0][length-1] = '\0';
    if(strcmp(userPass,scores[0])==0) { nl; green; space; p("Password Matched !!!"); s(2); welcome();}
    else { nl; space; red; p("Wrong Password !!!");}
    // printf("%s %s -",scores[0], userPass);
}

void log_in(void) // login screen
{
    c;nl;nl;nl;space;
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


int same(char a[]) // check if the username already exists
{
    for(int i=0; i<=userLimit; i++)
    {
        if(strcmp(a,IDS[i])==0)
        {
            // matched
            p("Account already exists !!!");
            return 1;
        }
    }
    return 0;
}



void registration() // user registation screen
{
    nl;nl;nl;space;
    p("USER REGISTRATION");
    char credentials[3][20];
    nl;
    p("Enter your ID >>> ");
    scanf("%s",credentials[0]);

    // create for already exists !!!
    int res = same(credentials[0]); // send it to the function
    if (res==1) registration();
    else p("Account Available");

    p("Enter password [ At least 8 characters long ] >>> ");
    scanf("%s",credentials[1]);

    char u[] = "users/";
    char t[] = ".txt";
    strcat(u,credentials[0]);
    strcat(u,t); // ready for creating by this name

    FILE *regi = fopen(u,"w");
    fprintf(regi,"%s\n0\n0\n0\n0\n0\n0\n0\n0\n0\n0",credentials[1]); // default data values later can be changed
    fclose(regi);
    nl;
    p("Account created successfully !!!");
}



