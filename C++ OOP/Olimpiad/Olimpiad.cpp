#include <iostream>
#include <string>
#include <ctime>
#include <chrono>
using namespace std;

const int participantcount = 1000;

class CDate
{
protected:
	int d, m, y;

public:
	CDate() { y = 1970; };
	~CDate();
	void setDateFromEGN(const string& EGN);
	void displayDate();
	/*int setAge(int age);*/
	int calculateAge() const;
};

CDate::~CDate()
{
}
void CDate::setDateFromEGN(const string& EGN)
{
	// Пример за извличане на ден, месец и година от ЕГН
	d = stoi(EGN.substr(4, 2));
	m = stoi(EGN.substr(2, 2));

	int isIt = stoi(EGN.substr(2, 1));
	if (isIt >= 40 && isIt <= 52)
	{
		y = stoi("20" + EGN.substr(0, 2));
		m -= 40;
	}
	else
	{
		y = stoi("19" + EGN.substr(0, 2));
	}
}
void CDate::displayDate()
{
	cout << d << "/" << m << "/" << y << endl;
}

int CDate::calculateAge() const {
	auto now = chrono::system_clock::now();
	time_t now_time = chrono::system_clock::to_time_t(now);
	tm ltm;
	localtime_s(&ltm, &now_time);
	int currentDay = ltm.tm_mday;
	int currentMonth = 1 + ltm.tm_mon;
	int currentYear = 1900 + ltm.tm_year;

	int age = currentYear - y;
	if (currentMonth < m || (currentMonth == m && currentDay < d)) {
		age--;
	}

	return age;
}

//int CDate::setAge(int age)
//{
//
//	// Get current date
//	auto now = chrono::system_clock::now();
//	time_t now_time = chrono::system_clock::to_time_t(now);
//	tm* ltm = localtime(&now_time);
//	int currentDay = ltm->tm_mday;
//	int currentMonth = 1 + ltm->tm_mon;
//	int currentYear = 1900 + ltm->tm_year;
//
//	int age = currentYear - y;
//
//	if (currentMonth < m || (currentMonth == m && currentDay < d)) {
//		age--;
//	}
//
//	return age;
//}






class CParticipant
{
protected:
	int id;
	CDate birthDate;
	string name, EGN;
	int points;
public:
	CParticipant();
	~CParticipant();
	virtual void getData();
	virtual void display();
	string getGender(string gender);
	int getAge() const;
	bool isitmaleover20();
	virtual string getUniversity() const {
		return "";
	}
};

CParticipant::CParticipant()
{
}

CParticipant::~CParticipant()
{
}
void CParticipant::getData()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter EGN: ";
	cin >> EGN;
	cout << "Enter points: ";
	cin >> points;
	birthDate.setDateFromEGN(EGN);
}
void CParticipant::display()
{
	cout << "Name: " << name << endl;
	cout << "EGN: " << EGN << endl;
	cout << "Points: " << points << endl;
}
string CParticipant::getGender(string gender)
{
	int gen = stoi(EGN.substr(8, 1));
	if (gen % 2 == 0)
	{
		return "male";
	}
	else
	{
		return "female";
	}

}

int CParticipant::getAge() const 
{
	//int d, m, y;
	//// Пример за извличане на ден, месец и година от ЕГН
	//d = stoi(EGN.substr(4, 2));
	//m = stoi(EGN.substr(2, 2));

	//int isIt = stoi(EGN.substr(2, 1));
	//if (isIt >= 40 && isIt <= 52)
	//{
	//	y = stoi("20" + EGN.substr(0, 2));
	//	m -= 40;
	//}
	//else
	//{
	//	y = stoi("19" + EGN.substr(0, 2));
	//}

	//// Get current date
	//auto now = chrono::system_clock::now();
	//time_t now_time = chrono::system_clock::to_time_t(now);
	//tm* ltm = localtime(&now_time);
	//int currentDay = ltm->tm_mday;
	//int currentMonth = 1 + ltm->tm_mon;
	//int currentYear = 1900 + ltm->tm_year;

	//int age = currentYear - y;

	//if (currentMonth < m || (currentMonth == m && currentDay < d)) {
	//	age--;
	//}

	//return age;
	
		return birthDate.calculateAge();
}

bool CParticipant::isitmaleover20()
{
	if (getGender(EGN) == "male" && getAge()>20)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class CUstudent : public CParticipant
{
protected:
	CParticipant Ustudent;
	string university, FN;
public:
	CUstudent();
	~CUstudent();
	void getData();
	void display();
	string getUniversity() const;
};

CUstudent::CUstudent()
{
}

CUstudent::~CUstudent()
{
}
void CUstudent::getData()
{
	Ustudent.getData();
	id = 1;
	cout << "Enter university: ";
	cin >> university;
	cout << "Enter FN: ";
	cin >> FN;
}
void CUstudent::display()
{
	Ustudent.display();
	cout << "University: " << university << endl;
	cout << "FN: " << FN << endl;
}

string CUstudent::getUniversity() const
{
	return university;
}

class CSstudent : public CParticipant
{
protected:
	CParticipant Sstudent;
	string school, clas;
public:
	CSstudent();
	~CSstudent();
	void getData();
	void display();
};

CSstudent::CSstudent()
{
}

CSstudent::~CSstudent()
{
}
void CSstudent::getData()
{
	Sstudent.getData();
	id = 2;
	cout << "Enter school: ";
	cin >> school;
	cout << "Enter class: ";
	cin >> clas;
}
void CSstudent::display()
{
	Sstudent.display();
	cout << "School: " << school << endl;
	cout << "Class: " << clas << endl;
}
int main()
{
	CParticipant* participants[participantcount];
	int choice;
	int input = 0;
	int counter = 0;
	int y = 0;
	string university;


	do
	{
		cout << endl;
		cout << "Menu" << endl;
		cout << "1. Get data for one participant." << endl;
		cout << "2. Display data for all participants." << endl;
		cout << "3. Males over 20 by university. " << endl;
		cout << "4. " << endl;
		cout << "0. Exit" << endl;
		cout << "Chose option: " << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			if (counter >= participantcount) {
				cout << "Maximum number of participants reached." << endl;
				break;
			}
			cout << "Enter (1-University student/2-School student)";cin >> input;cout << endl;
			if (input == 1)
			{
				CUstudent* newStudent = new CUstudent;
				newStudent->getData();
				participants[counter] = newStudent;
				counter++;
			}
			 if (input==2)
			{
				CSstudent* newStudent = new CSstudent;
				newStudent->getData();
				participants[counter] = newStudent;
				counter++;
			}
			break;
		case 2:
			for (int i = 0; i < counter; i++)
			{
				participants[i]->display();
			}
			break;
		case 3:
			cout << "Enter university :";cin >> university;cout << endl;
			for (int i = 0; i < counter; i++)
			{
				if (participants[i]->isitmaleover20()==true && participants[i]->getUniversity()==university)
				{
					participants[i]->display();
				}
			}
			break;
		case 4:

			break;
		case 0:
			cout << "Exit";
			break;
		default:
			cout << "Option not valid";
			break;
		}

	} while (choice != 0);

	for (int i = 0; i < counter; i++)
	{
		delete participants[i];
	}
}