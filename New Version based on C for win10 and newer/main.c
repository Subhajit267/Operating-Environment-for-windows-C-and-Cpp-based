//VER:5.0 dev build
//c is implemented

#include<time.h>
#include<stdio.h>
#include <stdlib.h>
#include<windows.h>
#include<math.h>
#include<string.h>
#define bold "\x1B[1m"//ascii escape sequences jate bar bar mention na korte hoi tai age predifine korechi
#define red "\x1B[31m"
#define BLUE "\x1B[34m"
#define purple "\x1B[95m"
#define RED "\x1B[91m"
#define Yellow "\x1B[33m"
#define yellow "\x1B[93m"
#define blue "\x1B[94m"
#define UNDERLINE "\033[4m"
int reg_status,trial;
#define CLOSEUNDERLINE "\033[0m"
#define green "\x1B[92m"
#define cc "\033[0m"
#define cyan "\x1B[36m"
#define invisible "\x1B[8m"
#define B1 "\x1B[41m"
#define B2 "\x1B[42m"
#define B3 "\x1B[43m"
#define B4 "\x1B[44m"
#define B5 "\x1B[45m"
#define B6 "\x1B[46m"
#define B7 "\x1B[47m"
#define B8 "\x1B[100m"
#define B9 "\x1B[101m"
#define B10 "\x1B[102m"
#define B11 "\x1B[103m"
#define B12 "\x1B[104m"
#define B13 "\x1B[105m"
#define B14 "\x1B[106m"
#define B15 "\x1B[107m"
#include"looks.h"
void settings();
#include "sources.h"
#include "Sources2.h"
#include "programs.h"

