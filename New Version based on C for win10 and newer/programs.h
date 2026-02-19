// EQN SOLVER

//c implemented

void solve() //To solve the equations using cross multiplication method
{
    x = ((Bi1 * C2) - (Bi2 * C1)) / n;
    y = ((A2 * C1) - (A1 * C2)) / n;

    gotoxy(5, 28); printf("Required equations after suitable arrangement are:");

    if (C == 'y' && A_1 == 'n')
    {
        C1 = C1 * 1;
        C2 = C2 * 1;
    }
    else if (C == 'y' && A_1 == 'y')
    {
        C1 = C1 * -1;
        C2 = C2 * -1;
    }
    else if (C == 'n' && cho == 'y')
    {
        C1 = C1 * -1;
        C2 = C2 * -1;
    }
    else if (C == 'n' && cho == 'n')
    {
        C1 = C1 * -1;
        C2 = C2 * -1;
    }
    else
    {
        printf("\nPart of your input is invalid.\n");
        printf("The program will stop.\n");
    }

    gotoxy(5, 29); printf("(%lf)x + (%lf)y + (%lf) = 0\n", A1, Bi1, C1);
    gotoxy(5, 30); printf("(%lf)x + (%lf)y + (%lf) = 0\n", A2, Bi2, C2);
    gotoxy(5, 31); printf("X = %lf and Y = %lf\n", x, y);
    gotoxy(5, 32); printf("They represent equations with unique solution intersecting at a point on graph.%s%s", cc, cc);
}

void get_Side() //to get the side of constant terms
{
    gotoxy(5, 26); printf("Are all the constant terms in same side?(y/n) ");
    scanf(" %c", &C);

    if (C == 'y')
    {
        gotoxy(5, 27); printf("Are the constant terms alone in one side?(y/n) ");
        scanf(" %c", &A_1);

        if (A_1 == 'y')
        {
            m = -1; n = n * m;
            solve();
        }
        else if (A_1 == 'n')
        {
            m = 1; n = n * m;
            solve();
        }
    }
    else if (C == 'n')
    {
        gotoxy(5, 27); printf("Is C1 alone in one side(y/n): ");
        scanf(" %c", &cho);

        if (cho == 'y')
        {
            m = -1; n = n * m;
            C2 = C2 * -1;
        }
        else if (cho == 'n')
        {
            m = -1; n = n * m;
            C1 = C1 * -1;
        }

        solve();
    }
}

void get_Eqn() //to get the equation
{
    system("cls"); gotoxy(1, 1); layout();

    gotoxy(5, 6); printf("%s%s/*IT MUST BE NOTED THAT ALL THE X,Y and constant terms must be numbers*/%s\n", yellow, bold, cc);
    gotoxy(5, 7); printf("%sYour equations may be in the form of:%s", blue, cc);
    gotoxy(5, 8); printf("a1x + b1y + c1 = 0");
    gotoxy(5, 9); printf("a2x + b2y + c2 = 0");
    gotoxy(5, 11); printf("a1x + b1y = c1 ");
    gotoxy(5, 12); printf("a2x + b2y = c2 ");
    gotoxy(5, 14); printf("a1x + b1y = c1 ");
    gotoxy(5, 15); printf("a2x + b2y + c2 = 0");
    gotoxy(5, 17); printf("a1x + b1y + c1 = 0");
    gotoxy(5, 18); printf("a2x + b2y = c2 %s%s\n", cc, cc);

    gotoxy(5, 20); printf("%sEnter the value of a1/coefficient of x in first equation:%s", green, cc);
    scanf("%lf", &A1);

    gotoxy(5, 21); printf("%sEnter the value of b1/coefficient of y in first equation:%s", green, cc);
    scanf("%lf", &Bi1);

    gotoxy(5, 22); printf("%sEnter the value of c1/constant in first equation:%s", green, cc);
    scanf("%lf", &C1);

    gotoxy(5, 23); printf("%sEnter the value of a2/coefficient of x in second equation:%s", green, cc);
    scanf("%lf", &A2);

    gotoxy(5, 24); printf("%sEnter the value of b2/coefficient of y in second equation:%s", green, cc);
    scanf("%lf", &Bi2);

    gotoxy(5, 25); printf("%sEnter the value of c2/constant term in second equation:%s", green, cc);
    scanf("%lf", &C2);

    n = ((A1 * Bi2) - (A2 * Bi1));

    if (A1 * Bi2 != A2 * Bi1)
        get_Side();
    else if (A1 / A2 == Bi1 / Bi2 && A1 / A2 == C1 / C2)
    {
        gotoxy(5, 26); printf("Solution can be given only to equations with unique solution.");
        gotoxy(5, 27); printf("Your entered equations have infinitely many solutions and represent coincident lines on graph.");
        getchar();
    }
    else if (A1 / A2 == Bi1 / Bi2 && A1 / A2 != C1 / C2)
    {
        gotoxy(5, 26); printf("Solution can be given only to equations with unique solution.");
        gotoxy(5, 27); printf("Your entered equations have no solutions and represent parallel lines on graph.");
        getchar();
    }
}

