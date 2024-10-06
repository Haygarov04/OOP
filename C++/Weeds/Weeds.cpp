

#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

const int max_plants = 100;

class CPlant
{
protected:
	string name;
	float price;
	int pNumber;
public:
	CPlant();
	~CPlant();
	void addPlant();
	virtual void display();
	float getPrice();
	virtual string getColor();
};

CPlant::CPlant()
{
}

CPlant::~CPlant()
{
}
void CPlant::addPlant()
{
	cout << "Enter name: ";cin >> name;
	cout << "Enter price: ";cin >> price;
	cout << "Enter number: ";cin >> pNumber;
}

void CPlant::display()
{
	cout << "Name: ";cout << name;cout << endl;
	cout << "Price: ";cout << price;cout << endl;
	cout << "Number: ";cout << pNumber;cout << endl;

}

float CPlant::getPrice()
{
	return price;
}

string CPlant::getColor() {
	return "";
}
class CTree : public CPlant
{
protected:
	/*CPlant tree;*/
	int high, type;
public:
	void addPlant();
	void display();

};
void CTree::addPlant()
{
	//tree.addPlant();
	CPlant::addPlant();
	cout << "Enter high: ";cin >> high;
	cout << "Enter type(1-coniferous/2-deciduous): ";cin >> type;
	cout << endl;
	cout << endl;
}
void CTree::display()
{
	//tree.display();
	CPlant::display();
	cout << "High: ";cout << high;cout << endl;
	cout << "Type: ";cout << type;cout << endl;
	cout << endl;
	cout << endl;
}
class CFlowers : public CPlant
{
protected:
	/*CPlant flower;*/
	string color;
public:
	void addPlant();
	void display();
	string getColor() override;


};
void CFlowers::addPlant()
{
	/*CFlowers::pgetData();*/
	/*flower.addPlant();*/
	CPlant::addPlant();
	cout << "Enter color: ";cin >> color;
	cout << endl;
	cout << endl;
}
void CFlowers::display()
{
	/*CFlowers::pdisplay();*/
	/*flower.display();*/
	CPlant::display();
	cout << "Color: ";cout << color;cout << endl;
	cout << endl;
	cout << endl;
}

string CFlowers::getColor() {
	return color;
}






int main()
{
	int choice;
	int input = 0;
	CPlant* plants[max_plants]{};
	int plantcount = 0;
	float maxPrice = 0;
	int maxIndex = 0;

	CPlant* redFlowers[max_plants];
	int nextindex = 0;


	do
	{
		cout << "Menu" << endl;
		cout << "1. Get data for one plant" << endl;
		cout << "2. Display all plants" << endl;
		cout << "3. Display the most expensive plant" << endl;
		cout << "4. Display red flowers" << endl;
		cout << "0. Exit" << endl;
		cout << "Chose option: " << endl;
		cin >> choice;
		cout << endl;
		cout << endl;

		switch (choice)
		{
		case 1:
			cout << "What plant you want to enter(1-tree/2-flower)?: ";cin >> input;cout << endl;

			if (input == 1)
			{
				CTree* newTree = new CTree();
				newTree->addPlant();
				plants[plantcount] = newTree;
				plantcount++;

			}
			else if (input == 2)
			{
				CFlowers* newFlower = new CFlowers();
				newFlower->addPlant();
				plants[plantcount] = newFlower;
				plantcount++;
			}


			break;
		case 2:
			for (int i = 0; i <= plantcount - 1; i++)
			{
				plants[i]->display();
			}
			cout << endl;
			cout << endl;

			break;
		case 3:
			 maxPrice = plants[0]->getPrice();
			 maxIndex = 0;

			// Обхождаме останалите растения и търсим най-голямата цена
			for (int i = 1; i < plantcount; ++i) {
				float currentPrice = plants[i]->getPrice();
				if (currentPrice > maxPrice) {
					maxPrice = currentPrice;
					maxIndex = i;
				}
			}

			// Извеждаме данните на растението с най-голяма цена
			cout << "Plant with the highest price:" << endl;
			plants[maxIndex]->display();

			break;
		case 4:
			for (int i = 0; i < plantcount; i++)
			{
				if (plants[i]->getColor()=="red")
				{
					redFlowers[nextindex] = plants[i];
					nextindex++;
				}
			}
			for (int y = 0; y < nextindex; y++)
			{
				redFlowers[y]->display();
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

	// Изтриваме всички обекти във масива, за да избегнем изтичане на памет
	for (int i = 0; i < plantcount; i++) {
		delete plants[i];
	}
	for (int i = 0; i < nextindex; i++) {
		delete redFlowers[i];
	}


}


