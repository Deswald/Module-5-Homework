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
		// ������������ Snack
		Snack(string snackName, int snackCallories, float snackCost );
		Snack(string snackName, float snackCost);
		Snack(string snackName, int snackCallories);
		Snack(string snackName);

		// ���������� Snack
		~Snack() = default;

	private:
		// ���� ������ Snack
		string snackName;
		int snackCallories;
		float snackCost;
	};

	class SnackSlot
	{
	public:
		// ������������ SnackSlot
		SnackSlot(int numberOfSnacks);


		// ���������� SnackSlot
		~SnackSlot() = default;

		// ������ SnackSlot
		void addSnack(Snack *snack);
		void deleteSnack(Snack *snack);

		// ������ SnackSlot
		int getSnack() const;

	private:
		// ���� ������ SnackSlot
		int freeSpace;
	};

	class VendingMachine
	{
	public:
		// ������������ VendingMachine
		VendingMachine(int const slotCount);

		// ������ VendingMachine
		void addSlot(SnackSlot* snackSlot);

		// ������ VendingMachine
		int getEmptySlotsCount() const;

	private:
		int slots[slotCount];
	};

}