//TICTACTOE
//int mode;
int DifficultLevel; // 1 for easy, 2 for hard

void selector_t()
{
    gotoxy(1, 1); layout(); gotoxy(5, 7);
    printf("%s%sSelect Game Mode(1/2).%s%s\n", bold, UNDERLINE, CLOSEUNDERLINE, cc);
    gotoxy(5, 9); printf("\x1B[94m1. Computer VS Player.");
    gotoxy(5, 10); printf("2. Player VS Player.%s\n", CLOSEUNDERLINE);
    gotoxy(5, 11); printf("\x1B[93mENTER YOUR CHOICE: \x1B[96m");
    scanf("%d", &mode);
    printf("%s", cc);

    switch (mode)
    {
    case 1:
    {
        gotoxy(5, 12); printf("%sEnter Game type:%s", RED, cc);
        gotoxy(5, 13); printf("\ta.) Simple.");
        gotoxy(5, 14); printf("\tb.) Difficult.%s", cc);
        gotoxy(5, 15); printf("Enter Your Choice (a/b): ");

        char choice;
        scanf(" %c", &choice);

        if (choice == 'a') DifficultLevel = 1;
        else if (choice == 'b') DifficultLevel = 2;
        else {
            gotoxy(5, 16); printf("%sInvalid choice. Defaulting to Easy.%s", RED, cc);
            DifficultLevel = 1;
        }

        computer_vs_player();
        break;
    }
    case 2:
        player_vs_player();
        break;
    default:
        gotoxy(5, 15); printf("%sPlease Select Valid Game Mode.%s\n", RED, cc);
        Sleep(1000);
        prompt();
    }
}

void get_computer_choice_e() {
    srand(time(0));
    int choice;
    do {
        choice = rand() % 9;
    } while (board[choice] != ' ');
    board[choice] = 'O';
}