void prompt()//Main controller
{
    system("cls");
    gotoxy(1,1);
    layout();
    logo();gotoxy(32,10);
    printf("%s%s%sOperating Environment ver: 4.12.03%s",red ,bold,UNDERLINE,cc);
    char command[50];
    while(1)
    {
        if(ins==9)//if guest user
        {
            printf("\a"); fflush(stdout);
            gotoxy(32,12);
            printf("Only available commands are install, login(use it to re login) and exit");
            gotoxy(32,13);
            printf("Command->");
            scanf(" %49s",&command);
            if(strcmp(command,"install")==0)
            {
                FILE* file=fopen("file.txt", "r");
                int bs = 1;
                if (file!=NULL)
                {  gotoxy(32,14);printf("Already  installed.");
                printf("\a\a\a" );fflush(stdout);
                  gotoxy(32,16);
                  printf("Type login and re login with your user ID password(if exists).");
                   getchar();
                   getchar();
                    prompt();
                }
                else{
                    IP();
                    prompt();
                }
            }
            else if(strcmp(command,"exit")==0)
            {      printf(" %s%sStatus: You are about to exit.", red , bold);
            printf("\a\a");fflush(stdout);
                exit(0);
            }
            else if(strcmp(command, "reg_edit")==0)
            {
                printf("\a");fflush(stdout); reg_status = 0;
                reg_edit();
            }
            else if(strcmp(command, "login")==0)
            {
                FILE* file;
                char filename[100];
                int ins;
                strcpy(filename, "file.txt");

                file = fopen(filename, "r");
                if (file != NULL) {
                    ins = 0;
                    fclose(file);
                }
                else {
                    ins = 9;
                }

                gotoxy(1,1);
                system("cls");
                layout();
                logo();
                login();
            }
            else
            {
                FILE* file;
                char  filename[100];

                strcpy(filename, "file.txt");
                file = fopen(filename, "r");
                if (file != NULL)
                {
                    gotoxy(32, 15);
                    printf("%s%sI see you trying to access user features without a valid installation/ user id creation. But access denied.%s",
                        red, bold, cc);
                    printf("\a\a\a");
                    getchar();
                    getchar();
                    fclose(file);
                    prompt();
                }
                else {
                    gotoxy(32, 20);
                    printf("%s%s Status: No Command%s", red, bold, cc);
                    getchar();
                    getchar();
                    prompt();
                }

            }
        }
        else//If a proper user
        {   gotoxy(32,11);
			printf("%s%sType help to get list of commands%s",green ,bold,cc);
			gotoxy(88,10);
			reg_status=0;
            printf("%s%sWelcome%s%s%s ",bold,purple,cyan,bold,name1);
            gotoxy(32,13);
            printf("%s%sCommand->%s",blue ,bold , cc);
            scanf("%19s",command);
            if (strcmp(command,"Help")==0|| strcmp(command,"HELP")==0|| strcmp(command, "help")==0)//Help command to make the command interface easy
            {    gotoxy(35,14);
             	 printf("%s%sType:%s", yellow, bold, cc);
                 gotoxy(35, 15); printf("%s%s\tTicTacToe%s", blue, bold, cc); //TicTacToe
                 gotoxy(35, 16); printf("%s%s\tCalculator%s", red, bold, cc); //Calculator
                 gotoxy(35, 17); printf("%s%s\tQuiz%s", blue, bold, cc); //Quiz
                 gotoxy(35, 18); printf("%s%s\tTemp_Conv%s", red, bold, cc); //Temperature_Converter
                 gotoxy(35, 19); printf("%s%s\teqn_solve%s", blue, bold, cc); //Pair of linear equations in two variables
                 gotoxy(35, 20); printf("%s%s\tquad_eqn_solve, to open the applications(if installed).%s", red, bold, cc); //Quadratic Equation Solver
                 gotoxy(35, 21); printf("%s%sType:%s", yellow, bold, cc); //New Section
                 gotoxy(35, 22); printf("%s%s\texit: To exit .%s", red, bold, cc); //Exit Command
                 gotoxy(35, 23); printf("%s%s\tver: To see version number%s", blue, bold, cc); //Version Number Command
                 gotoxy(35, 24); printf("%s%s\tinst_all: To install al applications except TicTacToe and Quiz at once.%s", red, bold, cc); //Installer for programs
                 gotoxy(35, 25); printf("%s%s\tsettings: To change your existing settings.%s", blue, bold, cc); //Settings Application
                 gotoxy(35, 26); printf("%s%s\tType 'registryeditor' to enter the mode%s", red, bold, cc); //Registry Key modifier
                 gotoxy(35, 27); printf("%s%s\tTo re-login type login.%s", blue, bold, cc); //Login
                 gotoxy(35, 28); printf("%s%s\tTo install an app from above  list type inst_'with app name'%s", red, bold, cc); //Install command
                 gotoxy(35, 29); printf("%s%s\tTo uninstall an app from above  list type unst_'with app name'%s", blue, bold, cc); //Uninstall command

                 getchar(); getchar();

                    prompt();//Since Cls command has been removed hence after completion of a command the program returns too the origin
            }
            else if (strcmp(command, "TicTacToe") == 0 ||
                strcmp(command, "tictactoe") == 0 ||
                strcmp(command, "TICTACTOE") == 0) //If TicTacToe is installed
            {
                bs = 1; // Registry key for the bootscreen to change it for tictactoe

                FILE* f; // opening file containing installation info
                f = fopen("TicTacToe.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0; // file missing -> not installed
                }

                if (reg == 1) { // If installed
                    bootscreen();
                    selector_t();
                }
                else { // If not installed
                    gotoxy(32, 15);
                    printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                    printf("\a\a");
                    getchar();
                    getchar();
                    prompt();
                }
            }

            else if (strcmp(command, "Quiz") == 0 ||
                strcmp(command, "QUIZ") == 0 ||
                strcmp(command, "quiz") == 0) //If quiz is installed
            {
                FILE* f;
                f = fopen("Quiz.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0; // file missing -> not installed
                }

                bs = 2; // Changing bootscreen

                if (reg == 1) { // Checking installation state
                    bootscreen();
                    start();
                }
                else {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                    printf("\a\a");
                    getchar();
                    getchar();
                    prompt();
                }
            }

            else if (strcmp(command, "ar(t_c)") == 0)
            {
                FILE* f;
                f = fopen("ATC.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                bs = 8; // Changing bootscreen
                if (reg == 1) // Checking installation state
                {
                    bootscreen();
                    atc();
                }
                else
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                    printf("\a\a");
                    getchar();
                    getchar();
                    prompt();
                }
            }

            else if (strcmp(command, "inst_ar(t_c)") == 0) // Installer command for TicTacToe
            {
                v = 8; // Activation required hence v=1
                bs = 8;

                FILE* f;
                f = fopen("ATC.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) // Error handling if already installed
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar();
                    getchar();
                    prompt();
                }
                else // running the installer
                {
                    bootscreen();
                    installer();
                }
            }

            else if (strcmp(command, "TEMP_CONV") == 0 ||
                strcmp(command, "temp_conv") == 0 ||
                strcmp(command, "Temp_Conv") == 0) // If temperature converter is installed
                {
                    bs = 3; // Changing bootscreen
                    FILE* f; // Checking installation state
                    f = fopen("TC.txt", "r");
                    if (f != NULL) {
                        fscanf(f, "%d", &reg);
                        fclose(f);
                    }
                    else {
                        reg = 0;
                    }

                    if (reg == 1) {
                        bootscreen();
                        tc();
                    }
                    else {
                        gotoxy(32, 15);
                        printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                        printf("\a\a");
                        getchar();
                        getchar();
                        prompt();
                    }
                    }
            else if (strcmp(command, "VER") == 0 || strcmp(command, "ver") == 0) // Version command
            {
                gotoxy(32, 15);
                printf("%s%s   VER: 4.23.09(DEV)%s", red, bold, cc);
                getchar();
                getchar();
                prompt();
                }
            else if (strcmp(command, "whoami") == 0 || strcmp(command, "list_ID") == 0) // username identifier
            {
                gotoxy(32, 15);
                printf("%s%s%s%s", red, bold, name1, cc);
                getchar();
                getchar();
                prompt();
                }
            else if (strcmp(command, "exit") == 0 || strcmp(command, "EXIT") == 0 || strcmp(command, "Exit") == 0) // exit command
            {
                printf("\a\a\a\a");
                gotoxy(30, 10);
                system("cls");
                printf("%s%s Program is shutting Down. Thank You for using. Have a good time. Bye!!!%s", RED, bold, cc);
                Sleep(1000);
                exit(0);
                prompt();
                }
            else if (strcmp(command, "inst_TicTacToe") == 0) // Installer command for TicTacToe
            {
                v = 1; // Activation required hence v=1
                bs = 1;

                FILE* f;
                f = fopen("TicTacToe.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) // Error handling if already installed
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar();
                    getchar();
                    prompt();
                }
                else // running the installer
                {
                    bootscreen();
                    installer();
                }
                }
            else if (strcmp(command, "inst_Temp_Conv") == 0 || strcmp(command, "inst_temp_conv") == 0) // Installer for Temperature_Converter
            {
                v = 3; // Activation not required
                bs = 3; // Changing bootscreen

                FILE* f;
                f = fopen("TC.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) // If already installed
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar();
                    getchar();
                    prompt();
                }
                else
                {
                    bootscreen();
                    installer();
                    tc();
                }
                }
            else if (strcmp(command, "inst_Calculator") == 0) // Installer for calculator
            {
                bs = 4; // Changing bootscreen
                v = 4;  // activation required
                FILE* f;
                f = fopen("Calc.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) // If already installed
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar();
                    getchar();
                    prompt();
                }
                else
                {
                    bootscreen();
                    installer();
                    calc();
                }
                }

            else if (strcmp(command, "inst_Quiz") == 0) // Installer for quiz
            {
                v = 2; // Activation required
                bs = 2;
                FILE* f;
                f = fopen("Quiz.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1)
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar();
                    getchar();
                    prompt();
                }
                else
                {
                    bootscreen();
                    installer();
                }
                }

            else if (strcmp(command, "Calculator") == 0 || strcmp(command, "calculator") == 0) // Command for calculator
            {
                bs = 4; // At first changing registry value to bring appropriate bootscreen
                FILE* f;
                f = fopen("Calc.txt", "r"); // Opening the file for checking installation state
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) // If installed
                {
                    bootscreen(); // opening the calculator
                    calc();
                }
                else
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                    printf("\a\a");
                    getchar();
                    getchar();
                    prompt();
                }
                }

            else if (strcmp(command, "eqn_solve") == 0) // command for equation solver
            {
                bs = 6; // Settings bootscreen
                FILE* f;
                f = fopen("solve.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) // if installed
                {
                    bootscreen();
                    get_Eqn();
                }
                else // if not installed
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                    printf("\a\a");
                    getchar();
                    getchar();
                    prompt();
                }
                }

            else if (strcmp(command, "quad_eqn_solve") == 0) // command for quadratic equation solver
            {
                bs = 7;
                FILE* f;
                f = fopen("quad_solve.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1)
                {
                    bootscreen();
                    quad_eqn_solve();
                }
                else
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Non installed yet%s", red, bold, cc);
                    printf("\a\a");
                    getchar();
                    getchar();
                    prompt();
                }
                }

            else if (strcmp(command, "inst_eqn_solve") == 0) // command for installing equation solver
            {
                v = 6;
                bs = 6;
                FILE* f;
                f = fopen("solve.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1)
                {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar();
                    getchar();
                    prompt();
                }
                else
                {
                    bootscreen();
                    installer();
                    get_Eqn();
                }
                }

            else if (strcmp(command, "inst_quad_eqn_solve") == 0) // installing quadratic equation solver
            {
                v = 7;
                bs = 7;
                FILE* f = fopen("quad_solve.txt", "r");
                if (f != NULL) {
                    fscanf(f, "%d", &reg);
                    fclose(f);
                }
                else {
                    reg = 0;
                }

                if (reg == 1) {
                    gotoxy(32, 15);
                    printf("%s%s  Status: Already installed%s", yellow, bold, cc);
                    printf("\a");
                    getchar(); getchar();
                    prompt();
                }
                else {
                    bootscreen();
                    installer();
                    quad_eqn_solve();
                }
                }

                // List of uninstalling commands
            else if (strcmp(command, "unst_eqn_solve") == 0)
            {
                FILE* f = fopen("solve.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "unst_TicTacToe") == 0)
            {
                FILE* f = fopen("TicTacToe.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "unst_Temp_Conv") == 0)
            {
                FILE* f = fopen("TC.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "unst_Calculator") == 0)
            {
                FILE* f = fopen("Calc.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "unst_quad_eqn_solve") == 0)
            {
                FILE* f = fopen("quad_solve.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "unst_Quiz") == 0)
            {
                FILE* f = fopen("Quiz.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "unst_ar(t_c)") == 0)
            {
                FILE* f = fopen("ATC.txt", "w");
                reg = 0;
                if (f != NULL) {
                    fprintf(f, "%d", reg);
                    fclose(f);
                }
                gotoxy(32, 15);
                printf("%s%s Uninstallation finished.%s", blue, bold, cc);
                printf("\a\a\a\a\a\a");
                getchar(); getchar();
                prompt();
                }

                // Something interesting
            else if (strcmp(command, "registryeditor") == 0) // Registry key editor
            {
                printf("\a\a\a\a\a\a\a");
                fflush(stdout);
                reg_status = 0; // starts without admin privileges
                reg_edit();
                }

            else if (strcmp(command, "display_source") == 0) // Source code displayer
            {
                printf("\a");
                fflush(stdout);
                source();
                getchar();
                system("cls");
                }

            else if (strcmp(command, "inst_all") == 0) // Installer for applications other than TicTacToe and Quiz
            {
                reg = 1;
                FILE* tc = fopen("TC.txt", "w");
                if (tc) { fprintf(tc, "%d", reg); fclose(tc); }

                FILE* c = fopen("Calc.txt", "w");
                if (c) { fprintf(c, "%d", reg); fclose(c); }

                FILE* eqn = fopen("solve.txt", "w");
                if (eqn) { fprintf(eqn, "%d", reg); fclose(eqn); }

                FILE* qe = fopen("quad_solve.txt", "w");
                if (qe) { fprintf(qe, "%d", reg); fclose(qe); }

                FILE* at = fopen("ATC.txt", "w");
                if (at) { fprintf(at, "%d", reg); fclose(at); }

                gotoxy(32, 15);
                printf("%s%sSuccessfully completed the command%s", green, bold, cc);
                getchar(); getchar();
                prompt();
                }

            else if (strcmp(command, "settings") == 0 ||
                strcmp(command, "Settings") == 0 ||
                strcmp(command, "SETTINGS") == 0)
                {
                    settings();
                    }

            else if (strcmp(command, "login") == 0 || strcmp(command, "Login") == 0)
            {
                system("cls");
                layout();
                login();
                }

            else
            {
                gotoxy(32, 15);
                printf("%s%s  No such command%s", red, bold, cc);
                printf("\a");
                getchar(); getchar();
                prompt();
                }

        }
    }
}
int main()
{
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SMALL_RECT DisplayArea = { 0, 0, 99, 39 };  // left, top, right, bottom
    COORD bufferSize = { 10000, 4000 };             // width × height

    // set screen buffer size
    SetConsoleScreenBufferSize(hOut, bufferSize);

    // set window size
    SetConsoleWindowInfo(hOut, TRUE, &DisplayArea);


    bs = 0; // initial bootscreen for OE
    bootscreen();

    FILE* file;
    char filename[100] = "file.txt";
    file = fopen(filename, "r");

    if (file != NULL)
    {
        fclose(file);
        system("cls");
        layout();
        logo();
        login();
        prompt();
    }
    else
    {
        IP();
    }

    return 0;
}

void IP() // Installer procedure
{
    gotoxy(1, 1);
    layout();
    logo();
    gotoxy(10, 8);

    char c[50]; // input buffer
    reg_status = 1; // Added support for admin reg_edit

    printf("%s%sDo you want to directly install this application or you want to use it once before installation?(Enter choice below).%s%s",
        BLUE, bold, cc, cc);
    gotoxy(32, 10);
    printf("%s%s%sHelp Me Decide:%s", purple, bold, UNDERLINE, cc);
    gotoxy(32, 12);
    printf("%s%sIf you wish to install the program directly on the browser without testing for once press y.%s", yellow, bold, cc);
    gotoxy(32, 13);
    printf("If you want to test the program before installing i.e. if you want to have a look at the user ");
    gotoxy(32, 14);
    printf("interface press n and it will load you into the guest user login screen. Just Press enter there  ");
    gotoxy(32, 15);
    printf("to login. As it is trial so only three commands login, install and exit would be there.");
    gotoxy(32, 18);
    printf("%s%sEnter your choice(y/n):%s", cyan, bold, cc);

    printf("%s", invisible); // making console invisible
    scanf("%49s", c); // input (limit 49 chars to prevent overflow)
    printf("%s", cc); // reset color

    if (strcmp(c, "n") == 0 || strcmp(c, "N") == 0) // trial required
    {
        system("cls");
        gotoxy(1, 1);
        layout();
        logo();
        gotoxy(5, 7);
        printf("After completion of your trial type 'install' to restart the setup to continue.");
        login();
    }
    else if (strcmp(c, "registryeditor_admin") == 0) // reg_edit required
    {
        reg_edit(); // Skipping setup
    }
    else if (strcmp(c, "prompt") == 0) // Totally skipping setup
    {
        reg_status = 1;
        ins = 0;
        prompt();
    }
    else if (strcmp(c, "y") == 0 || strcmp(c, "Y") == 0) // direct installation required
    {
        system("cls");
        layout();
        logo();
        gotoxy(32, 8);
        printf("%s%s%sWhile the game is loading let us know its working:%s", UNDERLINE, red, bold, CLOSEUNDERLINE);
        gotoxy(32, 10);
        printf("%sAt first type help command at the prompt.%s", yellow, CLOSEUNDERLINE);
        gotoxy(32, 11);
        printf("You will be getting a list of available commands use it  ");
        gotoxy(88, 10);
        printf("%s  Designed for ease%s", purple, cc);
        gotoxy(32, 12);
        printf("%sto install your desired program%s", yellow, cc);
        gotoxy(88, 11);
        printf("%s  For ease in using %s", purple, cc);
        gotoxy(32, 13);
        printf("%sEnjoy using it!!!%s", yellow, cc);
        gotoxy(88, 12);
        printf("%s  softwares%s", purple, cc);
        gotoxy(88, 17);
        printf("%sDEVELOPER:%s Subhajit Halder", green, RED);
        gotoxy(2, 6);

        progressbar();
        Sleep(6000);
        add_user();
        reg = 0;
        install();        // Creating default files
        Improvements();   // Showing improvements
        getchar();        // wait
        gotoxy(1, 2);
        layout();
        login();          // Restart after installation
    }
}

void reg_edit() // Registry Key modifier/manipulator
{
    gotoxy(1, 1);
    layout();
    gotoxy(5, 7);
    printf("%s%s%sWelcome to Registry Editor version:3.5.0(For Power Users).%s",
        bold, UNDERLINE, red, cc);
    gotoxy(5, 8);
    printf("%s%sAvailable commands:%s", green, bold, cc);

    gotoxy(5, 9);  printf("%s%s\ta.)install", yellow, bold);
    gotoxy(5, 10); printf("\tb.)temp");
    gotoxy(5, 11); printf("\tc.)exit");
    gotoxy(5, 12); printf("\td.)reset");
    gotoxy(5, 13); printf("\te.)prompt");
    gotoxy(5, 14); printf("\tf.)add_key (Only for Quiz and TicTacToe)");
    gotoxy(5, 15); printf("\tg.)user");
    gotoxy(5, 16); printf("\th.)help (It is advised to use help command first to get usage of available commands.%s", cc);

    while (1) // infinite loop
    {
        char command[100];
        gotoxy(5, 17);
        printf("Command-> ");
        scanf("%99s", command);

        FILE* t, * q, * tc, * c, * eqn, * d;
        reg = 1;

        if (strcmp(command, "install") == 0)
        {
            if (reg_status == 1)
            {
                install();
                gotoxy(5, 18);
                printf("%s%sSuccesfully completed the command%s", cyan, bold, cc);
                getchar(); getchar();
                reg_edit();
            }
            else
            {
                gotoxy(5, 18);
                printf("%s%sSuccesfully completed the command%s", cyan, bold, cc);
                getchar(); getchar();

                tc = fopen("TC.txt", "w"); if (tc) { fprintf(tc, "%d", reg); fclose(tc); }
                c = fopen("Calc.txt", "w"); if (c) { fprintf(c, "%d", reg); fclose(c); }
                d = fopen("Calc.txt", "w"); if (d) { fprintf(d, "%d", reg); fclose(d); }
                eqn = fopen("solve.txt", "w"); if (eqn) { fprintf(eqn, "%d", reg); fclose(eqn); }

                reg_edit();
            }
        }
        else if (strcmp(command, "add_key") == 0)
        {
            if (reg_status == 1)
            {
                gotoxy(5, 18); printf("\tCommand-> ");
                scanf("%99s", command);

                if (strcmp(command, "both") == 0) {
                    t = fopen("TicTacToe.txt", "w"); if (t) { fprintf(t, "%d", reg); fclose(t); }
                    q = fopen("Quiz.txt", "w");      if (q) { fprintf(q, "%d", reg); fclose(q); }
                }
                else if (strcmp(command, "quiz") == 0) {
                    q = fopen("Quiz.txt", "w"); if (q) { fprintf(q, "%d", reg); fclose(q); }
                }
                else if (strcmp(command, "tictactoe") == 0) {
                    t = fopen("TicTacToe.txt", "w"); if (t) { fprintf(t, "%d", reg); fclose(t); }
                }

                gotoxy(5, 18);
                printf("%s%sSuccesfully completed the command%s", cyan, bold, cc);
                getchar(); getchar();
                reg_edit();
            }
            else
            {
                gotoxy(5, 20);
                printf("%s%sStatus: No available command%s", red, bold, cc);
                printf("\a\a\a\a\a\a\a\a\a\a\a\a");
                getchar(); getchar();
                reg_edit();
            }
        }
        else if (strcmp(command, "exit") == 0)
        {
            layout();
            logo();
            login();
        }
        else if (strcmp(command, "temp") == 0)
        {
            gotoxy(5, 18);
            printf("Command-> ");
            scanf("%99s", command);

            if (strcmp(command, "TTT") == 0 || strcmp(command, "ttt") == 0)
            {
                if (reg_status == 1) {
                    computer_vs_player();
                }
                else {
                    gotoxy(5, 20);
                    printf("%s%sStatus: No available command%s", red, bold, cc);
                    printf("\a\a\a\a\a\a\a\a\a\a\a\a");
                    getchar(); getchar();
                    reg_edit();
                }
            }
            else if (strcmp(command, "quiz") == 0)
            {
                if (reg_status == 1) start();
                else { trial = 4; start(); }
            }
            else
            {
                gotoxy(10, 20);
                printf("%s%stemp command is available for only one program(s)%s", red, bold, cc);
                getchar(); getchar();
                reg_edit();
            }
        }
        else if (strcmp(command, "user") == 0)
        {
            if (reg_status == 1)
            {
                FILE* file = fopen("file.txt", "r");
                if (file != NULL) // user exists
                {
                    fclose(file);
                    gotoxy(5, 19);
                    printf("%s%sWarning! This command will reset all your user-id password%s", RED, bold, cc);
                    printf("\a\a\a\a\a\a\a\a\a\a");
                    gotoxy(5, 20);
                    printf("Do you want to continue:");
                    char a; scanf(" %c", &a);

                    if (a == 'y') {
                        add_user();
                        getchar();
                        gotoxy(5, 25);
                        printf("%s%sSuccesfully completed the command%s", cyan, bold, cc);
                        getchar(); getchar();
                        reg_edit();
                    }
                    else {
                        gotoxy(5, 19);
                        printf("%s%sExecution Cancelled!!%s", RED, bold, cc);
                        getchar(); getchar();
                        reg_edit();
                    }
                }
                else {
                    add_user(); // clean install
                }
            }
            else {
                gotoxy(5, 19);
                printf("%s%sExecution Cancelled!!%s", RED, bold, cc);
                getchar(); getchar();
                reg_edit();
            }
        }
        else if (strcmp(command, "reset") == 0)
        {
            gotoxy(5, 19);
            printf("%s%sWarning! This command will reset all your applications.%s", RED, bold, cc);
            printf("\a\a\a\a\a\a\a\a\a\a");
            gotoxy(5, 20);
            printf("Do you want to continue:");
            char a; scanf(" %c", &a);

            if (a == 'y') {
                reg = 0;
                install();
                gotoxy(5, 25);
                printf("%s%sSuccesfully completed the command%s", cyan, bold, cc);
                getchar(); getchar();
                reg_edit();
            }
            else {
                gotoxy(5, 19);
                printf("%s%sExecution Cancelled!!%s", RED, bold, cc);
                getchar(); getchar();
                reg_edit();
            }
        }
        else if (strcmp(command, "prompt") == 0 || strcmp(command, "Prompt") == 0)
        {
            system("cls");
            gotoxy(1, 1);
            layout();
            logo();
            FILE* file = fopen("file.txt", "r");
            if (file != NULL) { ins = 0; fclose(file); }
            else ins = 9;
            prompt();
        }
        else if (strcmp(command, "help") == 0)
        {
            gotoxy(5, 20);
            printf("%s%s Welcome to HELP Documentation Ver: 1.0.%s", blue, bold, cc);
            gotoxy(5, 21); printf("\ta.)install: To install all the programs at once.");
            gotoxy(5, 22); printf("\tb.)add_key: Install only TicTacToe and Quiz (admin only).");
            gotoxy(5, 23); printf("\tc.)exit: Exit Registry Editor and open login screen.");
            gotoxy(5, 24); printf("\td.)temp: To access a program temporarily (TTT/Quiz).");
            gotoxy(5, 25); printf("\te.)user: Add new user or bypass password.");
            gotoxy(5, 26); printf("\tf.)reset: Uninstall all applications.");
            gotoxy(5, 27); printf("\tg.)clear: Clear output screen.");
            getchar(); getchar();
            reg_edit();
        }
        else if (strcmp(command, "clear") == 0 || strcmp(command, "cls") == 0)
        {
            system("cls");
            reg_edit();
        }
        else if (strcmp(command, "start_admin_reg_edit") == 0)
        {
            reg_status = 1;
            reg_edit();
        }
        else
        {
            gotoxy(5, 20);
            printf("%s%sStatus: No available command%s", red, bold, cc);
            printf("\a\a\a\a\a\a\a\a\a\a\a\a");
            getchar(); getchar();
            reg_edit();
        }
    }
}
