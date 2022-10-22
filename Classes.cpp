using namespace std;
#include "Classes.h"
using namespace Vending;
#include <iostream>


	Snack::Snack(SnackType type, int weight, int price, int calories)
	{
		this->type = type;
		this->weight = weight;
		this->price = price;
		this->calories = calories;
	}


	Snack::Snack(const Snack* Source)
	{
		this->type = Source->type;
		this->weight = Source->weight;
		this->price = Source->price;
		this->calories = Source->calories;
	}

	Snack::~Snack()
	{
	}

	void Snack::print()
	{
		cout << "Type: " << type << endl
			<< "Weight: " << weight << endl
			<< "Price: " << price << endl
			<< "Calories: " << calories << endl;
	}


	Row::Row(int cellNumb)
	{
		snack = new Snack[cellNumb]{};
		this->cellNumb = cellNumb;
	}

	Row::~Row()
	{
		delete[] snack;
	}

	void Row::addSnack(Snack* snack)
	{
		this->snack[cellCount] = *snack;
		++cellCount;
	}

	void Row::removeSnack(Snack* snack)
	{
		this->snack[cellCount] = *snack;
		--cellCount;
	}


	void Row::print()
	{
		for (int i = 0; i < cellNumb; i++)
		{
			cout << endl << "///////// cell " << (i + 1) << ": /////////" << endl;
			snack[i].print();
		}
	}



	Machine::Machine(int rowNumb)
	{
		row = new Row[rowNumb]{};
		this->rowNumb = rowNumb;

	}

	Machine::~Machine()
	{
		delete[] row;
	}


	void Machine::addRow(Row* row)
	{
		this->row[rowCount] = *row;
		++rowCount;
	}

	void Machine::removeRow(Row* row)
	{
		this->row[rowCount] = *row;
		--rowCount;
	}

	void Machine::print()
	{
		for (int i = 0; i < rowNumb; i++)
		{
			cout << endl << "////////////////// ROW " << (i + 1) << ": //////////////////" << endl;
			row[i].print();
		}
	}

	int Vending::Machine::getEmptyRowCount()
	{
		return (rowNumb - rowCount);
	}