void get_computer_choice_h() {
    // First check for winning/blocking moves
    int i, win_combo[8][3] = {
        {0,1,2},{3,4,5},{6,7,8}, // rows
        {0,3,6},{1,4,7},{2,5,8}, // cols
        {0,4,8},{2,4,6}           // diagonals
    };

    for (i = 0; i < 8; i++) {
        int a = win_combo[i][0], b = win_combo[i][1], c = win_combo[i][2];
        // Win for O
        if (board[a] == 'O' && board[b] == 'O' && board[c] == ' ') { board[c] = 'O'; return; }
        if (board[a] == 'O' && board[c] == 'O' && board[b] == ' ') { board[b] = 'O'; return; }
        if (board[b] == 'O' && board[c] == 'O' && board[a] == ' ') { board[a] = 'O'; return; }

        // Block X
        if (board[a] == 'X' && board[b] == 'X' && board[c] == ' ') { board[c] = 'O'; return; }
        if (board[a] == 'X' && board[c] == 'X' && board[b] == ' ') { board[b] = 'O'; return; }
        if (board[b] == 'X' && board[c] == 'X' && board[a] == ' ') { board[a] = 'O'; return; }
    }

    // Take center if free
    if (board[4] == ' ') { board[4] = 'O'; return; }

    // Take corners
    int corners[4] = { 0,2,6,8 };
    for (i = 0; i < 4; i++) {
        if (board[corners[i]] == ' ') { board[corners[i]] = 'O'; return; }
    }

    // Take any side
    int sides[4] = { 1,3,5,7 };
    for (i = 0; i < 4; i++) {
        if (board[sides[i]] == ' ') { board[sides[i]] = 'O'; return; }
    }
}
void get_player_choice(char symbol, char* player_name) {
    while (1) {
        gotoxy(5, 20);
        printf("%s Select Your Position (1-9): ", player_name);
        char input[10];
        scanf("%9s", input);

        if (strcmp(input, "w") == 0) { // cheat
            if (symbol == 'X') {
                board[1] = board[4] = board[7] = board[2] = board[3] = 'X';
                board[0] = board[6] = board[8] = board[5] = 'O';
            }
            else {
                board[1] = board[4] = board[7] = board[2] = board[3] = 'O';
                board[0] = board[6] = board[8] = board[5] = 'X';
            }
            system("cls");
            show_board();
            gotoxy(5, 17);
            printf("You win! Other player lost the game");
            getchar(); getchar();
            exit(0);
        }

        int choice = atoi(input) - 1; // convert to 0-based index
        if (choice < 0 || choice > 8) {
            gotoxy(5, 21);
            printf("Please Select Your Choice From (1-9).\n");
        }
        else if (board[choice] != ' ') {
            gotoxy(5, 21);
            printf("Please Select An Empty Position.\n");
        }
        else {
            board[choice] = symbol;
            break;
        }
    }
}
void computer_vs_player() {
    char player_name[50];
    gotoxy(1, 1);
    layout();

    gotoxy(5, 7);
    printf("%s%sPlease fill in the following details:%s", red, bold, CLOSEUNDERLINE);

    gotoxy(5, 8);
    printf("%sEnter Your Name: %s", yellow, CLOSEUNDERLINE);
    scanf("%s", player_name);

    while (1) {
        system("cls");
        show_board();

        if (count_board('X') == count_board('O')) {
            gotoxy(5, 22);
            printf("%s's Turn.\n", player_name);
            get_x_player_choice();
        }
        else {
            if (strcmp(Difficult, "1") == 0)
                get_computer_choice_e();
            else if (strcmp(Difficult, "2") == 0)
                get_computer_choice_h();
        }

        char winner = check_winner();
        if (winner == 'X') {
            system("cls");
            show_board();
            gotoxy(5, 22);
            printf("%s Won The Game.\n", player_name);
            getchar();
            break;
        }
        else if (winner == 'O') {
            system("cls");
            show_board();
            gotoxy(5, 22);
            printf("Computer Won The Game.\n");
            getchar();
            break;
        }
        else if (winner == 'D') {
            system("cls");
            show_board();
            gotoxy(5, 22);
            printf("Game is Draw.\n");
            getchar();
            break;
        }
    }

    getchar();
    system("cls");
    printf("\nThe program is shutting down to prevent any file corruption.");
    exit(0);
}
void get_x_player_choice() {
    while (1) {
        gotoxy(5, 20);
        printf("Select Your Position (1 - 9): ");

        long choice_a;
        scanf("%ld", &choice_a);
        choice_a--;

        if ((char)choice_a == 'w') //cheat
        {
            board[1] = board[4] = board[7] = board[2] = board[3] = 'X';
            board[0] = board[6] = board[8] = board[5] = 'O';
            system("cls");
            show_board();
            gotoxy(5, 17);
            printf("You win the game, Computer/player 2 lost the game");
            getchar();
            exit(0);
            break;
        }
        else if (choice_a < 0 || choice_a > 8) {
            gotoxy(5, 21);
            printf("Please Select Your Choice From (1 - 9).\n");
        }
        else if (board[choice_a] != ' ') {
            gotoxy(5, 21);
            printf("Please Select An Empty Position.\n");
        }
        else {
            board[choice_a] = 'X';
            break;
        }
    }
}
void get_o_player_choice() {
    while (1) {
        gotoxy(5, 20);
        printf("Select Your Position (1 - 9): ");

        int choice_b;
        scanf("%d", &choice_b);
        choice_b--;

        if ((char)choice_b == 'w') //cheat
        {
            board[1] = board[4] = board[7] = board[2] = board[3] = 'O';
            board[0] = board[6] = board[8] = board[5] = 'X';
            system("cls");
            show_board();
            gotoxy(5, 20);
            printf("You win the game, player 1 lost the game");
            getchar();
            exit(0);
            break;
        }
        else if (choice_b < 0 || choice_b > 8) {
            gotoxy(5, 21);
            printf("Please Select Your Choice From (1 - 9).\n");
        }
        else if (board[choice_b] != ' ') {
            gotoxy(5, 21);
            printf("Please Select An Empty Position.\n");
        }
        else {
            board[choice_b] = 'O';
            break;
        }
    }
}
void player_vs_player() {
    char x_player_name[50], o_player_name[50];
    gotoxy(1, 1); layout();
    gotoxy(5, 7); printf("%sPlease fill in the following details:%s", RED, cc);
    gotoxy(5, 8); printf("%sEnter X Player Name: %s", yellow, CLOSEUNDERLINE);
    scanf("%49s", x_player_name);
    gotoxy(5, 9); printf("%sEnter O Player Name: %s", yellow, CLOSEUNDERLINE);
    scanf("%49s", o_player_name);

    while (1) {
        system("cls");
        show_board();
        if (count_board('X') == count_board('O')) {
            gotoxy(5, 19);
            printf("%s‘s Turn.\n", x_player_name);
            get_player_choice('X', x_player_name);
        }
        else {
            gotoxy(5, 19);
            printf("%s‘s Turn.\n", o_player_name);
            get_player_choice('O', o_player_name);
        }

        char winner = check_winner();
        if (winner == 'X') {
            system("cls"); show_board();
            gotoxy(5, 23);
            printf("%s Won The Game.\n", x_player_name);
            getchar(); getchar();
            break;
        }
        else if (winner == 'O') {
            system("cls"); show_board();
            gotoxy(5, 23);
            printf("%s Won The Game.\n", o_player_name);
            getchar(); getchar();
            break;
        }
        else if (winner == 'D') {
            gotoxy(5, 23);
            printf("Game is Draw.\n");
            getchar(); getchar();
            break;
        }
    }
    system("cls");
    gotoxy(5, 1);
    printf("%sThe program is shutting down to prevent any file corruption.%s", RED, cc);
    exit(0);
}

