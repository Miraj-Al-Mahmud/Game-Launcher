

#include "essentials.h"

void title(void)
{
    s(3);
    yellow;
    printf("\t\t\t\t+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");
    printf("\t\t\t\t|G|A|M|E| |L|A|U|N|C|H|E|R|\n");
    printf("\t\t\t\t+-+-+-+-+ +-+-+-+-+-+-+-+-+\n");

}


void logo(void)
{
    s(1);
    purple;
    printf("\t                     .::----:.              .:----::.                   \n");
    printf("\t                :+#O@@@@@@@@@@@*.        .+@@@@@@@@@@@O#+:              \n");
    printf("\t              -#@@@@@O##*++*#@@@@.      .O@@@#**+*##O@@@@@O-            \n");
    printf("\t            .#@@@O=:         -@@@O######O@@@-         .=O@@@#.          \n");
    printf("\t           .O@@@+             -O@@@@@@@@@@O-             +@@@O.         \n");
    printf("\t          .O@@@-    .::::.       ..::::..      .+**+.     -@@@@.        \n");
    printf("\t         .O@@@-     O@##@@                     O@--@@      :@@@O.       \n");
    printf("\t         #@@@=   ...@@  @@...              .:. +@##@# ...   -@@@#       \n");
    printf("\t        =@@@*  .@@OOO#  *OOO@@            *@#O@=.--.=@OO@+   *@@@+      \n");
    printf("\t       .@@@O   .@O:::.  .:::@@.          .@O.-@#    @@::@@    O@@@:     \n");
    printf("\t       #@@@-    #OOO@@  @@OO##            :#O#*:+**+-*OO*:    :@@@O     \n");
    printf("\t      -@@@*         O@..@@                     O@--@@          *@@@-    \n");
    printf("\t      #@@@:         *OOOO#                     +@##@*          .@@@O    \n");
    printf("\t     :@@@#                   :-=***####***+-:   .--.            #@@@:   \n");
    printf("\t     +@@@-               .+#@@@@@@@@@@@@@@@@@@O+.               -@@@+   \n");
    printf("\t     O@@@               +@@@@O*+=-::::::--+*O@@@@*.              @@@O   \n");
    printf("\t     @@@#             -O@@@*:                :+@@@O-             #@@@.  \n");
    printf("\t    -@@@+            +@@@@-                    :O@@@*.           +@@@-  \n");
    printf("\t    =@@@-          :O@@@*.                       +@@@O-          -@@@+  \n");
    printf("\t    =@@@=        .*@@@O:                          :O@@@*.        =@@@+  \n");
    printf("\t    .O@@@+:    :+@@@@+                              +@@@@*:    .+@@@@.  \n");
    printf("\t     .*@@@@@OO@@@@@*.                                .*@@@@@OO@@@@@#.   \n");
    printf("\t       .=#@@@@@O*=.                                    .=*O@@@@@#=.     \n");


}


void credits(void)
{
    s(2); white;
    printf("\t\t\t\t         CREATED BY\n");
    s(2); cyan;
    printf("\t\t\t\t     MIRAJ AL MAHMUD KHAN");
    s(1); red;
    s(1); green;
    s(1); white;
}

// login or registration
int login(void)
{
    c;
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

// display dots animation
void dots(void) { for (int i = 0; i < 5; ++i) { s(1); printf(" .");} }

void welcome()
{
    c; s(2);
    nl;nl;nl;nl;nl;nl;nl;
    p("\t\t\t");
    p(" W");s(1);cyan;
    p(" E");s(1);red;
    p(" L");s(1);yellow;
    p(" C");s(1);green;
    p(" O");s(1);white;
    p(" M");s(1);cyan;
    p(" E");s(1);green;

    // scores[0] is the name
    int i = 0; p("     ");
    while(scores[0][i]!='\0')
    {
        printf(" %c",scores[0][i]);
        s(.25);
        i++;
    }
}
