//___________________________ Start __________________________//
#include <iostream>
#include <string>
#include <cstdlib>
#include <conio.h>
using namespace std;

//____________________ System Deta___________________________//
struct Busline {
	int numline;
	string nameline;
	int tableline;
	int passengers;
};

const int Max = 100;
int currentBus = 0;
Busline Bus[100];
//____________________ Set Color Function ___________________//
void setColor(const string& colorCode) {
	cout << "\033[" << colorCode << "m";
}

//_________________________ Add line__________________________//
void addBus() {
	int n;
	system("cls");
	system("color 1F");
	cout << "Please enter how many lines do you want to enter: ";
	cin >> n;

	if (currentBus + n <= Max) {
		for (int i = 0; i < n; i++) {
			cout << "Please enter (" << currentBus + i + 1 << ") line Number of Bus: ";
			cin >> Bus[currentBus + i].numline;
			cin.ignore();
			cout << "Please enter (" << currentBus + i + 1 << ") Name Bus: ";
			getline(cin, Bus[currentBus + i].nameline);
			cout << "Please enter (" << currentBus + i + 1 << ") tables: ";
			cin >> Bus[currentBus + i].tableline;
			cout << "Please enter (" << currentBus + i + 1 << ") passengers register: ";
			cin >> Bus[currentBus + i].passengers;
		}
		currentBus += n;
	}
	else {
		setColor("31");
		cout << "The capacity of the line is complete.\n";
		return;
	}

	setColor("32");
	cout << "The line successfully added. \n\n";

	setColor("37");
	cout << "Please press any key to go back to the menu... ";
	_getch();
}

//_________________________ Add new Passenger________________//
void addPass() {
	int n;
	system("cls");
	system("color 0A");

	if (currentBus == 0) {
		setColor("31");
		cout << "There isn't any line. \n";
		setColor("37");
		cout << "Please press any key to go back to the menu... ";
		_getch();
		return;
		
	}

	cout << "Please enter the line number: ";
	cin >> n;

	bool found = false;
	for (int i = 0; i < currentBus; i++) {
		if (Bus[i].numline == n) { 
			if (Bus[i].passengers < Bus[i].tableline) {
				int x;
				cout << "Please enter number of new passengers: ";
				cin >> x;

				if (Bus[i].passengers + x <= Bus[i].tableline) {
					Bus[i].passengers += x;
					setColor("32");
					cout << "The passengers successfully added. \n";
				}
				else {
					cout << "Not enough seats available.\n";
				}

			}
			else {
				cout << "There is no seat. \n";
			}
			found = true;
			break;
		}
	}

	if (!found) {
		setColor("31");
		cout << "Line not found. \n";
	}

	setColor("37");
	cout << "Please press any key to go back to the menu... ";
	_getch();
}

//_________________________ Line status______________________//
void lineStatus() {
	system("cls");
	system("color 83");
	cout << "This is lines status: \n\n";

	if (currentBus == 0) {
		setColor("31");
		cout << "There isn't any line. \n\n";
		setColor("37");
		cout << "Please press any key to go back to the menu... ";
		_getch();
		return;
	}

	for (int i = 0; i < currentBus; i++) {
		cout << "-----------------------------------" << endl;
		cout << i + 1 << "_";
		cout << "Bus line Number: " << Bus[i].numline << endl;
		cout << "Bus line Name: " << Bus[i].nameline << endl;
		cout << "Bus tables: " << Bus[i].tableline << endl;
		cout << "Bus passengers: " << Bus[i].passengers << endl;
		cout << "Bus empty tables: " << max(0, Bus[i].tableline - Bus[i].passengers) << endl;
		cout << "-----------------------------------" << endl;
		cout << endl;
	}

	setColor("37");
	cout << "Please press any key to go back to the menu... ";
	_getch();
}

//_________________________ Passengers status________________//
void passStatus() {
	int n;
	system("cls");
	system("color 0B");

	if (currentBus == 0) {
		setColor("31");
		cout << "There isn't any line. \n";
		setColor("37");
		cout << "Please press any key to go back to the menu... ";
		_getch();
		return;
	}

	cout << "Please enter line number: ";
	cin >> n;

	bool found = false;
	for (int i = 0; i < currentBus; i++) {
		if (Bus[i].numline == n) {
			cout << "There are (" << Bus[i].passengers << ") passengers in the line (" << n << ")\n";
			cout << "Bus empty tables: " << max(0, Bus[i].tableline - Bus[i].passengers) << endl;
			found = true;
			break;
		}
	}

	if (!found) {
		setColor("31");
		cout << "No line found!! \n\n";
	}

	setColor("37");
	cout << "Press any key to return to the main menu... ";
	_getch();
}

//_________________________ Delete line______________________//
void deleteLine() {
	int n;
	system("cls");
	system("color 0A");

	if (currentBus == 0) {
		setColor("31");
		cout << "There isn't any line. \n\n";
		setColor("37");
		cout << "Please press any key to go back to the menu... ";
		_getch();
		return;
	}

	cout << "Please enter line number: ";
	cin >> n;

	for (int i = 0; i < currentBus; i++) {
		if (Bus[i].numline == n) {
			for (int v = i; v < currentBus - 1; v++) {
				Bus[v] = Bus[v + 1];
			}
			Bus[currentBus - 1] = {};
			currentBus--;
			setColor("32");
			cout << "The line removed successfully. \n";
		} else {
			setColor("31");
			cout << "Line not found. \n\n";
		}
	}

	setColor("37");
	cout << "Press any key to return to the main menu... ";
	_getch();
}

//________________ About Developer _____________________//
void AboutDev() {
	system("cls");

	setColor("33");
	cout << "< --------------------------------------------------------------------------------------- >\n";

	setColor("32");
	cout << "Hello,\nThis program was developed by Mohammadreza\n"
		"in 2024 as part of my university project.\n\n\n";

	setColor("33");
	cout << "<< -------------------------------------------------------------------------------------- >>\n";

	setColor("31");
	cout << "About Me:\n\n";

	setColor("32");
	cout << "Dev: Mohammadreza\n";
	cout << "Email: twimmati@gmail.com\n";
	cout << "Telegram: @l6Ml6\n\n";

	setColor("37");
	cout << "Press any key to return to the main menu...";
	_getch();
}

//_________________________ Menu ____________________________//
int menu() {
	while (1) {
		system("cls");
		system("color 0A");
		setColor("32");
		cout << "\t\t\t< << ------------Welecome to city transportation system------------ >> > \n\n\n" ;
		setColor("34");
		cout << "\t[1] Adding new lines. \t\t\t\t\t [2] Adding new passengers.\n";
		cout << "\t[3] Lines Status. \t\t\t\t\t [4] The Status of Line Passengers.\n";
		cout << "\t[5] Delete a line. \t\t\t\t\t [0] Exit. \n";
		cout << "\t\t\t\t\t [6] About Dev. \n\n";
		setColor("37");
		cout << "Enter a number to continue: ";
		int chose = _getch();

		switch (chose) {
		case '1':
			addBus();
			break;
		case'2':
			addPass();
			break;
		case'3':
			lineStatus();
			break;
		case'4':
			passStatus();
			break;
		case'5':
			deleteLine();
			break;
		case'6':
			AboutDev();
			break;
		case'0':
			exit(0);
		}
	}
}
//______________________ Main Function ______________________//
int main() {
	menu();
	return 0;
}
//_____________________ End Programming _____________________//
// Developed by Mohammadreza