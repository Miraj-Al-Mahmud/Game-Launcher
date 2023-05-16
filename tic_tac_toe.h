

#include "essentials.h"

int computer = false; // toggle for A.I.
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // main board
char backup[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' }; // backup

int ai_rng() // generate moves for A.I.
{
    srand(time(NULL));
    int x = (rand() % 9) + 1;  // + 1 for ignoring the 0
    int flag = false;
    int i = x;
    while (i > 0)
    {
        if(square[i]=='X' || square[i]=='O') i--; // from the generated number to backwards
        else {flag = true; break;}
    }
    if (flag = true) return i;
    if (flag == false)
    {
        while(true)
        {
            if(square[i]=='X' || square[i]=='O') x++; // if not found then forwards
            else {flag = true; break;}
        } 
    }
    
    return x;
}

void add_points(int start, int player, int i, int chances) // not sure if it's needed
{
    tempArray[0]++;
    if (player==2 && i==1) tempArray[1]++;
    else tempArray[2]++;
    tempArray[3] = (tempArray[1]*100) / tempArray[0];
    if (chances < tempArray[4]) tempArray[4] = chances; 
}



int game1(int wheel) // wheel for rotations of the game
{
    for(int i = 0; i < 10; i++) square[i] = backup[i]; // copy the backup after deforming
    int counter = 0; // number of moves
    int player = 1, i, choice; // player 1 is the user himself
    char mark;
    do
    {
        counter++;
        board(counter); 
        if (player % 2 == 1) {player=1;}
        else { player = 2; }
        nl;nl;nl;
        
        if (computer==true && player==2) choice = ai_rng();
        else
        {
            printf("Player %d = \t   ", player);
            scanf("%d", &choice);
        }
        if (player == 1) {mark='X';}
        else {mark='O';}
        if (choice == 1 && square[1] == '1') square[1] = mark;
        else if (choice == 2 && square[2] == '2') square[2] = mark;
        else if (choice == 3 && square[3] == '3') square[3] = mark;
        else if (choice == 4 && square[4] == '4') square[4] = mark;
        else if (choice == 5 && square[5] == '5') square[5] = mark;
        else if (choice == 6 && square[6] == '6') square[6] = mark;
        else if (choice == 7 && square[7] == '7') square[7] = mark;
        else if (choice == 8 && square[8] == '8') square[8] = mark;
        else if (choice == 9 && square[9] == '9') square[9] = mark;
        else // for any wrong move
        {
            c;
            system("color 4F");
            printf("\n\n\n\n\n\n\n\n\t\t\t\t==========================================\n\n");
            printf("\t\t\t\t||\t\tWRONG MOVE \t\t||\n");
            printf("\n\t\t\t\t==========================================\n\n");

            player--;
            counter--;
            getch();
        }

        i = checkwin();
        player++;
        
        
    } while (i ==  - 1);

    board();

    if (i == 1){
        system("color 0F");
        c;nl;
        smiley(player);

    }
    else{
        system("cls");
        system("color 60");
        printf("\n\n\n\n\n\n\n\n\t\t\t\t==========================================\n\n");
        printf("\t\t\t\t||\t\tGAME DRAW \t\t||\n");
        printf("\n\t\t\t\t==========================================\n\n");
    }
    
    add_points(0, player, i, choice);
    ass();
    
    getch();

    return 0;
}


int checkwin() // winning or not ??
{
    if (square[1] == square[2] && square[2] == square[3])  return 1;
    else if (square[4] == square[5] && square[5] == square[6]) return 1;
    else if (square[7] == square[8] && square[8] == square[9]) return 1;
    else if (square[1] == square[4] && square[4] == square[7]) return 1;
    else if (square[2] == square[5] && square[5] == square[8]) return 1;
    else if (square[3] == square[6] && square[6] == square[9]) return 1;
    else if (square[1] == square[5] && square[5] == square[9]) return 1;
    else if (square[3] == square[5] && square[5] == square[7]) return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')
        return 0;
    else return  - 1;
}

void board(int counter)
{
    c;
    system("MODE 110,30");
    printf("\n\n\t\t\t\tTIC TAC TOE\n\n");

    if (counter%2==0) system("color 1f");
    else system("color 5f");


    printf("\t\t\tPlayer 1 (X)  -  Player 2 (O)\n\n\n");

    printf("\t\t\t   -------------------\n");
    printf("\t\t\t   |     |     |     |\n");
    printf("\t\t\t   |  %c  |  %c  |  %c  |\n", square[1], square[2], square[3]);

    printf("\t\t\t   |_____|_____|_____|\n");
    printf("\t\t\t   |     |     |     |\n");

    printf("\t\t\t   |  %c  |  %c  |  %c  |\n", square[4], square[5], square[6]);

    printf("\t\t\t   |_____|_____|_____|\n");
    printf("\t\t\t   |     |     |     |\n");

    printf("\t\t\t   |  %c  |  %c  |  %c  |\n", square[7], square[8], square[9]);

    printf("\t\t\t   |     |     |     |\n");
    printf("\t\t\t   -------------------\n");
}



void smiley(player){
    system("MODE 120,35");
    nl;nl;
    printf("                          $$$$$$$$$$$$$$$$$$$$\n");
    printf("                       $$$$$$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("                    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$         $$   $$$$$\n");
    printf("    $$$$$$        $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$$$$$$$$\n");
    printf(" $$ $$$$$$      $$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$       $$$$$$$$\n");
    printf(" $$$$$$$$$     $$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$    $$$$$$$$\n");
    printf("   $$$$$$$    $$$$$$$$$$$      $$$$$$$$$$$      $$$$$$$$$$$$$$$$$$$$$$$\n");
    printf("   $$$$$$$$$$$$$$$$$$$$$$$    $$$$$$$$$$$$$    $$$$$$$$$$$$$$  $$$$$$\n");
    printf("    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$\n");
    printf("     $$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$\n");
    printf("    $$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$       $$$$\t\tPLAYER %d WINS\n", --player);
    printf("    $$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$ $$$$$$$$$$$$$$$$$\n");
    printf("   $$$$$$$$$$$$$  $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$\n");
    printf("   $$$$$$$$$$$$$   $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$     $$$$$$$$$$$$\n");
    printf("  $$$$       $$$$    $$$$$$$$$$$$$$$$$$$$$$$$$$$$$$      $$$$\n");
    printf("             $$$$$     $$$$$$$$$$$$$$$$$$$$$$$$$         $$$\n");
    printf("               $$$$          $$$$$$$$$$$$$$$           $$$$\n");
    printf("                $$$$$                                $$$$$\n");
    printf("                 $$$$$$      $$$$$$$$$$$$$$        $$$$$\n");
    printf("                   $$$$$$$$     $$$$$$$$$$$$$   $$$$$$$\n");
    printf("                      $$$$$$$$$$$  $$$$$$$$$$$$$$$$$\n");
    printf("                         $$$$$$$$$$$$$$$$$$$$$$\n");
    printf("                                 $$$$$$$$$$$$$$$\n");
    printf("                                     $$$$$$$$$$$$\n");
    printf("                                      $$$$$$$$$$$\n");
    printf("                                       $$$$$$$$\n");

}


struct collector
{
    char player_name[nameLength];
    int g11;
    int g12;
    int g13;
    int g14;
    int g15;
    int g21;
    int g22;
    int g23;
    int g24;
    int g25;
};



void assembler(int played)
{
    system("MODE 110,20");
    nl;nl;nl;
    struct collector array_final[total_registered_users];
    for (int i = 0; i < total_registered_users; ++i)
    {
        strcpy(array_final[i].player_name, IDS[i]); // copy the name
        array_final[i].g11 = world_credentials_converted[i][1];
        array_final[i].g12 = world_credentials_converted[i][2];
        array_final[i].g13 = world_credentials_converted[i][3];
        array_final[i].g14 = world_credentials_converted[i][4]; // %
        array_final[i].g15 = world_credentials_converted[i][5];
        array_final[i].g21 = world_credentials_converted[i][6];
        array_final[i].g22 = world_credentials_converted[i][7];
        array_final[i].g23 = world_credentials_converted[i][8];
        array_final[i].g24 = world_credentials_converted[i][9]; // %
        array_final[i].g25 = world_credentials_converted[i][10];
    }
    
    // display data of all users
    space;
    printf("USERNAME\tPLAYED\tWIN\tLOSS\t%%\tMOVES\n");
    if (played==1)
    {
        for (int i = 0; i < total_registered_users; ++i)
        {
            space;
            printf("%s\t%d\t%d\t%d\t%d\t%d\n", \
            array_final[i].player_name, array_final[i].g11,array_final[i].g12,array_final[i].g13,array_final[i].g14,array_final[i].g15);
        }
    }
    else if (played==2)
    {
        for (int i = 0; i < total_registered_users; ++i)
        {
            space;
            printf("%s\t%d\t%d\t%d\t%d\t%d\n", \
            array_final[i].player_name, array_final[i].g21,array_final[i].g22,array_final[i].g23,array_final[i].g24,array_final[i].g25);
        }
    }
    
}





int welcome_screen_1() // A.I. or Human
{
    int handler = 0;
    c;
    nl;nl;
    strcenter("= S E L E C T\tM O D E =");
    nl;nl;nl;
    strcenter("1. Play against A.I.");
    strcenter("2. Play against another user");
    nl; nl;
    strcenter("Enter your choice >>> ");
    char te = getch();
    if (te=='1')
    {
        handler = 1;
        nl;
        strcenter("You have selected OPTION 1");
    }
    else if (te=='2')
    {
        handler = 2;
        nl;
        strcenter("You have selected OPTION 2");
    }
    strcenter("Press any key to continue ...");
    char dumb = getch();
    return handler;
    
}

/*


void add_all(char fname[], int counter) // attach the usernames with the files
{
    char file_name_final[] = "users/";
    strcat(file_name_final,fname);
    strcat(file_name_final,".txt");
    strcpy(world[counter],file_name_final);
}

*/

void leaderboard(int played)  // only arrange the data 
{   
    system("MODE 105,22");
    nl;nl;nl;
    // Name - Password - Win - Loss - % - Moves
    // 0 1
    // 2 3 4 5  6
    // 7 8 9 10 11
    printf("\t\t\tNAME\t\tPLAYED\tWIN\tLOSS\t%%\tMOVES");
    nl;
    int e = 2;
    if (played == 2) e+=5; 
    for (int i = 0; i < total_registered_users; ++i)
    {
        p("\t\t\t");
        if(strlen(version2[i][0])>5) printf("%s\t", version2[i][0]);
        else printf("%s\t\t", version2[i][0]);
        if (i!=found_index) for(int j=e; j<=e+4; j++) printf("%s\t", version2[i][j]);
        else
        {
            for(int j=e; j<=e+4; j++) printf("%d\t", tempArray[j-2]);
            p("<<< YOU <<<");
        }
        nl;
    }
    
    nl;nl;nl;
    space;
    hold;
    
}

int present(int array[], int number) // check for availability
{
    int flag = false;
    for (int i = 0; i < total_registered_users; ++i) {   if(array[i] == number) {flag = true; break;}  }
    return flag;
}



void sorted_leaderboard(int played)
{
    int num[total_registered_users];
    char nam[total_registered_users][nameLength];
    
    for (int i = 0; i < total_registered_users; ++i)
    {
        strcpy(nam[i],version2[i][0]); // one to one
        int t = atoi(version2[i][5]);
        num[i]=t; 
    }
    // copy the tempArray only one
    num[total_registered_users] = tempArray[3];
    strcpy(nam[total_registered_users],identity);
    
    //int n = sizeof(nam) / sizeof(nam[0]);

    //sort_names_and_values(nam, num, total_registered_users);
    
    for (int i = 0; i < total_registered_users; ++i) printf("%s %d\n", nam[i], num[i]);
    /*
    char distribution[total_registered_users][nameLength];
    
    // copy all of the names and percentages only
    
    for (int i = 0; i < total_registered_users; ++i) printf("%s %d\n", nam[i], num[i]);


    int ban[total_registered_users];
    // make them zeros
    int highest = -1, ind = -1;
    char champion[nameLength] = "";
    //strcpy(champion, nam[0]); // just to start off
    //highest = num[0]; // and the second one
    int k = 0; // for iterating through the for loop another last time
    while (k < total_registered_users)
    {
        int i;
        for (i = 0; i < total_registered_users; ++i)
        {
            if(num[i]>=highest && strcmp(champion,nam[i])==1) // nums and names do not match
            {
                highest = num[i];
                //free(champion);
                strcpy(champion, nam[i]);
                printf("%s %d\n", champion, highest);
                ind = i;
            }
            // at last get the name and num of the champion and change the values of the higest to the lowest
            
        }
        //free(distribution[k]);
        strcpy(distribution[k],champion);
        printf("%s\n", distribution[k]);
        num[ind]=-1*k+1;
        k++;
    }
    strcenter("FINAL");
    for (int i = 0; i < total_registered_users; ++i) printf("%s\n", distribution[i]);
    */
    hold;
}


void main_game_controller(int wheel) // driver code
{
    int x = welcome_screen_1();
    if (wheel==1) gather_previous_scores(); // only for the first time
    //gather_previous_scores();
    stats(0);
    if (x==1) {computer = true; game1(wheel);}
    else if (x==2) game1(wheel);
    
}


void hall_of_fame(int played) { leaderboard(played); /*assembler(played);*/ }