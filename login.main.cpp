#include<iostream>
#include<conio.h>
#include<string>
#include <fstream>
#include <ctime>
using namespace std;
class singin {
private:
	string user, pass, rpass;
	int counter = 1;
	void check_User();
	void check_Pass();
public:
	singin(string, string);
	void getUser();
	void getPass();
	void getrpass();
	void check();
	void input();
};
singin::singin(string u, string p) {
	user = u;
	pass = p;
	check_User();
}
void singin::getUser() {
	string u;
	cin >> u;
	user = u;
	check_User();
}
void singin::getPass() {
	string p;
	cin >> p;
	pass = p;
	check_Pass();
}
void singin::getrpass() {
	string r;
	cin >> r;
	rpass = r;
	check_Pass();
}
void singin::check_User() {
	int ulength = user.length();

	if (ulength < 5 || ulength>18) {
		cout << "           Username length is too small or to big (5-18 char) . Enter new Username : ";
		getUser();
	}
	else if (user.at(0) >= '0' && user.at(0) <= '9') {
		cout << "           Username Is not Valid . Enter Another : ";
		getUser();
	}
	else {
		check_Pass();
	}
}
void singin::check_Pass() {
	int ac = 0, nc = 0;
	int pl = pass.length();
	for (int i = 0; i < pass.length(); i++) {
		if (pass.at(i) >= 'a' && pass.at(i) <= 'z' || pass.at(i) >= 'A' && pass.at(i) <= 'Z') {
			ac++;
		}
		if (pass.at(i) >= '0' && pass.at(i) <= '9') {
			nc++;
		}
	}
	if (nc >= pass.length() || ac >= pass.length()) {
		cout << "           Password must be combination of chars : ";
		getPass();
	}
	else if (pl < 8 || pl>32) {
		cout << "           Password length is too small or too big . Enter Another pass(8-32) : ";
		getPass();
	}
	else if (pass == user) {
		cout << "           username and password can't same !!! Please Enter new Password : ";
		getPass();
	}
	else {
	     check();
	}
}
void singin::check() {
	string rpass;
	cout << "           Enter Repley Password : ";
	cin >> rpass;
	if (pass == rpass) {

	}
	else {
		if (counter == 3) {
			cout << "Your Account Was Blocked !!";
			cin.ignore();
			cin.get();
			exit(1);
		}
		counter++;
		check();
	}

}
/*void singin::input() {
	string username, password, rpassword;
	cout << "Enter Username : ";
	cin >> username;
	cout << "Enter Password : ";
	cin >> password;
	//cout << "Enter Password : ";
	//cin >> rpassword;
	singin acc(username, password);
}*/
int main()
{
	string textToSave;
	string option;
	system("color 03");
menu:
	cout << endl;
	cout << "         =====================================" << endl;
	cout << "         ||        WELCOME TODO APP         ||" << endl;
	cout << "         =====================================" << endl;
	cout << "         || 1 - SIGN IN                     ||" << endl;
	cout << "         || 2 - LOGIN                       ||" << endl;
	cout << "         || 3 - EXIT                        ||" << endl;
	cout << "         =====================================" << endl;
	cout << "\n          Enter Your Choice :	";
	getline(cin, option);

	if (option == "1") {
        string textToSave;
		system("cls");
		system("color 06");
		cout << "        ========================================" << endl;
		cout << "        ||            TODO APP                ||\n";	//save a string
		cout << "        ========================================\n\n" << endl;
		string username, password, rpassword;
		cout << "           Enter Username : ";
		cin >> username;
		cout << "           Enter Password : ";
		cin >> password;
		//cout << "Enter Password : ";
		//cin >> rpassword;
		singin acc(username, password);
		getline(cin, textToSave);
		ofstream saveFile("file.txt");
		saveFile << textToSave;
        cout << "" << endl<< endl<< endl<< endl<< endl<< endl;
        saveFile.close();
		system("pause");
		system("cls");

		goto menu;
	}
	if (option == "2") {
		system("color 03");
		system("cls");
		ifstream loadFile;
		loadFile.open("file.txt", ifstream::in);
		cout << "        ========================================" << endl;
		cout << "        ||    THE FILE CONTAINS THE STRING    ||\n";
		cout << "        ========================================\n\n" << endl;
		cout << "        ";
		while (loadFile.good()) {
			cout << (char)loadFile.get();
		}
		cout << "" << endl << endl << endl << endl << endl << endl;
		loadFile.close();

		system("pause");
		system("cls");

		goto menu;
	}
	if (option == "3") {
		system("color 02");
		system("cls");
		cout << "\n\n\n\n";
		cout << "        ========================================" << endl;
		cout << "        ||              GOOD BYE              ||\n";
		cout << "        ========================================\n\n" << endl;
		return 0;
	}
	_getch();
	return 0;
}

