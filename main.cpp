#include <iostream>
#include <conio.h>
#include <fstream>

using namespace std;

class STUDENT {
public:


private:

};


void resultsMenu();
void classResults();


int main() {

	STUDENT obj;

	int choice;
	cout << "--------------------------------------------------------\n\n";
	cout << "                       MAIN MENU\n\n";
	cout << "--------------------------------------------------------\n\n";

	cout << "Please select your option (1-3)\n\n";
	cout << "\t1. RESULTS MENU"
		<< "\n\t2. ENTRY/EDIT MENU"
		<< "\n\t3. EXIT\n\n";

	cin >> choice;
	cout << "\n";

	switch (choice) {
	case 1:
		resultsMenu();
		break;
		/*case 2:
			break;*/
	case 3:
		exit(0);
		break;
	default:
		cout << "Wrong Input!" << endl;
		main();

	}

	return 0;
}

void resultsMenu() {

	int choice;
	cout << "\033[2J\033[1;1H";  //clear the screen

	cout << "--------------------------------------------------------\n\n";
	cout << "                       RESULTS MENU\n\n";
	cout << "--------------------------------------------------------\n\n";

	cout << "Choose your option (1-3)\n\n";
	cout << "\t1. CLASS RESULTS"
		<< "\n\t2. STUDENT REPORT CARD"
		<< "\n\t3. BACK\n\n";

	cin >> choice;
	cout << "\n";

	switch (choice)
	{
	case 1:
		classResults();
		break;
	case 2:
		break;
	case 3:
		main();
	}

}

void classResults() {

	int z;
	STUDENT obj;
	ifstream IFobj("Class Results.txt");

	if (!IFobj) {
		cout << "\n\t\tRESULTS NOT FOUND!\n";
		cout << "\t\tPress 0 to redirect...";
		cin >> z;
		if (z == 0) {
			cout << endl << endl;
			main();
		}

	}
	/*else {
		while (IFobj.read(reinterpret_cast<char*>(&obj), sizeof(STUDENT)))
		{

		}
	}*/
	IFobj.close();


}
