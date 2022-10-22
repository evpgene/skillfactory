using namespace std;
#include <iostream>
#include "Classes.h"
using namespace Vending;
const int rowCellNumb{ 10 }; //Количество ячеек в ряду
const int machineRowNumb{ 10 }; //Количество рядов в машине


int main()
{
	Snack* snack1 = new Snack(SNICKERS,35,50,120);


	Row* row1 = new Row(rowCellNumb);
	Row* row2 = new Row(rowCellNumb);

	row1->addSnack(snack1);

	Snack* snack2 = new Snack(ALENKA, 100, 45, 220);

	Snack* snack3 = new Snack(snack2);
	Snack* snack4 = new Snack(snack1);

	Snack* snack5 = new Snack(MARS, 36, 51, 121);
	Snack* snack6 = new Snack(BOUNTY, 37, 52, 122);
	Snack* snack7 = new Snack(snack5);

	row1->addSnack(snack2);
	row1->addSnack(snack3);
	row1->addSnack(snack4);

	row2->addSnack(snack5);
	row2->addSnack(snack6);
	row2->addSnack(snack7);
	row2->addSnack(new Snack(snack1));

	Machine* machine1 = new Machine(machineRowNumb);
	machine1->addRow(row1);
	machine1->addRow(row2);

	cout << endl << "//////////////////////////////////// MACHINE1: //////////////////////////////////// ";
	machine1->print();

	cout << endl << "Empty ROW number: " << machine1->getEmptyRowCount() << endl;
	cout << endl << "________________________________  Goodbye!  ________________________________";
	delete snack1, snack2, snack3, snack4, snack5, snack6, snack7;
	delete row1, row2;
	delete machine1;

	return 0;
}
