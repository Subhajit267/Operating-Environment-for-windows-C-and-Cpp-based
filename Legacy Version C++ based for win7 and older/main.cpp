#ifdef _MSC_VER
#define _CRT_DEFINE_NO_WARNINGS
#endif
#define read _read
#include<iostream>
#include<direct.h>
#include<io.h>
#include<Windows.h>
#include<chrono> //Basically jotogulo predefined function commonly use kori sei sob mention korlam  :)
#include<thread> 
#include<cstdlib>
#include<sys/stat.h>
#include<sys/types.h>
#include<conio.h>
#include<ctime>
#include <stdlib.h>
#include<iomanip>
#include <string>
#include<fstream>
#include <random>
#include <stdio.h>
 #define bold "\x1B[1m"//ascii escape sequences jate bar bar mention na korte hoi tai age predifine korechi
#define red "\x1B[31m"
#define BLUE "\x1B[34m"
#define purple "\x1B[95m"
#define RED "\x1B[91m"
#define Yellow "\x1B[33m"
#define yellow "\x1B[93m"
#define blue "\x1B[94m"
#define UNDERLINE "\033[4m"
int reg_status, trial;
#define CLOSEUNDERLINE "\033[0m"
#define green "\x1B[92m"
#define cc "\033[0m"
#define cyan "\x1B[36m"
#define invisible "\x1B[8m"
#include <random>
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

/*  And an ernest request to everyperson who will view this source code
PLEASE dont change my name from the secret about menu
You may change it from the start screen but not from anywhere else
*/


void reg_edit();
void prompt();
void settings();
using namespace std;
#include"sources.h"
#include"look.h"
#include"Sources2.h"
#include"programs.h"
#include"help.h"
void IP()//Installer procedure
{
	gotoxy(1, 1); layout(); logo(); gotoxy(10, 8);
	system("color 3f"); string c;//defining the console color
	reg_status = 1;//Added support for adming reg_edit
	cout << "" << "" << "Do you want to directly install this application or you want to use it once before installation?(Enter choice below).";//Same strings that are displayed there
	gotoxy(32, 10);    cout << "" << """Help Me Decide:";
	gotoxy(32, 12);    cout << "" << "" << "If you wish to install the program directly on the browser without testing for once press y.";
	gotoxy(32, 13);    cout << "If you want to test the program before installing i.e. if you want to have a look at the user ";
	gotoxy(32, 14);    cout << "interface press n and it will load you into the guest user login screen. Just Press enter there  ";
	gotoxy(32, 15);    cout << "to login. As it is trial so only three commands login, install and exit would be there.";
	gotoxy(32, 18);    cout << "" << "" << "To install the program directly press any key or press n to test it:";
	cout << "";//making console output and input "" for a while
	cin >> c;//taking input
	cout << "";//making everything again normal after taking the input
	if (c == "n" || c == "N")//if trial required
	{
		system("cls");
		gotoxy(1, 1);
		layout();
		logo();
		gotoxy(5, 7);
		cout << "After completion of your trial type 'install' to restart the setup to continue.";
		login();
	}
	else if (c == "registryeditor_admin")//if reg_edit is required, for bypassing regular install procedure
	{
		reg_status = 1;
		reg_edit();	//Skipping setup
	}
	else if (c == "prompt")//Totally skipping setup and going to after installed state, user must be created to avoid setup via settings
	{
		reg_status = 1; ins = 0;
		prompt();
	}
	else //if direct installation required
	{
		system("cls");    layout();    logo();        gotoxy(32, 8);
		system("color 0b");
		cout << "" << "" << "" << "While the program is installing let us know its working:" << "";
		gotoxy(32, 10);
		cout << "" << "At first type help command at the prompt.";	   gotoxy(32, 11);
		cout << "You will be getting a list of available commands use it  " << "";	   gotoxy(88, 10);
		cout << "  Designed for ease";	   gotoxy(32, 12);
		cout << "" << "to install your desired program";	   gotoxy(88, 11);
		cout << "" << "For ease in using ";	   gotoxy(32, 13);
		cout << "" << "Enjoy using it!!!";	   gotoxy(88, 12);
		cout << "" << "softwares" << "";	   gotoxy(88, 17);
		cout << "" << "DEVELOPER:" << "" << " Subhajit Halder";	   gotoxy(2, 6);
		progressbar();	   Sleep(5000);
		_mkdir("C:\\OE");
		gotoxy(32, 42);
		_mkdir("C:\\OE\\Activation");
		_mkdir("C:\\OE\\Files"); system("color 04");
		gotoxy(32, 42);
		system("xcopy .\\resources c:\\oe /s /e ");
		getchar(); getchar();
		add_user();      reg = 0;
		install();//Creating default files
		Improvements();//Showing improveme  nts
		getchar();//waiting to get a character thus pausing the screen
		gotoxy(1, 2);          layout();          login();//Restarting after installation over
	}
}


int main()
{
	system("mode 650");
	system("color 0f");
	bootscreen();
	fstream file;
	string word, t, q, filename;
	filename = "c:\\OE\\Files\\file.txt";      // opening file
	file.open(filename.c_str());
	if (file.good())
	{
		system("cls");
		prompt();// IF user has deleted resource files of the program
		system("color 4f"); gotoxy(1, 1); layout(); logo(); gotoxy(32, 10);
		cout << "" << "" << "The system contains a pre-installed copy of this program. The installation cannot continue.";
		gotoxy(32, 11);   cout << "" << """First delete the old version then continue. Press any key to exit"; getchar();
	}
	else
	{
		IP();
	}
	return 0;
}
