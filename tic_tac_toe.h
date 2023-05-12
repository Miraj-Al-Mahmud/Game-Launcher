

#include "essentials.h"

int computer = false;
char square[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char backup[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

int ai_rng()
{
    srand(time(NULL));
    int x = (rand() % 9) + 1;  // + 1 for ignoring the 0
    int flag = false;
    int i = x;
    while (i > 0)
    {
        if(square[i]=='X' || square[i]=='O') i--;
        else {flag = true; break;}
    }
    if (flag = true) return i;
    
    if (flag == false)
    {
        while(true)
        {
            if(square[i]=='X' || square[i]=='O') x++;
            else {flag = true; break;}
        } 
    }
    
    return x;
}

void add_points(int start, int player, int i, int chances)
{
    tempArray[0]++;
    if (player==2 && i==1) tempArray[1]++;
    else tempArray[2]++;
    tempArray[3] = (tempArray[1]*100) / tempArray[0];
    if (chances < tempArray[4]) tempArray[4] = chances;
    
    //for(int j=0;j<10;j++) printf("%d\n", tempArray[j]);   
}



int game1(int wheel)
{
    for(int i = 0; i < 10; i++) square[i] = backup[i];
    int counter = 0; // number of moves
    int player = 1, i, choice;
    char mark;
    do
    {
        counter++;
        board(counter); 
        if (player % 2 == 1) {player=1;}
        else { player = 2; }
        nl;nl;nl;
        
        if (computer==true && player==2)
        {
            choice = ai_rng();
        }
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
        else
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
    
    // choice is the moves
    // player is the identity
    //printf("Total number of moves = %d\n", choice);
    //printf("Player %d wins\n", player);
    
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






//  1f --- blue
/*
    4f ---- red
    6f ==== violet
    60 ==== draw


*/


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

int present(int array[], int number) // check for availability
{
    int flag = false;
    for (int i = 0; i < total_registered_users; ++i) {   if(array[i] == number) {flag = true; break;}  }
    return flag;
}


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
    /*
    // find the greatest
    int expected = 0;
    int ice_breaker = false;
    char winner[nameLength] = "";
    
    int index_array[total_registered_users];
    int sorted_array[total_registered_users];
    char winner_array_name[total_registered_users][nameLength];
    int winner_array_score[total_registered_users];
    int positions[total_registered_users];
    
    
    // gather only the name and percentage to the secondary array
    for (int i = 0; i < total_registered_users; ++i)
    {
        strcpy(winner_array_name[i], array_final[i].player_name);
        winner_array_score[i] = array_final[i].g14;
    }
    
    
    
    

    
    int index = 0;    
    int temp_high = 0;
    int j = 0;
    while (j < total_registered_users)
    {
        for (int i = 0; i < total_registered_users; ++i)
        {
            int pr = present(sorted_array, winner_array_score[i]);
            //printf("%d\n", pr);
            if (temp_high < winner_array_score && pr == 0) {temp_high = winner_array_score[i]; index = i;}    
        }
        sorted_array[j] = temp_high;
        index_array[j] = index;
        j++;
    }
    
    // display
    for (int i = 0; i < total_registered_users; ++i) printf("%s %d\n", winner_array_name[i],winner_array_score[i]);
    
    
    // finall show the results
    for (int i = 0; i < total_registered_users; ++i)
    {
        for (int j = 0; j < total_registered_users; ++j)
        {
            if (strcmp(array_final[j].player_name,winner_array_name[index_array[i]])==0)
            {
                printf("%s\t%d\t%d\t%d\t%d\t%d\n",array_final[j].player_name,array_final[j].g11,array_final[j].g12,array_final[j].g13,array_final[j].g14,array_final[j].g15);
                break;
            }
            //else printf("Not found\n");
        }
    }
    */

}





int welcome_screen_1()
{
    int handler = 0;
    c;
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



void add_all(char fname[], int counter) // attach the usernames with the files
{
    char file_name_final[] = "users/";
    strcat(file_name_final,fname);
    strcat(file_name_final,".txt");
    strcpy(world[counter],file_name_final);
}



void leaderboard()  // only arrange the data 
{
    for(int i=0; i <= total_registered_users; i++) add_all(IDS[i],i);          
    for (int i = 0; i < total_registered_users; ++i)
    {
        FILE *fptr = fopen(world[i],"r");
        
        char pass[50];
        int j = 0;
        while (fgets(pass, 50, fptr) != NULL)
        {
            strcpy(world_credentials[i][j],pass);
            j++;
        }
    }
    for (int i = 0; i < total_registered_users; ++i)
    {
        for (int j = 0; j < 11; ++j) // make the last new line to null chanracter
            world_credentials[i][j][strlen(world_credentials[i][j])-1]='\0';
    }
    /*
    for (int i = 0; i < total_registered_users; ++i)
    {
        for (int j = 0; j < 10; ++j)  printf("%s ->", world_credentials[i][j]);
        nl;
    }
    */
    for (int i = 0; i < total_registered_users; ++i) // convert to digits
    {
        for (int j = 1; j < 11; ++j)
        {
            int con = atoi(world_credentials[i][j]);
            world_credentials_converted[i][j] = con;
        }

    }
    /*
    for (int i = 0; i < total_registered_users; ++i) // display all the infos
    {
        printf("%s", IDS[i]);
        for (int j = 1; j < 11; ++j)  printf("\t%d", world_credentials_converted[i][j]);
        nl;
    }
    */   
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


void hall_of_fame(int played) { leaderboard(); assembler(played); }