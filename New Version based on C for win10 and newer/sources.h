//c implemented

void quad_eqn_solve(void);           // Quadratic Eqn solver
void printrndone(void);
int timerS();                     // Shutdown timer
void logo(void);
void color_change(void);
void show_board();                // Board show function
void get_x_player_choice();       // Player X choice
void get_o_player_choice();       // Player O choice
void get_computer_choice_e();
void get_computer_choice_h();
int count_board(char symbol);
char check_winner();              // Check winner
void computer_vs_player();
void player_vs_player();
void selector_t();
void prompt();
void layout();
void install();
void password_change();
int source();
void scr();
void USER_ACCOUNTS();
void PERSONALIZATION();
void RESET_AND_RESTORE();
void IP();
void add_user();
int timerO();
int timerB();
void login();
//int loading();
int start();
int about();
int cheatcode();
int evaluator();
void reg_edit();
void bootscreen();
void userid_change();
void tc();
void activation();

// Global variables
int ap, reg, v, ins, bs, mode;
char choice[20];
double A1, A2, Bi1, Bi2, C1, C2, x, y, m, n;
char C, A_1, cho;
int state;
char a[10], filename[50], name1[50], password1[50], password[50];
char board[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
char Difficult[20];

void gotoxy(int x,int y)// declaring the cursor position 
{
    printf("%c[%d;%df",0x1B,y,x);
}
//Progress_BAR
void progressbar() {
    srand(time(NULL)); // seed random
    for (int progress = 0; progress != 100; progress += rand() % 20) {
        if (state == 1) {
            gotoxy(55, 22);
        }
        else {
            gotoxy(55, 22);
        }

        // delete in final: temp fix to stop at 25
        if (progress > 25) progress = 25;

        printf("\x1B[32m[\033[0m\x1B[34m");
        for (int i = 0; i < 25; i++) {
            if (i < progress)
                printf("-");
            else if (i == progress)
                printf("_");
            else
                printf(" ");
        }
        printf("\033[0m\x1B[32m]\033[0m ");
        fflush(stdout);

        // sleep
#ifdef _WIN32
        Sleep(500);
#else
        usleep(500000); // 500ms
#endif

        if (progress == 25) break; // delete in final
    }

    printf("\n");
    gotoxy(55, 22);
    printf("                                                        ");
}

int source() // Source Viewer function
{
    int c; // must be int, not char
    FILE* fp = fopen(__FILE__, "r");
    if (fp == NULL) {
        printf("Error: could not open source file.\n");
        return 1;
    }

    while ((c = fgetc(fp)) != EOF) {
        putchar(c);
    }

    fclose(fp);
    return 0;
}

void Improvements() // Improvements and Bugs
{
    system("cls");
    gotoxy(1, 2);
    layout();

    gotoxy(5, 7);
    printf("%s%s%sNew Improvements and Bug Fixes:%s", bold, RED, UNDERLINE, cc);

    gotoxy(5, 9);
    printf("%s%si.)Change in programming%s", bold, blue, cc);

    gotoxy(5, 10);
    printf("%s%sii.)New app Quadratic Eqn solver%s", bold, yellow, cc);

    gotoxy(5, 11);
    printf("%s%siii.)Quad Eqn solver can determine nature of roots%s", bold, blue, cc);

    gotoxy(5, 12);
    printf("%s%siv.)Added trial for quiz in registry editor by changing registry values.%s", bold, yellow, cc);

    gotoxy(5, 13);
    printf("%s%sv.)Introduction of a brand new UI%s", bold, blue, cc);

    gotoxy(5, 14);
    printf("%s%svi.)Introduction of settings application%s", bold, red, cc);

    gotoxy(5, 15);
    printf("%s%svii.)Parts of Registry Editor are accessible by normal user. Command : registryeditor.%s", bold, yellow, cc);

    gotoxy(5, 16);
    printf("%s%sviii.)Now you can change your User-ID%s", bold, blue, cc);

    gotoxy(5, 17);
    printf("%s%siX.)Password can be removed later via the settings application.%s", bold, yellow, cc);

    gotoxy(5, 18);
    printf("%s%sx.)Option for system restore by reinstallation to solve several errors.%s", bold, blue, cc);

    gotoxy(5, 19);
    printf("%s%sxi.)Added support for Kelvin in Temperature Converter.%s", bold, yellow, cc);

    gotoxy(5, 20);
    printf("%s%sxii.)One can directly move into the prompt menu from registry editor.%s", bold, blue, cc);

    gotoxy(5, 21);
    printf("%s%sNext version coming with more features%s", bold, green, cc);

    getchar();
}
void login() // Latest Login function
{
    FILE* file;
    char filename[100] = "file.txt";

    logo();

    file = fopen(filename, "r");
    if (file != NULL) // If User Exists
    {
        gotoxy(4, 9);
        reg_status = 1;
        printf("  To begin press enter or type password(if you have created a User-ID).");

        gotoxy(40, 12);
        printf("User-ID:");

        FILE* file1 = fopen("file.txt", "r");
        if (file1 != NULL) {
            fscanf(file1, "%s", name1);
            fclose(file1);
        }
        printf(" %s", name1);

        FILE* file2 = fopen("file2.txt", "r");
        if (file2 != NULL) {
            fscanf(file2, "%s", password1);
            fclose(file2);
        }

        if (strcmp(password1, "0") == 0) // if password is removed
        {
            getchar();
            prompt();
        }
        else
        {
            gotoxy(40, 13);
            printf("Password:");
            printf("%s", invisible); // hide input
            scanf("%s", password);
            printf("%s", cc); // reset formatting

            if (strcmp(password1, password) == 0)
                prompt();
            else if (strcmp(password, "registryeditor") == 0)
                reg_edit();
            else if (strcmp(password, "guess_it") == 0)
                source();
            else
                timerS();
        }
    }
    else // For Guest User
    {
        gotoxy(5, 9);
        reg_status = 1;
        printf(" /* To just test the program (*with limited features) press enter */ ");

        gotoxy(40, 13);
        printf("USER-ID: GUEST");
        printf(" \x1B[36m ");

        getchar();
        getchar();
        system("cls");
        ins = 9;
        reg_status = 0;
        prompt();
    }
}

void layout() // main looks the floating form design
{
    system("cls");
    gotoxy(1, 1);
    printf("%s", cc);

    // Top border
    printf("  %s                                                                                                                                  %s\n", border, cc);

    // Header rows
    printf("  %s %s                                                                                                                                %s %s\n", border, cc, border, cc);
    printf("  %s %s  \t\t\t\t\t\t\t  %s%s%sOperating Environment%s                                                    %s %s\n",
        border, cc, RED, bold, UNDERLINE, CLOSEUNDERLINE, border, cc);
    printf("  %s %s  \t\t\t\t\t                    %s%s%s  Version:4.12  %s%s%s                                                       %s %s\n",
        border, cc, blue, bold, UNDERLINE, CLOSEUNDERLINE, cc, cc, border, cc);
    printf("  %s %s                                                        %s%s(EVALUATION_BUILD)%s                                                      %s %s\n",
        border, cc, yellow, bold, cc, border, cc);

    // Middle empty rows (loop)
    for (int i = 0; i < 30; i++) {
        printf("  %s %s                                                                                                                                %s %s\n", border, cc, border, cc);
    }

    // Bottom border
    printf("  %s                                                                                                                                  %s\n", border, cc);

    gotoxy(1, 1);
}

void add_user() // User Creation menu
{
    system("cls");
    layout();

    char id[100], c[10], pass[100];

    gotoxy(5, 10);
    printf("%s%s%sWelcome to USER-ID Password Creation Wizard Ver: 1.7.9%s",
        UNDERLINE, RED, bold, cc);

    gotoxy(5, 11);
    printf("FOLLOW THE ONSCREEN INSTRUCTIONS TO CREATE A USER");

    gotoxy(5, 12);
    printf("%sPlease create a user id password for safety reasons:%s", yellow, cc);

    gotoxy(5, 13);
    printf("User-Id: ");
    scanf("%99s", id);

    gotoxy(5, 14);
    printf("Do you want to create a password(y/n): ");
    scanf("%9s", c);

    if (strcmp(c, "y") == 0 || strcmp(c, "Y") == 0) // If password is to be created
    {
        FILE* f1 = fopen("file.txt", "w");
        if (f1) {
            fprintf(f1, "%s", id);
            fclose(f1);
        }

        while (1) // Loop until valid password is entered
        {
            gotoxy(5, 15);
            printf("Enter password: ");
            scanf("%99s", pass);

            if (strcmp(pass, "0") == 0) // Invalid password
            {
                gotoxy(5, 16);
                printf("%s%sThe password cannot be 0%s", RED, bold, cc);
                printf("\a\a\a\a\a\a\a\a\a\a\a\a\a\a");
                gotoxy(5, 17);
                printf("%s%sPress Enter to try again.%s", blue, bold, cc);
                getchar(); getchar();
                continue; // abar loop cholbe
            }
            else // Password is valid
            {
                FILE* f2 = fopen("file2.txt", "w");
                if (f2) {
                    fprintf(f2, "%s", pass);
                    fclose(f2);
                }
                break;
            }
        }
    }
    else
    {
        strcpy(pass, "0"); // Storing password as zero in a file

        FILE* f1 = fopen("file.txt", "w");
        if (f1) {
            fprintf(f1, "%s", id);
            fclose(f1);
        }

        FILE* f2 = fopen("file2.txt", "w");
        if (f2) {
            fprintf(f2, "%s", pass);
            fclose(f2);
        }
    }

    gotoxy(5, 16);
    printf("%s%sYou are Successful in creating a user.%s", RED, bold, cc);

    getchar();
    getchar();
}

void install() // Installer for setting Reg_Values
{
    const char* files[] = {
        "TicTacToe.txt",
        "Quiz.txt",
        "TC.txt",
        "Calc.txt",
        "solve.txt",
        "quad_solve.txt"
    };

    for (int i = 0; i < 6; i++)
    {
        FILE* f = fopen(files[i], "w");
        if (f != NULL) {
            fprintf(f, "%d", reg);
            fclose(f);
        }
    }
}
void color_change() {
    system("cls"); gotoxy(1, 1); layout(); gotoxy(5, 8);
    printf(UNDERLINE RED bold "Welcome to background border color changer wizard." cc "\n");
    gotoxy(5, 9);
    printf(yellow bold "Available options:" cc "\n");
    gotoxy(5, 10); printf(" -------------------------------------------\n");
    gotoxy(5, 11);
    printf("|    " green bold "COLOR_NAME" cc "       |        " green bold "SAMPLE" cc "       |\n");
    gotoxy(5, 12); printf("|" bold blue " 1.) Red            " cc " |          %s  " cc "         |\n", B1);
    gotoxy(5, 13); printf("|" bold blue " 2.) Green          " cc " |          %s  " cc "         |\n", B2);
    gotoxy(5, 14); printf("|" bold blue " 3.) Yellow         " cc " |          %s  " cc "         |\n", B3);
    gotoxy(5, 15); printf("|" bold blue " 4.) Blue           " cc " |          %s  " cc "         |\n", B4);
    gotoxy(5, 16); printf("|" bold blue " 5.) Purple         " cc " |          %s  " cc "         |\n", B5);
    gotoxy(5, 17); printf("|" bold blue " 6.) Cyan           " cc " |          %s  " cc "         |\n", B6);
    gotoxy(5, 18); printf("|" bold blue " 7.) Light grey     " cc " |          %s  " cc "         |\n", B7);
    gotoxy(5, 19); printf("|" bold blue " 8.) Grey           " cc " |          %s  " cc "         |\n", B8);
    gotoxy(5, 20); printf("|" bold blue " 9.) Light Red      " cc " |          %s  " cc "         |\n", B9);
    gotoxy(5, 21); printf("|" bold blue " 10.) Light Green   " cc " |          %s  " cc "         |\n", B10);
    gotoxy(5, 22); printf("|" bold blue " 11.) Light Yellow  " cc " |          %s  " cc "         |\n", B11);
    gotoxy(5, 23); printf("|" bold blue " 12.) Light Blue    " cc " |          %s  " cc "         |\n", B12);
    gotoxy(5, 24); printf("|" bold blue " 13.) Light Purple  " cc " |          %s  " cc "         |\n", B13);
    gotoxy(5, 25); printf("|" bold blue " 14.) Light Cyan    " cc " |          %s  " cc "         |\n", B14);
    gotoxy(5, 26); printf("|" bold blue " 15.) White         " cc " |          %s  " cc "         |\n", B15);
    gotoxy(5, 27); printf("|" bold blue " 16.) Blank         " cc " |           " cc "          |\n");
    gotoxy(5, 28); printf(" -------------------------------------------\n");
    gotoxy(5, 29); printf(purple bold "Enter choice (To exit press e): " cc);

    char colorr[10];
    scanf("%9s", colorr);

    if (strcmp(colorr, "1") == 0 || strcmp(colorr, "2") == 0 || strcmp(colorr, "3") == 0 || strcmp(colorr, "4") == 0 ||
        strcmp(colorr, "5") == 0 || strcmp(colorr, "6") == 0 || strcmp(colorr, "7") == 0 || strcmp(colorr, "8") == 0 ||
        strcmp(colorr, "9") == 0 || strcmp(colorr, "10") == 0 || strcmp(colorr, "11") == 0 || strcmp(colorr, "12") == 0 ||
        strcmp(colorr, "13") == 0 || strcmp(colorr, "14") == 0 || strcmp(colorr, "15") == 0 || strcmp(colorr, "16") == 0)
    {
        FILE* color = fopen("looks.h", "w");
        if (strcmp(colorr, "1") == 0) fprintf(color, "#define border \"\\x1B[41m\"");
        else if (strcmp(colorr, "2") == 0) fprintf(color, "#define border \"\\x1B[42m\"");
        else if (strcmp(colorr, "3") == 0) fprintf(color, "#define border \"\\x1B[43m\"");
        else if (strcmp(colorr, "4") == 0) fprintf(color, "#define border \"\\x1B[44m\"");
        else if (strcmp(colorr, "5") == 0) fprintf(color, "#define border \"\\x1B[45m\"");
        else if (strcmp(colorr, "6") == 0) fprintf(color, "#define border \"\\x1B[46m\"");
        else if (strcmp(colorr, "7") == 0) fprintf(color, "#define border \"\\x1B[47m\"");
        else if (strcmp(colorr, "8") == 0) fprintf(color, "#define border \"\\x1B[100m\"");
        else if (strcmp(colorr, "9") == 0) fprintf(color, "#define border \"\\x1B[101m\"");
        else if (strcmp(colorr, "10") == 0) fprintf(color, "#define border \"\\x1B[102m\"");
        else if (strcmp(colorr, "11") == 0) fprintf(color, "#define border \"\\x1B[103m\"");
        else if (strcmp(colorr, "12") == 0) fprintf(color, "#define border \"\\x1B[104m\"");
        else if (strcmp(colorr, "13") == 0) fprintf(color, "#define border \"\\x1B[105m\"");
        else if (strcmp(colorr, "14") == 0) fprintf(color, "#define border \"\\x1B[106m\"");
        else if (strcmp(colorr, "15") == 0) fprintf(color, "#define border \"\\x1B[107m\"");
        else if (strcmp(colorr, "16") == 0) fprintf(color, "#define border \"\\x1B[99m\"");
        fclose(color);

        printf("\a\a\a\a"); fflush(stdout);
        gotoxy(30, 10); system("cls");
        printf(RED bold "Program is shutting down to save the changes. Restart to see the effect!!!" cc "\n");
        Sleep(1000);
        exit(0);
    }
    else if (strcmp(colorr, "e") == 0) settings();
    else {
        gotoxy(5, 30); printf("No command.\n");
        getchar(); getchar();
        color_change();
    }
}

void USER_ACCOUNTS() {
    system("cls"); gotoxy(1, 1); layout(); gotoxy(5, 8);
    printf(UNDERLINE RED bold "Welcome to User Account Control Panel:" cc "\n");
    gotoxy(5, 9); printf(yellow bold "Pick a task: \n");
    gotoxy(5, 10); printf(green bold "1.) Add /Remove /Create Password for your accounts\n");
    gotoxy(5, 11); printf("2.) Change Your User_ID.\n");
    gotoxy(5, 12); printf("3.) EXIT.\n");
    gotoxy(5, 13); printf(bold blue "Enter choice(1-3): " cc);
    scanf("%9s", choice);

    if (strcmp(choice, "1") == 0) password_change();
    else if (strcmp(choice, "2") == 0) userid_change();
    else if (strcmp(choice, "3") == 0) settings();
    else {
        gotoxy(5, 25); printf(RED bold "No suitable record found\a\a\a\a\a\a\a\a\a\a\a\n" cc);
        getchar(); getchar(); USER_ACCOUNTS();
    }
    getchar(); getchar(); USER_ACCOUNTS();
}

void RESET_AND_RESTORE() {
    system("cls"); gotoxy(1, 1); layout(); gotoxy(5, 8);
    printf(UNDERLINE RED bold "Welcome to Reset and Restore Panel:" cc "\n");
    gotoxy(5, 9); printf(yellow bold "Pick a task: \n");
    gotoxy(5, 10); printf(blue bold "1.) Reset your applications\n");
    gotoxy(5, 11); printf("2.) Restore your system by re-installing it.\n");
    gotoxy(5, 12); printf("3.) EXIT.\n");
    gotoxy(5, 13); printf(RED bold "Warning!! Any of the above task(command) will reset all your applications thus delete /alter data.\n");
    gotoxy(5, 14); printf(green bold "Do you want to continue(y/n)? ");
    scanf("%9s", a);

    if (strcmp(a, "y") == 0 || strcmp(a, "Y") == 0) {
        gotoxy(5, 15); printf(green bold "Enter choice(1-3): " cc);
        scanf("%9s", choice);
        if (strcmp(choice, "1") == 0) { reg_status = 0; install(); }
        else if (strcmp(choice, "2") == 0) IP();
        else if (strcmp(choice, "3") == 0) settings();
        else {
            gotoxy(5, 25); printf(RED bold "No suitable record found\a\a\a\a\a\a\a\a\a\a\a\n" cc);
            getchar(); getchar(); RESET_AND_RESTORE();
        }
        getchar(); getchar(); RESET_AND_RESTORE();
    }
    else settings();
}

void PERSONALIZATION() {
    system("cls"); gotoxy(1, 1); layout(); gotoxy(5, 8);
    printf(red UNDERLINE bold "Welcome to Personalization Panel:" cc "\n");
    gotoxy(5, 9); printf(yellow bold "Pick a task: \n");
    gotoxy(5, 10); printf(green bold "1.) Change your border color.\n");
    gotoxy(5, 11); printf("2.) EXIT.\n");
    gotoxy(5, 12); printf(blue bold "Enter choice(1-2): " cc);
    scanf("%9s", choice);

    if (strcmp(choice, "1") == 0) color_change();
    else if (strcmp(choice, "2") == 0) settings();
    else {
        gotoxy(5, 25); printf(RED bold "No suitable record found\a\a\a\a\a\a\a\a\a\a\a\n" cc);
        getchar(); getchar(); PERSONALIZATION();
    }
}
