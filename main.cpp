#include <iostream>
#include <conio.h>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

void resultsMenu();
void classResults();
void reportCard();
void entryMenu();
void createRecord();
void stdResult(const int& x);
//void dispAll();

class STUDENT {
	int regNo;
	string name;
	int m, e, k, p, c, b, h;
	char grade;

public:

	void dataOutput(const int &reg,string &name1,string &name2, const int& m, const int& e, const int& k, const int& p, const int& b, const int& c, const int& h){

		int total = m + e + k + p + b + c + h;
		float ave = total / 7.0; 
		grade = decide(total);
		cout << "Student Registration number: " << reg << endl;
		cout << "Student Name: " << name1 <<" " << name2 << endl;
		cout << "Mathematics: " << m << endl;
		cout << "English: " << e << endl;
		cout << "Kiswahili: " << k << endl;
		cout << "Physics: " << p << endl;
		cout << "Biology: " << b << endl;
		cout << "Chemistry : " << c << endl;
		cout << "History: " << h << endl;
		cout << "\nTotal marks: " << total << endl;
		cout << "Average: " <<ave << endl;
		cout << "Grade " << grade << endl;		
	}

	void dataInput() {

		cout << "\n------------------------------------------------------------------------------------------------------------\n\n";
		cout << "        Input the Registration number,Name and Marks out of 100. USE SPACEBAR to separate your inputs.\n\n";
		cout << "-------------------------------------------------------------------------------------------------------------\n";
		cout << "Press 0 to exit...\n";
		cout << "Reg No. -  Name - Math - Eng - Kisw - Phy - Bio - Chem - Hist  \n";

		
		ofstream OFobj("Class results.txt", ios::app);
		int counter = 1;
		string name1, name2;
		 do{
			cin >> regNo >> name1>>name2 >> m >> e >> k >> p >> b >> c >> h;
			OFobj << regNo << " " << name1<<" "<<name2 << " " << m << " " << e << " " << k << " " << p << " " << b << " " << c << " " << h << endl;
			 counter++;
		 } while (counter == 1);
		OFobj.close();		
	}

	void table() {

		ifstream IFobj("Class results.txt");

		if (!IFobj) {
			int z;
			cout << "\n\t\tRESULTS NOT FOUND!\n";
			cout << "\t\tPress 0 to exit...\n";
			cin >> z;
			if (z == 0) {
				cout << "\033[2J\033[1;1H";
				exit(0);
			}
		}

		int an, bn, cn, dn, en, fn, gn,regNon;
		string namen1,namen2;
		while (IFobj >> regNon >> namen1>>namen2 >> an >> bn >> cn >> dn >> en >> fn >> gn) {
			int total = an + bn + cn + dn + en + fn + gn;
			float ave = total / 7.0;
			grade = decide(total);
			cout <<setw(4)<< regNon<<"    "<< namen1<<setw(10)<<namen2<<" " << setw(4)<< an<<setw(5) << bn << setw(6) << cn
				<< setw(5) << dn << setw(5) << en << setw(6) << fn << setw(6) << gn << setw(7) << total<<"   " << setw(5) 
				<< setprecision(4) << ave << setw(3) << grade << endl;
			
		}
		IFobj.close();
	}

	char decide(const int& total) {
		char grade;
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

		return grade;
	}
private:
};


STUDENT obj;


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
	

	char ch;	
		cout << "\033[2J\033[1;1H";
		cout << "------------------------------------------------------------------------------\n\n";
		cout << "                              CLASS RESULTS \n\n";
		cout << "------------------------------------------------------------------------------\n\n";
		cout << "Reg No  Name               Math  Eng  Kisw  Phy  Bio  Chem  Hist  Total  Ave  Grade\n\n";

		obj.table();

		cout << "\n\n\t\tDo you want to view more results?\n"
			<< "\t\tPress (Y) - Yes     (N) - No\n";
		cin >> ch;

		if (ch == 'Y' || ch == 'y') {
			resultsMenu();
		}
		if (ch == 'N' || ch == 'n') {
			cout << "\033[2J\033[1;1H";
			main();
		}	
}

void reportCard() {

	int regNo;
	char ch;

	cout << "\033[2J\033[1;1H";
	cout << "\tEnter the Student's Registration Number:\n";
	cin >> regNo;
	stdResult(regNo);
		
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

void stdResult(const int &x) {
	
	ifstream IFobj("Class results.txt");
	if (!IFobj) {
		int exit;
		cout << "\n\n\t\tFILE NOT FOUND!!"
			<< "\n\t\tPress 0 to exit..." << endl;
		cin >> exit;
		if (exit == 0)
			main();
	}
	int reg,m,e,k,p,b,c,h,total;
	string name1,name2;
	while (IFobj >> reg >> name1>>name2 >> m >> e >> k >> p >> b >> c >> h ) {
		if ( reg == x) {
			
			cout << "\033[2J\033[1;1H";
			cout << "--------------------------------------------------------\n\n";
			cout << "                   STUDENT REPORT CARD\n\n";
			cout << "--------------------------------------------------------\n\n";

			obj.dataOutput(reg,name1,name2,m,e,k,p,b,c,h);
			
		}
	}
	IFobj.close();
}

void createRecord() {
	
	cout << "\033[2J\033[1;1H";
	obj.dataInput();

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
				//dispAll();
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



void dispAll() {

	ifstream IFobj("Class results.txt");
	if (!IFobj) {
		int exit;
		cout << "\033[2J\033[1;1H";
		cout << "\n\t\tFile cannot be found!!\n\n";
		cout << "\t\tPress 0 to exit...\n";
		cin >> exit;
		if(exit==0)
			main();
	}	

	cout << "--------------------------------------------------------\n\n";
	cout << "                    ALL STUDENTS RECORDS\n\n";
	cout << "--------------------------------------------------------\n\n";
	
	int a, c, d, e, f, g, h, i;
	float j;
	char k;
	string b;
	while (IFobj >>a>>b>>c>>d>>e>>f>>g>>h>>i>>j>>k) {
		
		obj.dataOutput();
	}
	IFobj.close();
}