int count_board(char symbol) {
    int total = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == symbol) total++;
    }
    return total;
}

char check_winner() {
    // horizontal
    if (board[0] == board[1] && board[1] == board[2] && board[0] != ' ') return board[0];
    if (board[3] == board[4] && board[4] == board[5] && board[3] != ' ') return board[3];
    if (board[6] == board[7] && board[7] == board[8] && board[6] != ' ') return board[6];
    // vertical
    if (board[0] == board[3] && board[3] == board[6] && board[0] != ' ') return board[0];
    if (board[1] == board[4] && board[4] == board[7] && board[1] != ' ') return board[1];
    if (board[2] == board[5] && board[5] == board[8] && board[2] != ' ') return board[2];
    // diagonal
    if (board[0] == board[4] && board[4] == board[8] && board[0] != ' ') return board[0];
    if (board[2] == board[4] && board[4] == board[6] && board[2] != ' ') return board[2];
    if (count_board('X') + count_board('O') < 9) return 'C';
    return 'D';
}

void show_board() {
    layout();
    gotoxy(5, 7);  printf("%s   %s|   %s|   %s", green, " ", " ", cc);
    gotoxy(5, 8);  printf("%s   %c%s|   %c%s|   %c%s", green, board[0], cc, board[1], cc, board[2], cc);
    gotoxy(5, 9);  printf("%s   %s|   %s|   %s", green, " ", " ", cc);
    gotoxy(5, 10); printf("-----------------------");
    gotoxy(5, 11); printf("   %s|   %s|   %s", " ", " ", " ");
    gotoxy(5, 12); printf("   %c%s|   %c%s|   %c%s", board[3], cc, board[4], cc, board[5], cc);
    gotoxy(5, 13); printf("   %s|   %s|   %s", " ", " ", " ");
    gotoxy(5, 14); printf("-----------------------");
    gotoxy(5, 15); printf("   %s|   %s|   %s", " ", " ", " ");
    gotoxy(5, 16); printf("   %c%s|   %c%s|   %c%s", board[6], cc, board[7], cc, board[8], cc);
    gotoxy(5, 17); printf("   %s|   %s|   %s%s", " ", " ", " ", cc);
}

