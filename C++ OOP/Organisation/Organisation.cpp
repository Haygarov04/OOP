// Organisation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

using namespace std;
class CDate
{
protected:
	int d, m, y;
public:
	CDate() { y = 1970; };
	~CDate();
	void setDateFromEGN(const string& EGN);
	void displayDate();
};

CDate::~CDate()
{
}
void CDate::setDateFromEGN(const string& EGN)
{
	// Пример за извличане на ден, месец и година от ЕГН
	d = stoi(EGN.substr(4, 2));
	m = stoi(EGN.substr(2, 2));
	
	int isIt= stoi(EGN.substr(2, 1));
	if (isIt >=40 && isIt <=52)
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
class CPerson
{
protected:
	CDate birthDate;
	string name, EGN;
	int payment,dni;
public:
	CPerson();
	~CPerson();
	void getData();
	void display();
	string getGender(string gender);
	string malePaymentForMonth(string);
	bool femalePaymentForDay();
	void nameNBirthDate();

};

CPerson::CPerson()
{
}

CPerson::~CPerson()
{
}
void CPerson::getData()
{
	cout << "Enter name: ";
	cin >> name;
	cout << "Enter EGN: ";
	cin >> EGN;
	cout << "Enter payment for one day: ";
	cin >> payment;
	cout << "Enter working days for one month: ";
	cin >> dni;
	birthDate.setDateFromEGN(EGN); 
}
void CPerson::display()
{
	cout << "Name: " << name << endl;
	cout << "EGN: " << EGN << endl;
	cout << "Payment for one day: " << payment << endl;
	cout << "Working days for one month: " << dni<< endl;
	cout << "Birth date: ";
}

string CPerson::getGender(string )
{
	int gen =stoi(EGN.substr(8, 1));
	if (gen%2==0)
	{
		return "male";
	}
	else
	{
		return "female";
	}
	
}

string CPerson::malePaymentForMonth(string)
{
	int monthSalary = payment * dni;
	string gender=getGender(EGN);
	if (monthSalary>=400 && gender == "male")
	{
		return name;
	}
}

bool CPerson::femalePaymentForDay()
{
	string gender = getGender(EGN);
	if (payment < 20 && gender == "female")
	{
		return true;
	}
	
}

void CPerson::nameNBirthDate()
{
	cout << name << "-";birthDate.displayDate();
}

int main()
{
	int choice;
	CPerson people[100];
	CPerson females[100];
	int counter = 0;
	int femalecounter;
	
	int y = 0;


	do
	{
		cout << endl;
		cout << "Menu" << endl;
		cout << "1. Get data for one person." << endl;
		cout << "2. Display data for all people." << endl;
		cout << "3. Males with 400lv salary and more. " << endl;
		cout << "4. Females with payment under 20" << endl;
		cout << "0. Exit" << endl;
		cout << "Chose option: " << endl;
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case 1:
			people[counter].getData();
			counter++;
			break;
		case 2:
			for (int i = 0; i < counter; i++)
			{
				people[i].display();
			}
			break;
		case 3:
			for (int i = 0; i < counter; i++)
			{
				string name;
				name=people[i].malePaymentForMonth(name);

				cout << name<<endl;
			}
			break;
		case 4:
			femalecounter = 0;
			for (int i = 0; i < counter; i++)
			{
				if (people[i].femalePaymentForDay()==true)
				{
					females[i] = people[i];
					femalecounter++;
				}
			}
			for (int i = 0; i < femalecounter; i++)
			{
				females[i].nameNBirthDate();
			}
			break;
		case 0:
			cout << "Exit";
			break;
		default:
			cout << "Option not valid";
			break;
		}

	} while (choice != 0);
}

