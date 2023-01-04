#include "VendingMachine.h"
#include <iostream>

using namespace std;

namespace vending_machine
{
	// Конструкторы Snack
	Snack::Snack(string snackName, int snackCallories, float snackCost)
	{
		this->snackName = snackName;
		this->snackCallories = snackCallories;
		this->snackCost = snackCost;
	}
	Snack::Snack(string snackName, float snackCost)
	{
		this->snackName = snackName;
		this->snackCost = snackCost;
	}
	Snack::Snack(string snackName, int snackCallories)
	{
		this->snackName = snackName;
		this->snackCallories = snackCallories;
	}
	Snack::Snack(string snackName)
	{
		this->snackName = snackName;
	}
	// Конструктор SnackSlot
	SnackSlot::SnackSlot(int freeSpace)
	{

		this->freeSpace = freeSpace;

	}
	// Конструктор VendingMachine
	VendingMachine::VendingMachine(int slotCount)
	{
		for (int i = 0; i < slotCount; ++i)
		{
			this->slots[i] = 0;
		}

	}
	// Геттеры
	int SnackSlot::getSnack() const
	{
		return freeSpace;
	}
	int VendingMachine::getEmptySlotsCount() const
	{
		int count = 0;
		for (int i = 0; i < slotCount; ++i)
		{
			if (slots[i] == 0)
				++count;
		}
		return count;
	}
	// Методы
	void SnackSlot::addSnack(Snack* snack ) // Добавить снек
	{
		if(this->freeSpace > 0)
		{
			this->freeSpace -= 1;
		}
		else
		{
			this->freeSpace = 0;
			cout << "Слот заполнен" << endl;
		}
	}
	void SnackSlot::deleteSnack(Snack* snack) // Убрать снек
	{
		if (this->freeSpace < 10)
		{
			this->freeSpace += 1;
		}
		else
		{
			this->freeSpace = 10;
			cout << "Слот уже пуст" << endl;
		}
	}
	void VendingMachine::addSlot(SnackSlot* snackSlot)
	{
		for (int i = 0; i < slotCount; ++i)
		{
			if(slots[i] == 0)
			{
				this->slots[i] = snackSlot->getSnack();
				break;
			}
		}
	}
}