// CALCULATOR
void calc() {
    gotoxy(1, 1); layout();
    gotoxy(5, 7); printf("!!!!!!!!!!!!!!This is a calculator!!!!!!!!!!!!!\n");

    double a, b, c, d, e, f, g;
    char A, B, C;

    gotoxy(5, 11); printf("Enter first number: ");
    scanf("%lf", &a);
    gotoxy(5, 12); printf("Enter first operator: ");
    scanf(" %c", &A);
    gotoxy(5, 13); printf("Enter second number: ");
    scanf("%lf", &b);
    gotoxy(5, 14); printf("Enter second operator: ");
    scanf(" %c", &B);
    gotoxy(5, 15); printf("Enter third number: ");
    scanf("%lf", &c);
    gotoxy(5, 16); printf("Enter third operator: ");
    scanf(" %c", &C);
    gotoxy(5, 17); printf("Enter fourth number: ");
    scanf("%lf", &d);
    gotoxy(5, 17); printf("Expression you entered is: %lf%c%lf%c%lf%c%lf\n", a, A, b, B, c, C);

    switch (A) {
    case '+': e = a + b; break;
    case '-': e = a - b; break;
    case '*': e = a * b; break;
    case '/': e = a / b; break;
    default: gotoxy(5, 21); printf("Invalid input\n"); return;
    }

    switch (B) {
    case '+': f = e + c; break;
    case '-': f = e - c; break;
    case '*': f = e * c; break;
    case '/': f = e / c; break;
    default: gotoxy(5, 21); printf("Invalid input\n"); return;
    }

    switch (C) {
    case '+': g = f + d; break;
    case '-': g = f - d; break;
    case '*': g = f * d; break;
    case '/': g = f / d; break;
    default: gotoxy(5, 21); printf("Invalid input\n"); return;
    }

    gotoxy(5, 21); printf("Result is: %lf\n", g);
    gotoxy(5, 23); printf("\t\t\t<<PRESS ANY KEY TO EXIT>>\n");
    getchar(); getchar();
    prompt();
}

// TEMPERATURE CONVERTER
void tc() {
    system("cls"); gotoxy(1, 1); layout();
    gotoxy(5, 8); printf("%sTEMPERATURE_CONVERTER_PROGRAM_VER: 4.05%s\n", yellow, cc);

    char choice;
    int temp, temp_c;
    gotoxy(5, 9); printf("Enter your desired unit of temperature:(C/F/K): ");
    scanf(" %c", &choice);
    gotoxy(5, 10); printf("Enter temperature (%c): ", choice);
    scanf("%d", &temp);

    if (choice == 'C' || choice == 'c') {
        temp_c = (temp * 1.8) + 32;
        gotoxy(5, 11); printf("Temperature in °F is: %d\n", temp_c);
        gotoxy(5, 12); printf("Temperature in K is: %d\n", temp + 273);
    }
    else if (choice == 'F' || choice == 'f') {
        temp_c = (temp - 32) * 5 / 9;
        gotoxy(5, 11); printf("Temperature in °C is: %d\n", temp_c);
        gotoxy(5, 12); printf("Temperature in K is: %d\n", temp_c + 273);
    }
    else if (choice == 'K' || choice == 'k') {
        temp_c = temp - 273;
        gotoxy(5, 11); printf("Temperature in °C is: %d\n", temp_c);
        temp_c = (temp_c * 1.8) + 32;
        gotoxy(5, 12); printf("Temperature in °F is: %d\n", temp_c);
    }
    else {
        gotoxy(5, 11); printf("%sINVALID INPUT%s\n", red, cc);
    }

    getchar(); getchar();
    prompt();
}

//THE QUIZ (LARGEST)
// GLOBAL VARIABLES
int A, B, a1, a2, a3, a4, b1, b2, b3, b4, bo1, bo2, bo3, bo4, bo5, bo6, bo7, bo8, r;
char p1, o1, p2, o2, p3, o3, p4, o5, p5, o6, p6, o7, o8;

// CHEAT PRINT ERROR FUNCTION
void printerror1() // To avoid any error in marks counting
{
    system("cls");
    gotoxy(5, 8);
    printf("\x1B[31m\t\t\t\tThis cheat code is for entertainment only\033[0m\t\t");
    gotoxy(5, 9);
    printf("\x1B[34m\nPlease restart the program\033[0m\t\t");
    getchar();
    system("cls");
  //
}

// COMMON PRINT FUNCTION FOR AWON / BWON
void print_cheat(char winner, int A_val, int B_val)
{
    A = A_val;
    B = B_val;
    gotoxy(1, 1);
    layout();
    gotoxy(5, 7);    printf("Correct Answers:");
    gotoxy(5, 8);    printf("1.) C");
    gotoxy(5, 9);    printf("2.) A");
    gotoxy(5, 10);   printf("3.) C");
    gotoxy(5, 11);   printf("4.) D");
    gotoxy(5, 12);   printf("5.) B");
    gotoxy(5, 13);   printf("6.) A");
    gotoxy(5, 14);   printf("%c won", winner);
    gotoxy(5, 15);   printf(" A=%d\tB=%d", A, B);
}

