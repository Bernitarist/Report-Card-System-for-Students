#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

using namespace std;

class STUDENT {

	int regNo;
	string name;
	int m, e, k, p, c, b, h;
	int total;

public:

	void dataInput() {
		
			cout << "Enter the student's Registration no: \n";
			cin >> regNo;
			cout << "Enter the student's Name: \n";
			cin.ignore();
			getline(cin, name);
			cout << "Enter the following marks out of 100:\n ";
			cout << "\nMathematics - "; cin >> m;
			cout << "\nEnglish - "; cin >> e;
			cout << "\nKiswahili - "; cin >> k;
			cout << "\nPhysics - "; cin >> p;
			cout << "\nChemistry - "; cin >> c;
			cout << "\nBiology - "; cin >> b;
			cout << "\nHistory - "; cin >> h;
		
	}

	void dataOutput() {

	}

	int regNoRet() {
		return regNo;
	}


private:
};

STUDENT obj;
void resultsMenu();
void classResults();
void reportCard();
bool isReportCard();
void viewReportCard(const int& x);
void entryMenu();
void createRecord();


int main() {

	int choice;
	cout << "--------------------------------------------------------\n\n";
	cout << "                       MAIN MENU\n\n";
	cout << "--------------------------------------------------------\n\n";

	cout << "Please select your option: \n\n";
	cout << "\t1. RESULTS MENU"
		<< "\n\t2. ENTRY/EDIT MENU"
		<< "\n\t3. EXIT\n\n";

	cin >> choice;
	cout << "\n";

	switch (choice) {
	case 1:
		resultsMenu();
		break;
		case 2:
			entryMenu();
			break;
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
		reportCard();
		break;
	case 3:
		cout << "\033[2J\033[1;1H";
		main();
	}

}

void classResults() {

	int z;
	char ch;
	STUDENT obj;
	ifstream IFobj("Class Results.txt");

	if (!IFobj) {
		cout << "\n\t\tRESULTS NOT FOUND!\n";
		cout << "\t\tPress 0 to go back to the main menu";
		cin >> z;
		if (z == 0) {
			cout << "\033[2J\033[1;1H";
			main();
		}

	}
	/*else {
	*   cout << "\033[2J\033[1;1H";
	*   cout << "--------------------------------------------------------\n\n";
		cout << "                       CLASS RESULTS \n\n";
		cout << "--------------------------------------------------------\n\n";
		while (IFobj.read(reinterpret_cast<char*>(&obj), sizeof(STUDENT)))
		{

		}
			cout << "\n\n\t\tDo you want to view more results?\n"
		<< "\t\tPress (Y) - Yes     (N) - No\n";
	cin >> ch;

	if (ch == 'Y' || ch=='y') {
		resultsMenu();
	}
	if (ch == 'N' || ch=='n') {
		cout << "\033[2J\033[1;1H";
		main();
	}*/
	IFobj.close();
}

void reportCard() {

	int regNo;
	char ch;
	cout << "\033[2J\033[1;1H";
	cout << "--------------------------------------------------------\n\n";
	cout << "                   STUDENT REPORT CARD\n\n";
	cout << "--------------------------------------------------------\n\n";

	cout << "\tEnter the Student's Registration Number:\n";

	cin >> regNo;
	bool status = isReportCard();
	if(status){ 
		viewReportCard(regNo);
	}
	
	cout << "\n\n\t\tDo you want to view another student's report?\n"
		<< "\t\tPress (Y) - Yes     (N) - No\n";
	cin >> ch;

	if (ch == 'Y' || ch=='y') {
		reportCard();
	}
	if (ch == 'N' || ch=='n') {
		cout << "\033[2J\033[1;1H";
		main();
	}
	
}

bool isReportCard() {

	ifstream IFobj("Report Card.dat");
	if (IFobj) {
		return true;
	}
	else {
		cout << "\t\t\tFILE CANNOT BE FOUND!\n\n";
	}
	IFobj.close();
}

void viewReportCard(const int &x) {

	ifstream IFobj("Report Card.dat");
	while (IFobj.read(reinterpret_cast<char*>(&obj), sizeof(STUDENT))) {

		if (obj.regNoRet() == x) {
			cout << "\033[2J\033[1;1H";
			obj.dataOutput();
		}
	}
	IFobj.close();
	
}

void entryMenu() {

	int choice;
	cout << "\033[2J\033[1;1H";

	cout << "--------------------------------------------------------\n\n";
	cout << "                      ENTRY MENU\n\n";
	cout << "--------------------------------------------------------\n\n";

	cout << "Select your option: \n"
		 << "\n\t\t1. CREATE STUDENT RECORD \n\t\t2. VIEW ALL STUDENTS' RECORDS \n\t\t3. SEARCH STUDENT RECORD \n\t\t4. MODIFY STUDENT RECORD"
		 << "\n\t\t5. DELETE STUDENT RECORD \n\t\t6. BACK\n\n";
		
	cin >> choice;
		switch (choice) {

			case 1:
				cout << "\033[2J\033[1;1H";
				createRecord();
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				cout << "\033[2J\033[1;1H";
				main();
				break;
		}
}

void createRecord() {

	int back;

	ofstream OFobj("Report card.dat");
	obj.dataInput();
	OFobj.write(reinterpret_cast<char*> (&obj), sizeof(STUDENT));	
	OFobj.close();

	cout << "\n\nStudent information succesfully added!\n" << "Press 1 to add a student or 0 to go back to the main menu...\n";
	cin >> back;

		switch (back) {
		case 0:
			cout << "\033[2J\033[1;1H";
			main();
			break;
		case 1:
			cout << "\033[2J\033[1;1H";
			createRecord();
		}	
}


