
// Libraries
#include "essentials.h"
static char temp[20] = "";
int total_registered_users = 0;
int found_index = -1;
static int wheel = 0; // how many times played the game

/*
void last_check() // remove the garbage value one last time
{
    for(int i=0;i<=total_registered_users;i++)
    {
        for(int j=0; j < strlen(IDS[i]); j++)
        {
            if(!isdigit(IDS[i][j]) && !isalpha(IDS[i][j])) {IDS[i][j]='\0'; break;}
        }
    }
}

void fileManager(char userInput[]) // process the users pass, scores of games // GENIUS !!!!
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
*/

int validID(char userInput[]) // search in the database
{
    //last_check();
    int flag = 0;
    for(int j=0; j<=total_registered_users; j++)
    {
        if(flag == 0)
        {
            if(strcmp(version2[j][0],userInput) == 0 && strlen(version2[j][0]) == strlen(userInput))
            {
                flag = 1;
                strcpy(scores[0],version2[j][1]);
                found_index = j;
                break;
            }
        }
    }
    strcpy(identity, userInput); // copy the username for later use
    return flag;

}

const char* incognito() // for user privacy
{
     // static for global variable
    
    strcpy(temp,"");
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
    //scores[0][length-1] = '\0';
    if(strcmp(userPass,scores[0])==0)
        {
            nl;
            green;
            strcenter("Password Matched !!!");
            s(2);
            welcome();
        }
    else { nl; space; red; p("Wrong Password !!!"); s(2); log_in();}
    // printf("%s %s -",scores[0], userPass);

}

void log_in(int trigger) // login screen
{
    system("MODE 95,18");
    c;nl;nl;nl;space;
    p("Enter the ID >>> ");
    char userInput[nameLength];
    scanf("%s",userInput);
    nl;
    int flag = validID(userInput);
    if (flag==1) // match found
    {
        if (trigger==1)
        {
            strcenter("Account already exists !!!");
            log_in(1);
        }
        else validPass(userInput);
    }
    else
    {
        if(trigger==1)
        {
            registration(userInput);
        }
        else {strcenter("Not found"); printf("%s\n%s\n%s\n",IDS[0],IDS[1],IDS[2]);system("pause");log_in(0);}
    }

}

void files_directory(void) // extract the ids from the created files
{
    /*
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
            if (strlen(dir->d_name) >= minimum_length)
            {
                while(dir->d_name[start]!='.') // exttrat the ids till '.txt'
                {
                    temp[start] = dir->d_name[start];
                    start++;
                }
            }
            strcpy(names[nameID],temp);
            printf("%s\n",names[nameID]);
            strcpy(names[nameID+1],"");
            nameID++;
        }
        closedir(d);
    }
    */

    // new iteration - only store the creadentials in one file
    FILE *fptr = fopen("docs.txt", "r");
    char pass[nameLength];
    int i = 0;
    while (fgets(pass, nameLength, fptr) != NULL)
    {
        // seperate the commas
        char *pt;
        pt = strtok (pass,",");
        int j=0;
        while (pt != NULL) {
            if(isalpha(pt[0]) || isdigit(pt[0])) strcpy(version2[i][j],pt); // copy the data to new array, this is the complete array
            //printf("%s\n", version2[i][j]);
            pt = strtok (NULL, ",");
            j++;
        }
        
        i++;
        total_registered_users++;
    }
    
    
    
    
    
    
    
    
    
    /*
    int tempArray = 0;
    for(int i=0; i<=userLimit; i++)
    {
        if(strlen(names[i])>=minimum_length)
        {
            char cleaner_array[nameLength];
            for(int k=0; k<nameLength; k++)
            {
                if(isalpha(names[i][k]) || isdigit(names[i][k])) cleaner_array[k] = names[i][k];
                else break;
            }
            strcpy(IDS[tempArray],cleaner_array);
            //printf("%s\n",IDS[tempArray]);
            tempArray++;
        }
    }
    total_registered_users = tempArray;
    //printf("%d",total_registered_users);
    system("pause");
    */
    
}

/*
int same(char a[]) // check if the username already exists
{
    leaderboard();
    int flag = 0;
    for(int i=0; i<=total_registered_users; i++)
    {
        if(strcmp(a,IDS[i])==0)
        {
            // matched
            p("Account already exists !!!");
            flag = 1;
            break;
        }
        printf("%s\n", world_credentials[i][0]);
    }
    return flag;
}
*/



void registration(char userInput[]) // user registation screen
{
    c;
    char tempPass[2][nameLength];
    p("Enter password [ At least 8 characters long ] >>> ");
    scanf("%s",tempPass[0]);
    strcpy(tempPass[1],tempPass[0]);


    FILE *regi = fopen("docs.txt","a");
    fprintf(regi,"%s,%s,0,0,0,0,10,0,0,0,0,10\n",userInput,tempPass[1]); // default data values later can be changed
    fclose(regi);
    nl;
    strcenter("Account created successfully !!!");
    space; hold;
    fflush(stdout);
    files_directory();
    log_in(0); // 0 for log in 1 for registration
}



