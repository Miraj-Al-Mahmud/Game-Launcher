
// Libraries
#include <stdio.h>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define nameLength 30
#define userLimit 50
#define minimum_length 1
char names[userLimit][nameLength]; // array of all names
char IDS[userLimit][nameLength]; // final ids
char userPassword[nameLength];
char scores[15][nameLength]; // login details -> first one is the password
char identity[nameLength]; // userName
char world[userLimit][nameLength]; // all the registered filenames
char world_credentials[userLimit][11][nameLength]; // 5 for each game
int world_credentials_converted[userLimit][11]; // 5 for each game

#define row 35
#define column 100
#define true 1
#define false 0
 
// definitions and color codes
#define nl printf("\n")
#define space printf("\t\t\t\t")
#define c system("cls")
#define s(num) Sleep(num*1000)
#define p(data) printf(data)
#define f(start,end) for(int i=start; i<=end; i++)

#define green system("color 0a")
#define cyan system("color 0b")
#define red system("color 0c")
#define purple system("color 0d")
#define yellow system("color 0e")
#define white system("color 0f")
#define cyan system("color 0b")

// white background
#define white_black system("color F0")
#define white_blue system("color F1")
#define white_green system("color F2")
#define white_cyan system("color F3")
#define white_blue system("color F9")
#define white_green system("color FA")
#define white_red system("color FC")
// yellow background
#define  yellow_black system("color E0")
#define  yellow_green system("color EA")
#define  yellow_red system("color EC")
// red background
#define  red_black system("color C2")
#define  red_grey system("color C7")
#define  red_blue system("color C9")
#define  red_green system("color CA")
#define  red_cyan system("color CB")
#define  red_yellow system("color CE")
#define  red_white system("color CF")
// cyan background
#define  cyan_blue system("color B9")
#define  cyan_red system("color BC")
// green background
#define  green_black system("color A0")
#define  green_blue system("color A9")
#define  green_red system("color AC")
#define  green_pink system("color AD")



