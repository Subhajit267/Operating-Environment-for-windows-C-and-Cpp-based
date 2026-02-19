
//This is place of function prototype(some functions)
void quad_eqn_solve();//Quadratic Eqn solver
int printrndone();
int timerS();//Shutdown timer
void logo(); /// gjv
void color_change();
string Difficult;
char board[9] = { ' ',' ',' ',' ',' ',' ',' ',' ',' ' };//Arrays(board layout of TicTacToe)
void show_board();//board show korar function
void get_x_player_choice();// getting player's choice whose letter is X
void get_o_player_choice();// getting player's choice whose letter is O
void get_computer_choice_e();
void get_computer_choice_h();
int count_board(char symbol);
char check_winner();// checking the winner
void computer_vs_player();// declaring how computer can play with the player
void player_vs_player();
void selector_t();
void layout();
void install();
void password_change();
void source();
int scr();
void USER_ACCOUNTS();
void PERSONALIZATION();
void RESET_AND_RESTORE();
int timerS();
void IP();
void add_user();
int timerO();
int timerB();
void login();
int loading();
int start();
int about();
int cheatcode();
int evaluator();
void bootscreen();
void userid_change();
void login();
void tc();
void password_change();
void activation();
int ap, reg, v, ins, bs, mode;
string choice;
double A1, A2, Bi1, Bi2, C1, C2, x, y, m, n;
char C, A_1, cho;
int state;
string a, filename, name1, password1, password;
void gotoxy(short x, short y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x,y };
	SetConsoleCursorPosition(h, c);
}
//Progress_BAR
void progressbar()
{
	gotoxy(58, 35);
	cout << "[                    ]"; gotoxy(59, 35);
	for (int i = 1; i <= 10; i++)
	{
		cout << "||";
		Sleep(250);
	}
	Sleep(2000);
}
void source()//Source Viewer function
{
	char c;
	FILE *fp = fopen(__FILE__, "r");
	do
	{
		c = fgetc(fp);
		putchar(c);
	} while (c != EOF);
	fclose(fp);
	getchar();
	getchar();
}
void Improvements()//Improvements and Bugs
{
	system("cls");
	system("color b"); gotoxy(1, 2);    layout();
	gotoxy(5, 7);     cout << "New Improvements and Bug Fixes:";
	gotoxy(5, 9);     cout << "i.)Change in programming";
	gotoxy(5, 10);    cout << "ii.)New app Quadratic Eqn solver";
	gotoxy(5, 11);    cout << "iii.)Quad Eqn solver can determine nature of roots";
	gotoxy(5, 12);    cout << "iv.)Added trial for quiz in registry editor by changing registry values.";
	gotoxy(5, 13);    cout << "v.)Introduction of a brand new UI";
	gotoxy(5, 14);    cout << "vi.)Introduction of settings application";
	gotoxy(5, 15);    cout << "vii.)Parts of Registry Editor are accessible by normal user. Command :  registryeditor.";
	gotoxy(5, 16);    cout << "viii.)Now you can change your User-ID";
	gotoxy(5, 17);    cout << "iX.)Password can be removed later via the settings application.";
	gotoxy(5, 18);    cout << "x.)Option for system restore by re-installation to solve several errors.";
	gotoxy(5, 19);    cout << "" << "" << "xi.)Added support for Kelvin in Temperature Converter.";
	gotoxy(5, 20);    cout << "" << "xii.)One can directly move into the prompt menu form registry editor.";
	gotoxy(5, 21);    cout << "" << "" << "Next version coming with more features";
	getchar();
}
void login() //Latest Login function
{
	fstream file;//layout done
	logo();
	system("color 0c");
	filename = "c:\\OE\\files\\file.txt";      // opening file
	file.open(filename.c_str());
	if (file.good()) //If User Exists
	{
		gotoxy(4, 9); reg_status = 1;
		cout << "  To begin press enter or type password(if you have created a User-ID).";
		gotoxy(40, 12);        cout << "User-ID:";
		fstream file1, file;   file1.open("c:\\OE\\files\\file.txt");
		file1 >> name1;            cout << " " << name1;
		fstream file2;
		file2.open("c:\\oe\\files\\file2.txt");
		file2 >> password1;
		if (password1 == "0")//if password is removed
		{
			getchar();
			prompt();
		}
		else {
			gotoxy(40, 13);  cout << "Password:";  cout << "";
			cin >> password;             cout << "";
			if (password1 == password)
				prompt();
			else if (password == "registryeditor")
				reg_edit();
			else if (password == "guess_it")
				source();
			else
				timerS();
		}
	}
	else //For Guest User
	{
		gotoxy(5, 9);  reg_status = 0;
		cout << " /* To just test the program (*with limited features) press enter */ ";
		gotoxy(40, 13);   cout << "USER-ID: GUEST";   cout << "  ";
		getchar();
		getchar();
		system("cls");
		ins = 9;
		reg_status = 0;
		prompt();
	}
}
void layout()//main looks the floating form design
{
	gotoxy(1, 1); system("cls"); cout << ""; gotoxy(1, 2);
	cout << "  " << """                                                                                                                                  " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """  \t\t\t\t\t\t\t  " << "" << "" << "" << "Operating Environment" << "" << "                                                    " << """ " << "" << endl;
	cout << "  " << """ " << """  \t\t\t\t\t                    " << "" << "" << "" << "  Version:4.12  " << "" << "" << "" << "" << "                                                       " << """ " << "" << endl;
	cout << "  " << """ " << """                                                        " << "" << """(EVALUATION_BUILD)" << "" << "                                                      " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """ " << """                                                                                                                                " << """ " << "" << endl;
	cout << "  " << """                                                                                                                                  " << "" << endl;
	gotoxy(1, 1);
}
void add_user()//User Creation menu
{
	fstream f1, f2, f3;   string id, c, pass;
	system("cls"); layout();
	system("color 0d");
	gotoxy(5, 10);     cout << "" << "" << "" << "Welcome to USER-ID Password Creation Wizard Ver: 1.7.9" << "";
	gotoxy(5, 11);     cout << "FOLLOW THE ONSCREEN INSTRUCTIONS TO CREATE A USER";
	gotoxy(5, 12);     cout << "" << "PLease create a user id password for safety reasons:" << "";
	gotoxy(5, 13);       cout << "User-Id:";
	cin >> id;
	f1.open("c:/oe/files/file.txt", ios::out);
	f1 << id;
	f1.close();
	gotoxy(5, 14);          cout << "Do you want to create a password(y/n):";
	cin >> c;
	if (c == "y")//If password is to be created
	{

		gotoxy(5, 15);
		cout << "Enter password:";
		cin >> pass;
		if (pass == "0")//If ente"" password is 0
		{
			gotoxy(5, 16);
			cout << "" << "" << "The password cannot be 0" << "" << "";
			cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a" << flush;
			gotoxy(5, 17);
			cout << "" << "" << "Press Enter to continue by recreating user.";
			getchar(); getchar(); add_user();
		}

		else//Password is registered in new file
		{
			f2.open("c:/oe/files/file2.txt", ios::out);
			f2 << pass;
			f2.close();
		}
	}
	else
	{
		pass = "0";//Storing password as zero in a file
		f2.open("c:/oe/files/file2.txt", ios::out);
		f2 << pass;
		f2.close();
	}
	gotoxy(5, 16);   cout << "" << "" << "You are Successfull in creating a user." << "";    getchar();    getchar();
}
void install()//Installer for setting Reg_Values
{
	fstream t, q, tc, c, eqn, qd, at;
	t.open("c:\\oe\\files\\TicTacToe.txt", ios::out);          t << reg;          t.close();
	q.open("c:\\oe\\files\\Quiz.txt", ios::out);          q << reg;          q.close();
	tc.open("c:\\oe\\files\\TC.txt", ios::out);          tc << reg;          tc.close();
	c.open("c:\\oe\\files\\Calc.txt", ios::out);          c << reg;          c.close();
	eqn.open("c:\\oe\\files\\solve.txt", ios::out);         eqn << reg;          eqn.close();
	qd.open("c:\\oe\\files\\quad_solve.txt", ios::out);          qd << reg;          qd.close();
	at.open("c:\\oe\\files\\ATC.txt", ios::out);          at << reg;          at.close();
}
void color_change()
{
	system("cls"); gotoxy(1, 1);    layout();    gotoxy(5, 8);
	cout << "" << "" << """Welcome to background "" color changer wizard." << "";  gotoxy(5, 9);
	cout << "" << """Available options:" << "";  gotoxy(5, 10);
	cout << " -------------------------------------------"; gotoxy(5, 11);
	cout << "|    " << "" << """COLOR_NAME" << """       |        " << "" << """SAMPLE" << """       |";     gotoxy(5, 12);
	cout << "|" << "" << "" << " 1.) ""             " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 13);
	cout << "|" << "" << "" << " 2.) Green          " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 14);
	cout << "|" << "" << "" << " 3.) Yellow         " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 15);
	cout << "|" << "" << "" << " 4.) ""             " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 16);
	cout << "|" << "" << "" << " 5.) Purple         " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 17);
	cout << "|" << "" << "" << " 6.)                " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 18);
	cout << "|" << "" << "" << " 7.) Light grey     " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 19);
	cout << "|" << "" << "" << " 8.) Grey           " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 20);
	cout << "|" << "" << "" << " 9.) Light          " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 21);
	cout << "|" << "" << "" << " 10.) Light Green   " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 22);
	cout << "|" << "" << "" << " 11.) Light Yellow  " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 23);
	cout << "|" << "" << "" << " 12.) Light         " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 24);
	cout << "|" << "" << "" << " 13.) Light Purple  " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 25);
	cout << "|" << "" << "" << " 14.) Light         " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 26);
	cout << "|" << "" << "" << " 15.) White         " << "" << " |          " << "  " << "" << "" << "         |"; gotoxy(5, 27);
	cout << "|" << "" << "" << " 16.) Blank         " << "" << " |          " << "  " << "" << "" << "         |";  gotoxy(5, 28);
	cout << " -------------------------------------------";
	gotoxy(5, 29);    cout << """Enter choice (To exit press e): ";
	string colorr;
	cin >> colorr;
	if (colorr == "1" || colorr == "2" || colorr == "3" || colorr == "4" || colorr == "5" || colorr == "6" || colorr == "7" || colorr == "8" || colorr == "9" || colorr == "10" || colorr == "11" || colorr == "12" || colorr == "13" || colorr == "14" || colorr == "15")
	{
		fstream color;
		color.open("c:\\oe\\files\\looks.h", ios::out);
		if (colorr == "1")//""
		{
			color << "#define "" \"\\x1B[41m\"";
		}
		else if (colorr == "2")//Green
		{
			color << "#define "" \"\\x1B[42m\"";
		}
		else if (colorr == "3")//Yellow
		{
			color << "#define "" \"\\x1B[43m\"";
		}
		else if (colorr == "4")//""
		{
			color << "#define "" \"\\x1B[44m\"";
		}
		else if (colorr == "5")//Purple
		{
			color << "#define "" \"\\x1B[45m\"";
		}
		else if (colorr == "6")//Aqua
		{
			color << "#define "" \"\\x1B[46m\"";
		}
		else if (colorr == "7")//Light Grey
		{
			color << "#define "" \"\\x1B[47m\"";
		}
		else if (colorr == "8")//Grey
		{
			color << "#define "" \"\\x1B[100m\"";
		}
		else if (colorr == "9")//Light ""
		{
			color << "#define "" \"\\x1B[101m\"";
		}
		else if (colorr == "10") //Light Green
		{
			color << "#define "" \"\\x1B[102m\"";
		}
		else if (colorr == "11")//Light Yellow
		{
			color << "#define "" \"\\x1B[103m\"";
		}
		else if (colorr == "12")//Light ""
		{
			color << "#define "" \"\\x1B[104m\"";
		}
		else if (colorr == "13")//Light Purple
		{
			color << "#define "" \"\\x1B[105m\"";
		}
		else if (colorr == "14")//""
		{
			color << "#define "" \"\\x1B[106m\"";
		}
		else if (colorr == "15")//WHite
		{
			color << "#define "" \"\\x1B[107m\"";
		}
		else if (colorr == "16")//Blank
		{
			color << "#define "" \"\\x1B[99m\"";
		}

		color.close();
		cout << "\a\a\a\a\a\a" << flush;			gotoxy(30, 10);                system("cls");
		cout << "" << """ Program is shuttng Down to save the changes. Re-launch to to see the effect!!!" << "";
		Sleep(2000);                exit(0);
	}
	else if (colorr == "e")
		settings();
	else
	{
		gotoxy(5, 30);
		cout << "No command.";
		getchar(); getchar();
		color_change();
	}
}
void USER_ACCOUNTS()
{
	system("cls"); gotoxy(1, 1);
	system("color 6e");   layout(); gotoxy(5, 8);    cout << "" << "" << """Welcome to User Account Control Panel:" << "";
	gotoxy(5, 9);    cout << "" << """Pick a task: ";
	gotoxy(5, 10);    cout << "" << """1.) Add /Remove /Create Password for your accounts";
	gotoxy(5, 11);    cout << "2.) Change Your User_ID.";
	gotoxy(5, 12);    cout << "3.) EXIT.";
	gotoxy(5, 13);    cout << "" << """Enter choice(1-3): " << "";
	cin >> choice;
	if (choice == "1")
		password_change();
	else if (choice == "2")
		userid_change();
	else if (choice == "3")
		settings();
	else {
		gotoxy(5, 25); cout << "" << "" << "No suitable record found" << "\a\a\a\a\a\a\a\a\a\a\a" << flush;
		getchar(); getchar(); USER_ACCOUNTS();
	}
	getchar(); getchar(); USER_ACCOUNTS();
}
void RESET_AND_RESTORE()
{
	system("color 2e");
	system("cls"); gotoxy(1, 1);    layout(); gotoxy(5, 8);    cout << "" << "" << """Welcome to Reset and Restore Panel:" << "";
	gotoxy(5, 9);    cout << "" << """Pick a task: ";
	gotoxy(5, 10);    cout << "" << """1.) Reset your applications";
	gotoxy(5, 11);    cout << "2.) Restore your system by re-installing it.";
	gotoxy(5, 12);    cout << "3.) EXIT.";
	gotoxy(5, 13);    cout << "" << """Warning!! Any of the above task(command) will reset all your applications thus delete /alter data. ";
	gotoxy(5, 14);    cout << "" << """Do you want to continue(y/n)?";
	cin >> a;
	if (a == "y" || a == "Y")
	{
		gotoxy(5, 15);
		cout << "" << """Enter choice(1-3): " << "";
		cin >> choice;
		if (choice == "1")
		{
			reg = 0;
			install();
		}
		else if (choice == "2")
			IP();
		else if (choice == "3")
			settings();
		else {
			gotoxy(5, 25); cout << "" << "" << "No suitable record found" << "\a\a\a\a\a\a\a\a\a\a\a" << flush;
			getchar(); getchar(); RESET_AND_RESTORE();
		} getchar(); getchar(); RESET_AND_RESTORE();
	}
	else
		settings();
}
void PERSONALIZATION()
{
	system("color 5d"); system("cls"); gotoxy(1, 1);    layout();
	gotoxy(5, 8);    cout << "" << "" << """Welcome to Personalization Panel:" << "";
	gotoxy(5, 9);    cout << "" << """Pick a task: ";
	gotoxy(5, 10);    cout << "" << """1.) Change your "" color.";
	gotoxy(5, 11);    cout << "2.) EXIT.";
	gotoxy(5, 12);    cout << "" << """Enter choice(1-2): " << "";
	cin >> choice;
	if (choice == "1")
		color_change();
	else if (choice == "2")
		settings();
	else {
		gotoxy(5, 25); cout << "" << "" << "No suitable record found" << "\a\a\a\a\a\a\a\a\a\a\a" << flush;
		getchar(); getchar(); PERSONALIZATION();
	}
	getchar(); getchar(); PERSONALIZATION();
}
#pragma once