// PRINT AWON / BWON USING COMMON FUNCTION
void printawon()
{
    print_cheat('A', 45, 0);
    getchar();
    printerror1();
    
}

void printbwon()
{
    print_cheat('B', 0, 45);
    
}

// SCOREBOARD FUNCTION
void scrbrd()
{
    system("cls");
    layout();
    gotoxy(64, 9);
    printf("Score(Rnd-%d)", r);
    gotoxy(57, 10);
    printf("|______Score Board______|");
    gotoxy(57, 11);
    printf("|_____A_____|_____B_____|");

    gotoxy(57, 12);
    printf("| ");
    printf("%+d  | %+d  | %+d  |", a1, bo2, b1); // simplified sign
    gotoxy(57, 13);
    printf("| %+d  | %+d  | %+d  |", a2, bo4, b2);
    gotoxy(57, 14);
    printf("| %+d  | %+d  | %+d  |", a3, bo6, b3);
    gotoxy(57, 15);
    printf("| %+d  | %+d  | %+d  |", a4, bo8, b4);

    getchar();
    if (r == 4)
    {
        scr();
        {
        }
        //return 0;
    }
}

// FINAL SCORE FUNCTION
void scr()
{
    A = a1 + a2 + a3 + a4 + bo8 + bo6 + bo2 + bo4;
    B = b1 + b2 + b3 + b4 + bo7 + bo5 + bo1 + bo3;

    gotoxy(64, 16);
    if (A > B)
        printf("!!!A won!!!");
    else if (B > A)
        printf("!!!B won!!!");
    else
        printf("!!!!Tie.!!!!");

    gotoxy(62, 17);
    printf(" A=%d\tB=%d", A, B);
    getchar();
    //return 0;
}
void ask_question(char group, int* score, int* bonus, char correct, char bonus_correct) {
    char ans, bonus_ans;
    printf("Your answer: ");
    scanf(" %c", &ans);

    if (ans == correct) {
        *score = 10;
    }
    else if (ans == 'u') {
        *score = 0;
        printf("Do you want bonus round (y/n): ");
        scanf(" %c", &p1);
        if (p1 == 'y') {
            printf("Bonus answer: ");
            scanf(" %c", &bonus_ans);
            *bonus = (bonus_ans == bonus_correct) ? 5 : 0;
        }
    }
    else {
        *score = -5;
        printf("Do you want bonus round (y/n): ");
        scanf(" %c", &p1);
        if (p1 == 'y') {
            printf("Bonus answer: ");
            scanf(" %c", &bonus_ans);
            *bonus = (bonus_ans == bonus_correct) ? 5 : 0;
        }
    }
}

// Round 1
void printrndone() {
    r = 1;
    layout();
    printf("Group: A\n");
    printf("1.) Who was the first propaganda minister of Hitler?\n");
    printf(" a.) James.\n b.) Gary.\n c.) Goebbels.\n d.) Haris.\n");
    ask_question('A', &a1, &bo1, 'c', 'c');

    printf("\nGroup: B\n");
    printf("2.) When French Revolution Started?\n");
    printf(" a.) 1764\n b.) 1665\n c.) 1122\n d.) 1789\n");
    ask_question('B', &b1, &bo2, 'd', 'd');

    scrbrd();
}

// Round 2
void printrndtwo() {
    r = 2;
    layout();
    printf("Group: A\n");
    printf("3.) Conio.h refer to:\n");
    printf(" a.) console in out\n b.) header file\n c.) both a and b\n d.) None\n");
    ask_question('A', &a2, &bo3, 'c', 'c');

    printf("\nGroup: B\n");
    printf("4.) Which king ruled France during 1774?\n");
    printf(" a.) Louis XX\n b.) Louis XVI\n c.) Louis XV\n d.) Louis XIV\n");
    ask_question('B', &b2, &bo4, 'b', 'b');

    scrbrd();
}

// Round 3
void printrndthree() {
    r = 3;
    layout();
    printf("Group: A\n");
    printf("5.) Who discovered e=mc^2?\n");
    printf(" a.) Einstein\n b.) James\n c.) Goebbels\n d.) Haris\n");
    ask_question('A', &a3, &bo5, 'a', 'a');

    printf("\nGroup: B\n");
    printf("6.) Who coined the term protoplasm?\n");
    printf(" a.) Rutherford\n b.) Purkinje\n c.) Brown\n d.) Bohr\n");
    ask_question('B', &b3, &bo6, 'b', 'b');

    scrbrd();
}

