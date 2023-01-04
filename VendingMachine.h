#pragma once
#include <iostream>

using namespace std;

namespace vending_machine
{
	enum vendingConst
	{
		slotCount = 10,
	};

	class Snack
	{
	public:
		// Конструкторы Snack
		Snack(string snackName, int snackCallories, float snackCost );
		Snack(string snackName, float snackCost);
		Snack(string snackName, int snackCallories);
		Snack(string snackName);

		// Деструктор Snack
		~Snack() = default;

	private:
		// Поля класса Snack
		string snackName;
		int snackCallories;
		float snackCost;
	};

	class SnackSlot
	{
	public:
		// Конструкторы SnackSlot
		SnackSlot(int numberOfSnacks);


		// Деструктор SnackSlot
		~SnackSlot() = default;

		// Методы SnackSlot
		void addSnack(Snack *snack);
		void deleteSnack(Snack *snack);

		// Геттер SnackSlot
		int getSnack() const;

	private:
		// Поля класса SnackSlot
		int freeSpace;
	};

	class VendingMachine
	{
	public:
		// Конструкторы VendingMachine
		VendingMachine(int const slotCount);

		// Методы VendingMachine
		void addSlot(SnackSlot* snackSlot);

		// Геттер VendingMachine
		int getEmptySlotsCount() const;

	private:
		int slots[slotCount];
	};

}
