#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const string FILENAME = "user.txt";

bool isusernameexits(const string& username) {
	ifstream infile(FILENAME);
	string user, pass;
	while (infile >> user >> pass) {
		if (user == username) {
			return true;
		}
	}
	return false;
}
void registeruser()
{
	string username, password;
	string fileuser, filepass;
	bool exit = false;
	cout << "___Registration___" << endl;
	cout << " Enter Username: ";
	cin >> username;
	cout << " Enter password: ";
	cin >> password;
	if (isusernameexits(username)) {
		cout << "Username already exists!\n";
		return;
	}

	ofstream outfile(FILENAME, ios::app);
	outfile << username << " " << password << endl;
	cout << "Registration successful!\n";
}

bool checklogin(const string& username, const string& password) {
	ifstream infile(FILENAME);
	string user, pass;
	while (infile >> user >> pass) {
		if (user == username && pass == password) {
			return true;
		}
	}
	return false;
}

void loginuser()
{
	string username, password;

	cout << "___Login___" << endl;
	cout << " Enter Username: ";
	cin >> username;
	cout << " Enter password: ";
	cin >> password;

	if (checklogin(username, password)) {
		cout << "Login successful!\n";
	}
	else {
		cout << "Invalid username or password!\n";
	}
}
int main()
{
	int choice;
	do
	{

		cout << "__Login and Registration system__" << endl;
		cout << " 1.Register  " << endl;
		cout << " 2.Login  " << endl;
		cout << " 3.Exit  " << endl;
		cout << " Enter your choice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			registeruser();
			break;
		case 2:
			loginuser();
			break;
		case 3:
			cout << "Program closed!";
			break;
		default:
			cout << "Invalid choice ";
		}
	} while (choice != 3);
	return 0;
}