// Round 4
void printrndfour() {
    r = 4;
    layout();
    printf("Group: A\n");
    printf("7.) Who discovered neutron?\n");
    printf(" a.) James Chadwick\n b.) Einstein\n c.) Newton\n d.) Haris\n");
    ask_question('A', &a4, &bo7, 'a', 'a');

    printf("\nGroup: B\n");
    printf("8.) Who discovered electron?\n");
    printf(" a.) Purkinje\n b.) J.J. Thompson\n c.) Brown\n d.) Rutherford\n");
    ask_question('B', &b4, &bo8, 'b', 'b');

    scrbrd();
}
int about() {
    gotoxy(1, 1);
    layout();
    gotoxy(5, 8);
    printf("\033[4;34m\nAbout:\033[0m\n");
    printf(" This is quiz app version 10.8 developed by Subhajit Halder\n");
    gotoxy(5, 9);
    printf("       This is console based application.\n");
    gotoxy(5, 10);
    printf("\033[32m\n\n\n\n\n\t\tTo raise a suggestion for the new version please write to subhajithalder327@outlook.com\033[0m\n");
    getchar(); getchar();
    printrndone(); // assume defined elsewhere
    return 0;
}

// evaluator() function
int evaluator() {
    gotoxy(1, 1);
    layout();
    gotoxy(5, 10);
    printf("Evaluated By: Ritabrata Saha\n");
    getchar(); getchar();
    prompt(); // assume defined elsewhere
    return 0;
}

// cheatcode() function
int cheatcode() {
    gotoxy(1, 1);
    layout();
    gotoxy(5, 8);
    printf("\033[31mEvery Game has certain cheat codes or cheat sheets\033[0m\n");
    gotoxy(5, 9);
    printf("Quiz ver:10.8 is also having it as it is a quiz game.\n");
    gotoxy(5, 10);
    printf("List of All correct answers.\n");
    gotoxy(5, 11);
    printf("Correct Answers:\n");
    gotoxy(5, 12);
    printf("1.) C\n");
    gotoxy(5, 13);
    printf("2.) D\n");
    gotoxy(5, 14);
    printf("3.) C\n");
    gotoxy(5, 15);
    printf("4.) B\n");
    gotoxy(5, 16);
    printf("5.) A\n");
    gotoxy(5, 17);
    printf("6.) B\n");
    gotoxy(5, 18);
    printf("7.) A\n");
    gotoxy(5, 19);
    printf("8.) B\n");
    getchar(); getchar();
    printrndone(); // assume defined elsewhere
    return 0;
}

// start() function
int start() {
    gotoxy(1, 1);
    layout();

    // Header
    gotoxy(20, 8);   printf("\t\t\t\t\t\t Quiz\n");
    gotoxy(20, 9);   printf("\t\t\t\t\t     Version:10.01\n");
    gotoxy(20, 10);  printf("\t\t\t\t\t    (Round: 1 - 4 )\n");

    // Instructions & marking scheme
    gotoxy(5, 11);   printf("General Instructions:\n");
    gotoxy(85, 11);  printf("Marking Scheme:\n");
    gotoxy(5, 12);   printf("a.) This quiz has 4 rounds\n");
    gotoxy(85, 12);  printf("i.) Each C.A. 10m\n");
    gotoxy(5, 13);   printf("b.) Each group can answer 4 questions\n");
    gotoxy(85, 13);  printf("ii.) Each W.A. -5m\n");
    gotoxy(5, 14);   printf("c.) Two groups can attempt the quiz\n");
    gotoxy(85, 14);  printf("iii.) Each U.A. 0m\n");
    gotoxy(5, 15);   printf("d.) To Unattempt a question type letter 'u' other than the option.\n");
    gotoxy(85, 15);  printf("iv.) Each B.A. 5m\n");
    gotoxy(5, 16);   printf("e.) Each question must be answered in 20 seconds (for originals)\n");
    gotoxy(5, 17);   printf("f.) Each bonus question must be answered in 05 seconds\n");
    gotoxy(25, 21);  printf("Used Short Abbreviations:\n");
    gotoxy(85, 21);  printf("New Improvements and bug fixes:\n");
    gotoxy(25, 22);  printf("1.) C.A. = Correct answer\n");
    gotoxy(85, 22);  printf("1.) SOURCE CODE VIEW\n");
    gotoxy(25, 23);  printf("2.) W.A. = Wrong answer\n");
    gotoxy(85, 23);  printf("3.) U.A. = Unattempted answer\n");
    gotoxy(85, 24);  printf("4.) B.A. = Bonus answer\n");
    gotoxy(85, 27);  printf("QUIZ MASTER: Subhajit Halder\n");
    gotoxy(25, 27);  printf("Developer: Subhajit Halder\n");
    gotoxy(55, 30);  printf("\033[31m<<Press ENTER to Continue>>\033[0m\n");

    getchar(); // wait for ENTER

    // Ask user for cheats, evaluator, about or start quiz
    int ch = getchar();
    if (ch == 'i') about();
    else if (ch == 'e') evaluator();
    else if (ch == 'c') cheatcode();
    else {
        // Start all rounds using round-wise functions
        printrndone();
        printrndtwo();
        printrndthree();
        printrndfour();
    }

    return 0;
}

