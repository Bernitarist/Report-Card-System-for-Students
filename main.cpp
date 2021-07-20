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
	float ave;
	char grade;
public:

	void dataOutput() {

		cout << "Student Registration number: " << regNo << endl;
		cout << "Student Name: " << name << endl;
		cout << "Mathematics: " << m << endl;
		cout << "English: " << e << endl;
		cout << "Kiswahili: " << k << endl;
		cout << "Physics: " << p << endl;
		cout << "Biology: " << b << endl;
		cout << "Chemistry : " << c << endl;
		cout << "History: " << h << endl;
		calculate();
		cout << "Total " << total << endl;
		cout << "Average " << ave << endl;
		cout << "Grade " << grade << endl;		
	}

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
		cout << "\nBiology - "; cin >> b;
		cout << "\nChemistry - "; cin >> c;
		cout << "\nHistory - "; cin >> h;
	}

	void table() {

		cout << regNo << " " << name << " " << m << " " << e << " " << k << " " << p << " " << b << " " << c << " " << total << " " << ave << " " << grade << " " << endl;
	}
	
private:
};

STUDENT obj;

void resultsMenu();
void classResults();
void reportCard();
void entryMenu();
void createRecord();
void dispAll();
bool isReportCard(const int& x);
int regNoRet();
void calculate();



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
	ifstream IFobj("Class Results.txt");

	if (!IFobj) {

		cout << "\n\t\tRESULTS NOT FOUND!\n";
		cout << "\t\tPress 0 to go back to the main menu\n";
		cin >> z;
		if (z == 0) {
			cout << "\033[2J\033[1;1H";
			main();
		}
	}
	else {
	    cout << "\033[2J\033[1;1H";
	    cout << "------------------------------------------------------------------------------\n\n";
		cout << "                              CLASS RESULTS \n\n";
		cout << "------------------------------------------------------------------------------\n\n";
		cout << "Reg No  Name                               M  E  K  P  B  C  Total  Ave  Grade\n\n";

		ifstream IFobj("Report Card.txt");
		if (!IFobj) {
			int press;
			cout << "\n\t\tFILE COULD NOT BE FOUND!\n\n";
			cout << "\t\tPress 0 to exit...\n\n";
			cin >> press;
			if (press == 0)
				main();
		}

		int reg, m, e, k, p, b, c, total;
		float ave;
		char grade;
		string name;
		while (IFobj >>reg>>name>>m>>e>>k>>p>>b>>c>>total>>ave>>grade)
		{
			obj.table();			
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
		}
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
	bool status = isReportCard(regNo);
	if (status) {
		dataOutput();
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


void entryMenu() {

	int choice;
	cout << "\033[2J\033[1;1H";

	cout << "--------------------------------------------------------\n\n";
	cout << "                      ENTRY MENU\n\n";
	cout << "--------------------------------------------------------\n\n";

	cout << "Select your option: \n"
		 << "\n\t\t1. CREATE STUDENT RECORD \n\t\t2. VIEW ALL STUDENTS RECORDS \n\t\t3. SEARCH STUDENT RECORD \n\t\t4. MODIFY STUDENT RECORD"
		 << "\n\t\t5. DELETE STUDENT RECORD \n\t\t6. BACK\n\n";
		
	cin >> choice;
		switch (choice) {

			case 1:
				cout << "\033[2J\033[1;1H";
				createRecord();
				break;
			case 2:
				cout << "\033[2J\033[1;1H";
				dispAll();
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

	ofstream OFobj("Class results.txt");
	obj.dataInput();
	OFobj.write((char*) &obj, sizeof(STUDENT));			//Write without overwriting prev data

	int back;
	cout << "\n\n\t\tStudent information succesfully added!\n" << "\t\tPress 1 to add a student or 0 to go back to the main menu...\n";
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

void dispAll() {

	ifstream IFobj("Report card.txt");
	if (!IFobj) {
		cout << "\033[2J\033[1;1H";
		cout << "\n\t\tFile cannot be found!!\n\n";
		cout << endl << endl;
		main();
	}	

	cout << "--------------------------------------------------------\n\n";
	cout << "                    STUDENTS RECORDS\n\n";
	cout << "--------------------------------------------------------\n\n";

	for (int x = 1;x<=(IFobj.eof();x++) {

		dataOutput();
	}
	
}

bool isReportCard(const int &x) {
	ifstream IFobj("Report Card.txt");
	if (IFobj)
		return true;
}

void calculate() {


	total = m + e + k + p + b + c + h;
	ave = total / 7.0;

	if (total >= 560)
		grade = 'A+';
	if (total >= 490 && total < 560)
		grade = 'A';
	if (total >= 420 && total < 490)
		grade = 'B';
	if (total >= 350 && total < 420)
		grade = 'C';
	if (total > 280 && total < 350)
		grade = 'D';
	if (total <= 280)
		grade = 'E';
}

int regNoRet() {

	return regNoRet;
}





