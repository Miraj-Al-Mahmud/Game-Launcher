
// all the backend code
#include "essentials.h"

static char temp[20] = "";
int total_registered_users = 0; // total number of users present in file
int found_index = -1; // current user index at version2
static int wheel = 0; // how many times played the game


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
    return temp;
}


int validPass(char userInput[]) // password validator
{
    cyan;
    strcenter(" <<< Enter your password >>> ");
    space;p("\t");
    const char *userPass = incognito();

    int length = strlen(scores[0]);
    if(strcmp(userPass,scores[0])==0)
        {
            nl;
            green;
            nl;nl;
            strcenter("Password Matched !!!");
            s(2);
            welcome();
        }
    else { nl; space; red; p("Wrong Password !!!"); s(2); log_in();}

}

void log_in(int trigger) // login screen
{
    system("MODE 95,18");
    c;nl;nl;nl;
    if (trigger == 0) {strcenter("= L O G I N    S C R E E N ="); nl;}
    else if (trigger == 1) {strcenter("= R E G I S T R A T I O N    S C R E E N ="); nl;}
    nl;nl;
    strcenter(" <<< Enter the ID >>> ");
    char userInput[nameLength];
    space;p("\t");
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
        
}



void _exit_() {exit(0);}
void _launch_() {system("a.exe");_exit_();}

void registration(char userInput[]) // user registation screen
{
    c;
    nl;nl;nl;
    char tempPass[2][nameLength];
    strcenter("Enter password [ At least 8 characters long ] >>> ");
    space;p("\t");
    scanf("%s",tempPass[0]);
    strcpy(tempPass[1],tempPass[0]);


    FILE *regi = fopen("docs.txt","a");
    fprintf(regi,"%s,%s,0,0,0,0,10,0,0,0,0,10\n",userInput,tempPass[1]); // default data values later can be changed
    fclose(regi);
    nl;
    strcenter("Account created successfully !!!");
    space; hold;
    //fflush(stdout);
    //files_directory();
    //log_in(0); // 0 for log in 1 for registration
    //memset(tempArray, 0, size);
    _launch_();
    //free();
    //_exit_();
}