// timerO() function for Windows
int timerO() {
    int a = 15;
    while (a >= 0) {
        gotoxy(70, 8);
        printf("TIME LEFT: %2d sec(s)\n", a);
        Sleep(1000); // Windows Sleep in milliseconds
        a--;
        if (a == 5) printf("\a");
    }
    gotoxy(5, 15);
    printf("Enter your answer: ");
    return 0;
}

// timerB() function for Windows
int timerB() {
    int a = 10;
    while (a >= 0) {
        gotoxy(70, 8);
        printf("TIME LEFT: %2d sec(s)\n", a);
        Sleep(1000); // Windows Sleep in milliseconds
        a--;
        if (a == 5) printf("\a");
    }
    gotoxy(5, 22);
    printf("Enter your answer: ");
    return 0;
}
//Quadratic equation Solver
void quad_eqn_solve() {
    gotoxy(1, 1); layout();
    gotoxy(5, 8);
    printf("%sWelcome to Quadratic Eqn Solver Ver: 1.0%s\n", green, CLOSEUNDERLINE);
    gotoxy(5, 9);
    printf("%sYour equations must be in the form of ax^2+bx+c=0%s\n", Yellow, cc);

    double a, b, c, d, r1, r2;
    gotoxy(5, 11); printf("Enter coefficient of x^2 (a): "); scanf("%lf", &a);
    gotoxy(5, 12); printf("Enter coefficient of x (b): "); scanf("%lf", &b);
    gotoxy(5, 13); printf("Enter the constant term(c): "); scanf("%lf", &c);

    d = b * b - 4 * a * c;

    if (d >= 0) {
        double di = sqrt(d);
        r1 = (-b + di) / (2 * a);
        r2 = (-b - di) / (2 * a);
        gotoxy(5, 15);
        if (d == 0)
            printf("Equation has real and equal roots. Roots are: %.2lf and %.2lf\n", r1, r2);
        else {
            printf("Equation has real and unequal roots. Roots are: %.2lf and %.2lf\n", r1, r2);
            gotoxy(5, 16);
            printf("Possible reasons for approximation differences:\n");
            gotoxy(5, 17); printf("a.) The answer has imperfect square numbers\n");
            gotoxy(5, 18); printf("b.) The answer may contain fractions, nearest whole numbers used\n");
        }
    }
    else {
        gotoxy(5, 15);
        printf("Equation has imaginary roots.\n");
    }

    getchar(); getchar();
    prompt();
}

// Area of triangle with coordinates
void atc() {
    gotoxy(1, 1); layout();

    double x1, y1, x2, y2, x3, y3, area;
    gotoxy(5, 8);
    printf("%sWelcome to Area of Triangle finder (works with given coordinates).%s\n", green, cc);
    gotoxy(5, 9);
    printf("**Important Instruction: Enter a space between x and y coordinate.**\n");

    gotoxy(5, 10); printf("Enter the first coordinate: "); scanf("%lf %lf", &x1, &y1);
    gotoxy(5, 11); printf("Enter the second coordinate: "); scanf("%lf %lf", &x2, &y2);
    gotoxy(5, 12); printf("Enter the third coordinate: "); scanf("%lf %lf", &x3, &y3);

    area = 0.5 * ((x1 * (y2 - y3)) + (x2 * (y3 - y1)) + (x3 * (y1 - y2)));

    gotoxy(5, 13);
    printf("Area: %.2lf\n", area >= 0 ? area : -area);

    getchar(); getchar();
    prompt();
}