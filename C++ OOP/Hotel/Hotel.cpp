// Hotel.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

class CGuest
{
protected:
	string name, EGN, area;
	int status, nights, price;
public:
	CGuest();
	~CGuest();
	void GetData();
	void display();
	void namepriceByArea(string Area);
	int unmariedMale(int y);

};

CGuest::CGuest()
{
	name = "Not entered yet";
	EGN= "Not entered yet";
	area= "Not entered yet";
	status = 0;
	nights = 0;
	price = 0;

}

CGuest::~CGuest()
{
}
void CGuest::GetData()
{
	cout << "Enter name: ";cin >> name;cout ;
	cout << "Enter EGN: ";cin >> EGN;cout ;
	cout << "Enter status(1-unmaried,2-maried): ";cin >> status;cout ;
	cout << "Enter how many nights: ";cin >> nights;cout ;
	cout << "Enter price: ";cin >> price;cout ;
	cout << "Enter area: ";cin >> area;cout ;
	cout << endl;
	cout << endl;
}
void CGuest::display()
{
	cout << "Name: ";cout<< name;cout << endl;
	cout << "EGN: ";cout<< EGN;cout << endl;
	cout << "Status: ";cout<< status;cout << endl;
	cout << "Nights: ";cout<< nights;cout << endl;
	cout << "Price: ";cout<<price;cout << endl;
	cout << "Area: ";cout<<area;cout << endl;
	cout << endl;
	cout << endl;
}
void CGuest::namepriceByArea(string Area)
{
	int aCount = 0;
	if (status == 1)
	{
		return;//maried
	}
	if (Area==area)
	{
		cout << "Name: " << name<<endl;
		cout << "Price: " << price<<endl;
	}
	aCount++;

	
	
	cout << endl;
	cout << endl;
}
 int CGuest::unmariedMale(int y)
{
	 string tgender;
	 // Извличане на годината на раждане
	 std::string year_str = EGN.substr(0, 2);
	 int year = std::stoi(year_str);
	 if (year < 0 || year > 99) {
		cout << "Invalid year\n";
		 return 0;
	 }

	 if (year > 20) {
		 year += 1900; // Родени преди 2000 година
	 }
	 else {
		 year += 2000; // Родени след 2000 година
	 }

	 // Проверка за мъжки пол
	 char gender = EGN[8];
	 if ((gender - '0') % 2 == 0) {
		 tgender = "Мъж";
	 }
	 else {
		 tgender = "Жена";
		 return 2; // Несъответствие в пола
	 }
	 if (status==2)
	 {
		 return 2;//maried
	 }

	 // Проверка за съвпадение на годината
	 if (year != y) {
		 std::cout << "Year not equal\n";
		 return 0;
	 }

	 return 1; // Критериите съвпадат


}
int main()
{
	int choice;
	CGuest groupOfGuests[100];
	CGuest yearMaleGuests[100];
	int counter=0;
	string Area;
	int year;
	int y = 0;


	do
	{
		cout << "Menu" << endl;
		cout << "1. Get data for one guest" << endl;
		cout << "2. Display data for all guest" << endl;
		cout << "3. Display name and amount of money by area" << endl;
		cout << "4. Display unmaried men" << endl;
		cout << "0. Exit" << endl;
		cout << "Chose option: " << endl;
		cin >> choice;
		cout << endl;
		cout << endl;

		switch (choice)
		{
		case 1:
			groupOfGuests[counter].GetData();
			counter++;
			break;
		case 2:
			for (int i = 0; i < counter; i++)
			{
				groupOfGuests[i].display();
				
			}
			break;
		case 3:
			cout << "Enter Area: ";cin >> Area;cout << endl;
			for (int i = 0; i < counter; i++)
			{
				groupOfGuests[i].namepriceByArea(Area);
			}
			break;
		case 4:
			cout << "Enter Year: ";cin >> year;cout << endl;
			for (int i = 0; i < counter; i++)
			{
				int result = groupOfGuests[i].unmariedMale(year);
					if (result ==1) {
						
						yearMaleGuests[y]= groupOfGuests[i];
						y++;
					}
			}
			for (int z = 0; z < counter; z++)
			{
				yearMaleGuests[z].display();
			}
			break;
		case 0:
			cout << "Exit";
			break;
		default:
			cout << "Option not valid";
			break;
		}

	} while (choice !=0);
}

