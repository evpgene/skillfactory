#pragma once
using namespace std;
#include <iostream>

namespace Vending
{
	enum SnackType
	{
		SNICKERS = 0,
		MARS,
		BOUNTY,
		ALENKA
	};

	class Snack //Закуска в ряду
	{
	public:
		Snack(SnackType type, int weight, int price, int calories);
		Snack() = default;
		Snack(const Snack* Source);
		~Snack();
		void print();
	private:
		SnackType type;
		int weight;
		int price;
		int calories;
	};


	class Row //Ряд в машине
	{
	public:
		Row(int cellNumb);
		Row() = default;
		~Row();
		void addSnack(Snack* snack);
		void removeSnack(Snack* snack);
		Snack* snack{ nullptr };
		void print();
	private:
		
		int cellCount{ 0 };
		int cellNumb{ 0 };
	};

	class Machine
	{
	public:
		Machine(int rowNumb);
		~Machine();
		void addRow(Row* row);
		void removeRow(Row* row);
		Row* row{ nullptr };
		void print();
		int getEmptyRowCount();
	private:
		int rowCount{ 0 };
		int rowNumb{ 0 };
	};

}