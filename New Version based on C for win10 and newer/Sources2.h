//New layout done for the file
//installer for all programs
void installer()
{
    printf("%s%s", green, bold);
    reg = 1; // registry value

    gotoxy(1, 1); layout();

    if (v == 1 && bs == 1) // TIC TAC TOE
    {
        gotoxy(20, 8);
        printf("%s\t\t\t\t\t\tTIC TAC TOE%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:4.0", yellow, bold);
    }
    else if (v == 2 && bs == 2) // QUIZ APP
    {
        gotoxy(20, 8);
        printf("%s\t\t\t\t\t\tQUIZ__APP%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:10.8", yellow, bold);
    }
    else if (v == 3 && bs == 3) // TEMP_CONV
    {
        gotoxy(20, 8);
        printf("%s\t\t\t\t\t\tTEMP_CONV%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:4.05", yellow, bold);
    }
    else if (v == 4 && bs == 4) // CALCULATOR
    {
        gotoxy(20, 8);
        printf("%s\t\t\t\t\t\tCALCULATOR%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:3.05", yellow, bold);
    }
    else if (v == 6 && bs == 6) // Pair_of_eqn_solve
    {
        gotoxy(46, 8);
        printf("%sPair_of_eqn_solve%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:4.05", yellow, bold);
    }
    else if (v == 7 && bs == 7) // Quadratic_eqn_solve
    {
        gotoxy(60, 8);
        printf("%sQuadratic_eqn_solve%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:1.05", yellow, bold);
    }
    else if (v == 8 && bs == 8) // Area_Of_Triangle(CO)
    {
        gotoxy(60, 8);
        printf("%sArea_Of_Triangle(CO)%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s%s\t\t\t\t\t       Version:1.00", yellow, bold);
    }

    gotoxy(20, 10); printf("\t\t\t\t\t        Please_Wait.");
    gotoxy(20, 11); printf("\t\t\t\t\t     While setup is");
    gotoxy(20, 12); printf("\t\t\t\t\t        Installing...%s", cc);

    Sleep(1000);

    // Activation / registry write
    FILE* f;
    if (v == 1 && bs == 1) activation();
    else if (v == 2 && bs == 2) activation();
    else if (v == 3 && bs == 3) { f = fopen("TC.txt", "w"); fprintf(f, "%d", reg); fclose(f); }
    else if (v == 4 && bs == 4) { f = fopen("Calc.txt", "w"); fprintf(f, "%d", reg); fclose(f); }
    else if (v == 6 && bs == 6) { f = fopen("solve.txt", "w"); fprintf(f, "%d", reg); fclose(f); }
    else if (v == 7 && bs == 7) { f = fopen("quad_solve.txt", "w"); fprintf(f, "%d", reg); fclose(f); }
    else if (v == 8 && bs == 8) { f = fopen("ATC.txt", "w"); fprintf(f, "%d", reg); fclose(f); }

    system("cls");
    Sleep(2000);
    layout(); logo(); prompt();
}

void activation() // Common activation for TicTacToe and Quiz
{
    gotoxy(1, 1);
    layout();
    gotoxy(5, 8);
    reg = 1;
    printf("Enter product key(10 characters): ");

    char key[11]; // 10 characters + null terminator
    scanf("%10s", key);

    if (v == 1) // TicTacToe
    {
        if ((key[6] + key[0]) == (key[9] + key[5]))
        {
            gotoxy(5, 10);
            printf("Verified\n");
            getchar(); getchar();

            FILE* k = fopen("file3.txt", "w");
            if (k != NULL) { fprintf(k, "%s", key); fclose(k); }

            FILE* t = fopen("TicTacToe.txt", "w");
            if (t != NULL) { fprintf(t, "%d", reg); fclose(t); }

            prompt();
        }
        else
        {
            gotoxy(5, 10);
            printf("Invalid key\n");
            getchar(); getchar();
            prompt();
        }
    }
    else if (v == 2) // Quiz
    {
        if ((key[7] + key[8]) == (key[2] + key[9]))
        {
            gotoxy(5, 10);
            printf("Verified\n");
            getchar(); getchar();

            FILE* k = fopen("file6.txt", "w");
            if (k != NULL) { fprintf(k, "%s", key); fclose(k); }

            FILE* t = fopen("Quiz.txt", "w");
            if (t != NULL) { fprintf(t, "%d", reg); fclose(t); }

            prompt();
        }
        else
        {
            gotoxy(5, 10);
            printf("Invalid key\n");
            getchar(); getchar();
            prompt();
        }
    }
}

