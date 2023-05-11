

#include "essentials.h"


char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
char backup[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };



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
        else{player=2;}
        printf("\n\n\n");
        printf("Player %d = \t   ", player);
        scanf("%d", &choice);

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


int welcome_screen_1()
{
    int handler = 0;
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


char world[userLimit][nameLength]; // all the filenames
int how_many_users = 0;
void add_all(char fname[], int counter)
{
    char file_name_final[] = "users/";
    strcat(file_name_final,fname);
    strcat(file_name_final,".txt");
    strcpy(world[counter],file_name_final);

}


void leaderboard()
{
    
    for(int i=0; i< userLimit; i++)
    {
        char temp_array[nameLength];
        if(strlen(names[i])>minimum_length)
        {
            int s = 0;
            while(names[i][s] != '\0')
            {
                temp_array[s] = names[i][s];
                s++;
            }
        }
        printf("%s\n", temp_array);
    }
    //for(int i=0; i<= how_many_users; i++) printf("%d %s-\n",i, world[i]);
}

void main_game_controller(int wheel) // driver code
{
    int x = welcome_screen_1();
    if (wheel==1) gather_previous_scores(); // only for the first time
    //gather_previous_scores();
    stats(0);
    if (x==1) {}
    else if (x==2) game1(wheel);
    
}
