#pragma once
//New layout done for the file
//installer for all programs
void installer()
{
	reg = 1;//The registry values which registers the apps as installed or not
	gotoxy(1, 1); layout();
	if (v == 1 && bs == 1)//at differnt states which title will be shown tar jonno
	{
		gotoxy(20, 8);        cout << "\t\t\t\t\t\tTIC TAC TOE";//String values depending on reg_calls
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:4.0";
	}
	else if (v == 2 && bs == 2)
	{
		gotoxy(20, 8);            cout << "\t\t\t\t\t\tQUIZ__APP";
		gotoxy(20, 9);            cout << "\t\t\t\t\t      " << "  Version:10.8";
	}
	else if (v == 3 && bs == 3)// temperature converter   
	{
		gotoxy(20, 8);            cout << "\t\t\t\t\t\tTEMP_CONV";
		gotoxy(20, 9);            cout << "\t\t\t\t\t      " << "  Version:4.05";
	}
	else if (v == 4 && bs == 4)
	{
		gotoxy(20, 8);        cout << "\t\t\t\t\t\tCALCULATOR";
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:3.05";
	}
	else if (v == 6 && bs == 6)
	{
		gotoxy(46, 8);        cout << "Pair_of_eqn_solve";
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:4.05";
	}
	else if (v == 7 && bs == 7)
	{
		gotoxy(60, 8);        cout << "Quadratic_eqn_solve";
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:1.05";
	}
	else if (v == 8 && bs == 8)
	{
		gotoxy(60, 8);        cout << "Area_Of_Triangle(CO)";
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:1.00";
	}
	gotoxy(20, 11);		cout << "\t\t\t\t\t        Please_Wait.";//Ei gulo common strings
	gotoxy(20, 12);		cout << "\t\t\t\t\t     While setup is";
	gotoxy(20, 13);		cout << "\t\t\t\t\t        Installing...";
	Sleep(1000);
	if (v == 1 && bs == 1)
		activation(); //activation for tictactoe
	else if (v == 2 && bs == 2)
		activation();  //activation for quiz
	else if (v == 3 && bs == 3)
	{
		fstream f;      f.open("c:\\oe\\files\\TC.txt", ios::out);
		f << reg;         f.close();
	}
	else if (v == 4 && bs == 4)
	{
		fstream f;         f.open("c:\\oe\\files\\Calc.txt", ios::out);
		f << reg;         f.close();
	}
	else if (v == 6 && bs == 6)
	{
		fstream f;         f.open("c:\\oe\\files\\solve.txt", ios::out);
		f << reg;            f.close();
	}
	else if (v == 7 && bs == 7)
	{
		fstream f;         f.open("c:\\oe\\files\\quad_solve.txt", ios::out);
		f << reg;            f.close();
	}
	else if (v == 8 && bs == 8)
	{
		fstream f;         f.open("c:\\oe\\files\\ATC_solve.txt", ios::out);
		f << reg;            f.close();
	}
	system("cls");
	system("cls");
	Sleep(2000);
	layout(); logo(); prompt();
}
void activation()//Common activation method for tictactoe and Quiz
{
	gotoxy(1, 1); layout();    gotoxy(5, 8); reg = 1; cout << "Enter product key(10 charcters):";
	char key[10];    cin >> key;
	if (v == 1)//FOr TicTacToe
	{
		if (key[6] + key[0] == key[9] + key[5])
		{
			gotoxy(5, 10);   cout << "Verified";
			getchar(); getchar();
			fstream k, t;				   k.open("c:\\oe\\Activation\\file3.txt", ios::out);				   k << key;				   k.close();
			t.open("c:\\oe\\files\\TicTacToe.txt", ios::out); 				   t << reg;				   t.close();
			prompt();
		}
		else
		{
			gotoxy(5, 10);				  cout << "Invalid key";
			getchar(); getchar(); prompt();
		}
	}
	else if (v == 2)//FOr Quiz
	{
		if (key[7] + key[8] == key[2] + key[9])
		{
			gotoxy(5, 10);		   cout << "Verified";		   getchar(); getchar();
			fstream k, t;			   k.open("c:\\oe\\Activation\\file6.txt", ios::out);				   k << key;				   k.close();
			t.open("c:\\oe\\files\\Quiz.txt", ios::out); 				   t << reg;				   t.close();
			prompt();
		}
		else
		{
			gotoxy(5, 10);				  cout << "Invalid key";
			getchar(); getchar();
			prompt();
		}
	}
}
//Bootscreens
void bootscreen()
{
	system("cls");  gotoxy(1, 1);  layout();
	if (bs == 1)
	{
		gotoxy(20, 8);        cout << "\t\t\t\t\t      " << "TIC TAC TOE";//String values depending on reg_calls
		gotoxy(20, 9);        cout << "\t\t\t\t\t  " << "    Version:4.0";
		state = 0;
	}
	else if (bs == 0)
	{
		layout();            logo();
		state = 1;
	}
	else if (bs == 2)
	{
		gotoxy(20, 8);          cout << "    " << "\t\t\t\t\t   " << "   " << "QUIZ__APP";
		gotoxy(20, 9);            cout << "\t\t\t\t\t   " << "  Version:10.8";
		state = 0;
	}
	else if (bs == 3)
	{
		gotoxy(20, 8);            cout << "\t\t\t\t\t\tTEMP_CONV";
		gotoxy(20, 9);            cout << "\t\t\t\t\t      " << "  Version:4.05";
		state = 0;
	}
	else if (bs == 4)
	{
		gotoxy(20, 8);      cout << "\t\t\t\t\t\tCALCULATOR";
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:3.05";
		state = 0;
	}
	else if (bs == 6)
	{
		gotoxy(60, 8);        cout << "Pair_of_eqn_solve";
		gotoxy(17, 9);        cout << "\t\t\t\t\t  " << "   Version:4.05";
		state = 0;
	}
	else if (bs == 7)
	{
		gotoxy(60, 8);        cout << "Quadratic_eqn_solve";
		gotoxy(20, 9);        cout << "t\t\t\t\t      " << "  Version:1.05";
	}
	else if (bs == 8)
	{
		gotoxy(60, 8);        cout << "Area_Of_Triangle(CO)";
		gotoxy(20, 9);        cout << "\t\t\t\t\t      " << "  Version:1.00";
	}
	gotoxy(17, 19); cout << "\t\t\t\t\t     Please_Wait.";
	gotoxy(17, 20); cout << "\t\t\t\t\t     LOADING......";
	progressbar();    gotoxy(53, 16); cout << "                                                         ";
}
int printerror() // To avoid any error in marks counting this section is used
{
	system("color cf");
	gotoxy(1, 1); layout();    cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a";
	gotoxy(5, 10);     printf("\t\t\t\tAn Unexpected error occured due to invalid input\t\t");
	gotoxy(5, 11);     printf("\nThe program is restarting. Press Enter\t\t");
	getchar();    getchar();
	system("color 0f"); prompt(); return 0;
}
void logo()
{
	gotoxy(5, 10);    cout << " ======================== ";
	gotoxy(5, 11);    cout << "|" << "   --------    -------" << "  |";
	gotoxy(5, 12);    cout << "|" << "  |        |  |       " << "  |";
	gotoxy(5, 13);    cout << "|" << "  |        |  |       " << "  |";
	gotoxy(5, 14);    cout << "|" << "  |        |   ====== " << "  |";
	gotoxy(5, 15);    cout << "|" << "  |        |  |       " << "  |";
	gotoxy(5, 16);    cout << "|" << "  |        |  |       " << "  |";
	gotoxy(5, 17);    cout << "|" << "   --------    -------" << "  |";
	gotoxy(5, 18);    cout << " ======================== ";
}
//password_change wizard
void password_change()
{
	gotoxy(1, 1); layout(); gotoxy(5, 7); cout << "Welcome to password changing wizard Ver 1.7.9";
	gotoxy(5, 8);    cout << "Enter Following details :";
	string name1, name, password, password1;
	string passnew;
	gotoxy(5, 9);   cout << "User-ID:";    cin >> name;
	fstream file1;       file1.open("c:\\oe\\files\\file.txt");       file1 >> name1;
	if (name1 == name)
	{
		fstream file;
		string word, t, q, filename;
		filename = "c:\\oe\\files\\file2.txt";        // opening file
		file.open(filename.c_str());
		if (file.good()) //if Password exists
		{
			gotoxy(5, 10); char pc;          cout << "Do you wish to keep a Password? "; cin >> pc;
			if (pc == 'y')
			{
				gotoxy(5, 11);
				cout << "Enter your last Password(if no Password was applied type 0):";
				cin >> password;
				fstream file2;
				file2.open("c:\\oe\\files\\file2.txt");
				file2 >> password1;
				if (password1 == password)
				{
					gotoxy(5, 12);                            cout << "Enter new password:";
					cin >> passnew;                            getchar();
					if (passnew == "0")
					{
						gotoxy(5, 16);                               cout << "The password cannot be 0";                               cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a\a" << flush;
						gotoxy(5, 17);                               cout << "Press Enter to restart password_change wizard.";
						getchar(); getchar();
						password_change();
					}
					else
					{
						fstream f1;                f1.open("c:\\oe\\files\\file2.txt", ios::out);               f1 << passnew;                             f1.close();
						gotoxy(5, 13);                             cout << "Your password has been changed";
						getchar();  system("cls");
					}
				}
				else //intruder
					timerS();
			}
			else
			{
				gotoxy(5, 13);     cout << "Your password has been removed";  getchar();  getchar();
				fstream file;
				file.open("file2.txt", ios::out);
				file << "0";
				file.close();
			}
		}
		else//if password doesn't exists
		{
			fstream f2;                string pass;                f2.open("c:\\oe\\files\\file2.txt", ios::out);
			gotoxy(5, 10);              cout << "Enter password:";                cin >> pass;                f2 << pass;
			f2.close();
			gotoxy(5, 12);                 cout << "Your password has been changed";
			getchar();
		}
		settings();
	}
	else//intruder
		timerS();
}
//Shutdown timer
int timerS() {
	int a = 10;
	gotoxy(40, 20);  cout << "ACCESS DENIED";
	gotoxy(40, 21);  cout << "Invalid Password.";
	while (a >= 0)                // while loop execution
	{
		cout << "\a\a\a\a\a\a\a\a\a\a\a\a\a\a" << flush;
		gotoxy(70, 12);        cout << "TIME UNTIL SHUTDOWN: " << setw(2) << a << "sec(s)" << endl;
		Sleep(1000);        a--;
		if (a == -1)
			exit(0);
	}
	return 0;
}
void userid_change()
{
	system("cls"); layout();
	fstream f1;
	string id, c, pass, nnn;
	gotoxy(5, 10);     cout << "Welcome to USER-ID Changing Wizard Ver 1.0.";
	gotoxy(5, 11);     cout << "FOLLOW THE ONSCREEN INSTRUCTIONS TO CHANGE THE USER-ID";
	gotoxy(5, 12);     cout << "Enter New USER-ID: ";
	cin >> nnn;
	f1.open("c:\\oe\\files\\file.txt", ios::out);
	f1 << nnn;
	f1.close();
	gotoxy(5, 17);     cout << "Your USER-ID has been changed. Re login to see the effect, press enter.";
	getchar(); getchar(); system("cls"); gotoxy(1, 1); layout(); login();
}
void settings()
{
	system("cls");    layout();
	gotoxy(5, 7);    cout << "Welcome to the Settings!!";
	gotoxy(5, 8);    cout << "Available sub-categories: ";
	gotoxy(5, 10);    cout << "1.) USER ACCOUNTS";
	gotoxy(5, 11);    cout << "2.) RESET AND RESTORE";
	gotoxy(5, 12);    cout << "3.) Personalization";
	gotoxy(5, 13);    cout << "4.) HELP";
	gotoxy(5, 14);    cout << "5.) EXIT";
	gotoxy(5, 15); cout << "Enter choice(1-5): "; string choice; cin >> choice;
	if (choice == "1")
		USER_ACCOUNTS();
	else if (choice == "2")
		RESET_AND_RESTORE();
	else if (choice == "3")
		PERSONALIZATION();
	else if (choice == "5") {
		gotoxy(1, 1); system("cls"); layout(); prompt();
	}
	else if (choice == "7")
		color_change();
	else if (choice == "4")
	{
		gotoxy(5, 17); cout << "Welcome to Help Documentaion Ver: 1.0 ";
		gotoxy(5, 18); cout << "1.) Press 1 to change/delete/apply new password or to change USER_ID for your account.";
		gotoxy(5, 19); cout << "2.) Press 2 to reset or restore your account.";
		gotoxy(5, 20); cout << "3.) Press 3 personalize your account by Changing colors.";
		gotoxy(5, 21); cout << "4.) Press 5 to exit settings."; getchar(); getchar();
	}
	else if (choice == "user_add")
		add_user();
	else
	{
		gotoxy(5, 25); cout << "No suitable record found" << "\a\a\a\a\a\a\a\a\a\a\a" << flush;
		getchar(); getchar(); settings();
	}
	gotoxy(5, 30);    cout << "Successfully completed the command";
	getchar();    settings();
}