//Bootscreens
void bootscreen()
{
    system("cls");
    gotoxy(1, 1);
    layout();
    printf("%s%s", green, bold);

    if (bs == 1)
    {
        gotoxy(20, 8);
        printf("\t\t\t\t\t      %sTIC TAC TOE%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s\t\t\t\t\t  Version:4.0%s", yellow, cc);
        state = 0;
    }
    else if (bs == 0)
    {
        layout();
        logo();
        state = 1;
    }
    else if (bs == 2)
    {
        gotoxy(20, 8);
        printf("    \t\t\t\t\t   %sQUIZ__APP%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s\t\t\t\t\t   Version:10.8%s", yellow, cc);
        state = 0;
    }
    else if (bs == 3)
    {
        gotoxy(20, 8);
        printf("%s\t\t\t\t\t\tTEMP_CONV%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s\t\t\t\t\t      Version:4.05%s", yellow, cc);
        state = 0;
    }
    else if (bs == 4)
    {
        gotoxy(20, 8);
        printf("%s\t\t\t\t\t\tCALCULATOR%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s\t\t\t\t\t      Version:3.05%s", yellow, cc);
        state = 0;
    }
    else if (bs == 6)
    {
        gotoxy(60, 8);
        printf("%sPair_of_eqn_solve%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(17, 9);
        printf("%s\t\t\t\t\t  Version:4.05%s", yellow, cc);
        state = 0;
    }
    else if (bs == 7)
    {
        gotoxy(60, 8);
        printf("%sQuadratic_eqn_solve%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s\t\t\t\t\t      Version:1.05%s", yellow, cc);
    }
    else if (bs == 8)
    {
        gotoxy(60, 8);
        printf("%sArea_Of_Triangle(CO)%s", UNDERLINE, CLOSEUNDERLINE);
        gotoxy(20, 9);
        printf("%s\t\t\t\t\t      Version:1.00%s", yellow, cc);
    }

    printf("%s%s", cc, cc);
    gotoxy(17, 18);
    printf("%s\t\t\t\t\t     Please_Wait.%s", cyan, cc);
    gotoxy(17, 19);
    printf("%s\t\t\t\t\t     LOADING......%s", yellow, cc);

    progressbar();
    gotoxy(53, 16);
    printf("                                                         ");
}

int printerror() // To avoid errors in marks counting
{
    gotoxy(1, 1);
    layout();
    printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
    gotoxy(5, 10);
    printf("%s\t\t\t\tAn Unexpected error occured due to invalid input%s\t\t", red, cc);
    gotoxy(5, 11);
    printf("%s\nThe program is restarting. Press Enter%s\t\t", blue, cc);
    getchar(); getchar();
    prompt();
    return 0;
}

void logo()
{
    gotoxy(5, 10); printf("%s ======================== %s%s", RED, bold, cc);
    gotoxy(5, 11); printf("%s|%s   --------    -------%s  |%s%s", RED, blue, RED, cc, cc);
    gotoxy(5, 12); printf("%s|%s  |        |  |       %s  |%s%s", RED, blue, RED, cc, cc);
    gotoxy(5, 13); printf("%s|%s  |        |  |       %s  |%s%s", RED, blue, RED, cc, cc);
    gotoxy(5, 14); printf("%s|%s  |        |   ====== %s  |%s%s", RED, yellow, RED, cc, cc);
    gotoxy(5, 15); printf("%s|%s  |        |  |       %s  |%s%s", RED, yellow, RED, cc, cc);
    gotoxy(5, 16); printf("%s|%s  |        |  |       %s  |%s%s", RED, green, RED, cc, cc);
    gotoxy(5, 17); printf("%s|%s   --------    -------%s  |%s%s", RED, green, RED, cc, cc);
    gotoxy(5, 18); printf("%s ======================== %s%s", RED, cc, cc);
}

// Password Change Wizard
void password_change() {
    gotoxy(1, 1);
    layout();
    gotoxy(5, 7); printf("Welcome to password changing wizard Ver 1.7.9\n");
    gotoxy(5, 8); printf("Enter Following details:\n");

    char name[50], password[50], passnew[50], storedName[100], storedPass[100];

    gotoxy(5, 9); printf("User-ID: ");
    scanf("%49s", name);

    // Read stored name from file
    FILE* file1 = fopen("file.txt", "r");
    if (file1 == NULL) {
        printf("Error opening file\n");
        return;
    }
    fscanf(file1, "%99s", storedName);
    fclose(file1);

    if (strcmp(storedName, name) == 0) {
        // Open password file
        FILE* file2 = fopen("file2.txt", "r");
        char pc;
        if (file2 != NULL) {
            // Password file exists
            fclose(file2);
            gotoxy(5, 10);
            printf("Do you wish to keep a Password? (y/n): ");
            scanf(" %c", &pc);

            if (pc == 'y') {
                gotoxy(5, 11);
                printf("Enter your last Password (if none, type 0): ");
                scanf("%49s", password);

                // Read stored password
                file2 = fopen("file2.txt", "r");
                if (file2 != NULL) {
                    fscanf(file2, "%99s", storedPass);
                    fclose(file2);

                    if (strcmp(storedPass, password) == 0) {
                        gotoxy(5, 12);
                        printf("Enter new password: ");
                        scanf("%49s", passnew);

                        if (strcmp(passnew, "0") == 0) {
                            gotoxy(5, 16);
                            printf("The password cannot be 0\n");
                            printf("\a"); // beep
                            gotoxy(5, 17);
                            printf("Press Enter to restart password_change wizard.\n");
                            getchar(); getchar();
                            password_change(); // restart
                        }
                        else {
                            // Write new password
                            file2 = fopen("file2.txt", "w");
                            if (file2 != NULL) {
                                fprintf(file2, "%s", passnew);
                                fclose(file2);
                            }
                            gotoxy(5, 13);
                            printf("Your password has been changed\n");
                            getchar();
                            system("cls");
                        }
                    }
                    else {
                        timerS(); // Intruder
                    }
                }
            }
            else {
                // Remove password
                gotoxy(5, 13);
                printf("Your password has been removed\n");
                getchar(); getchar();
                file2 = fopen("file2.txt", "w");
                if (file2 != NULL) {
                    fprintf(file2, "0");
                    fclose(file2);
                }
            }
        }
        else {
            // Password file does not exist
            char pass[50];
            file2 = fopen("file2.txt", "w");
            if (file2 != NULL) {
                gotoxy(5, 10);
                printf("Enter password: ");
                scanf("%49s", pass);
                fprintf(file2, "%s", pass);
                fclose(file2);
                gotoxy(5, 12);
                printf("Your password has been changed\n");
                getchar();
            }
        }
        settings();
    }
    else {
        timerS(); // Intruder
    }
}
// Shutdown Timer
int timerS()
{
    int a = 10;
    printf("%s", bold);
    gotoxy(40, 20); printf("ACCESS DENIED");
    gotoxy(40, 21); printf("Invalid Password.");

    while (a >= 0)
    {
        printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a"); fflush(stdout);
        gotoxy(70, 12); printf("TIME UNTIL SHUTDOWN: %2d sec(s)\n", a);
        Sleep(1000);
        a--;
        if (a == -1) exit(0);
    }
    return 0;
}
void userid_change() {
    system("cls");
    layout();

    char nnn[50];

    gotoxy(5, 10);
    printf("Welcome to USER-ID Changing Wizard Ver 1.0.\n");
    gotoxy(5, 11);
    printf("FOLLOW THE ONSCREEN INSTRUCTIONS TO CHANGE THE USER-ID\n");
    gotoxy(5, 12);
    printf("Enter New USER-ID: ");
    scanf("%49s", nnn);

    // Write new USER-ID to file
    FILE* f1 = fopen("file.txt", "w");
    if (f1 != NULL) {
        fprintf(f1, "%s", nnn);
        fclose(f1);
    }
    else {
        printf("Error opening file for writing.\n");
        return;
    }

    gotoxy(5, 17);
    printf("Your USER-ID has been changed. Re-login to see the effect, press enter.\n");
    getchar(); getchar();
    system("cls");
    gotoxy(1, 1);
    layout();
    login();
}

void settings()
{
    system("cls"); layout();

    char choice[20];
    gotoxy(5, 7); printf("%s%sWelcome to the Settings!!%s", red, bold, cc);
    gotoxy(5, 8); printf("%sAvailable sub-categories: %s", yellow, cc);
    gotoxy(5, 10); printf("%s1.) USER ACCOUNTS", green);
    gotoxy(5, 11); printf("2.) RESET AND RESTORE");
    gotoxy(5, 12); printf("3.) Personalization");
    gotoxy(5, 13); printf("4.) HELP");
    gotoxy(5, 14); printf("5.) EXIT%s", cc);
        gotoxy(5, 15); printf("%sEnter choice(1-5): %s", blue, cc);
    scanf("%19s", choice);
   
    if (strcmp(choice, "1") == 0)
        USER_ACCOUNTS();
    else if (strcmp(choice, "2") == 0)
        RESET_AND_RESTORE();
    else if (strcmp(choice, "3") == 0)
        PERSONALIZATION();
    else if (strcmp(choice, "5") == 0)
    {
        gotoxy(1, 1); system("cls"); layout(); prompt();
    }
    else if (strcmp(choice, "7") == 0)
        color_change();
    else if (strcmp(choice, "4") == 0)
    {
        gotoxy(5, 17); printf("%sWelcome to Help Documentation Ver: 1.0 %s", green, bold);
        gotoxy(5, 18); printf("%s1.) Press 1 to change/delete/apply new password or to change USER_ID for your account.", cc);
        gotoxy(5, 19); printf("2.) Press 2 to reset or restore your account.");
        gotoxy(5, 20); printf("3.) Press 3 to personalize your account by Changing colors.");
        gotoxy(5, 21); printf("4.) Press 5 to exit settings.");
        getchar(); getchar();
    }
    else if (strcmp(choice, "user_add") == 0)
        add_user();
    else
    {
        gotoxy(5, 25); printf("%sNo suitable record found%s\a\a\a\a\a\a\a\a\a\a\a", red, bold);
        getchar(); getchar();
        settings();
    }

    gotoxy(5, 30); printf("%sSuccessfully completed the command%s", blue, bold);
    getchar();
    settings();
}
