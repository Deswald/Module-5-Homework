#include "VendingMachine.h"
#include <iostream>

using namespace std;

namespace vending_machine
{
	// ������������ Snack
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
	// ����������� SnackSlot
	SnackSlot::SnackSlot(int freeSpace)
	{

		this->freeSpace = freeSpace;

	}
	// ����������� VendingMachine
	VendingMachine::VendingMachine(int slotCount)
	{
		for (int i = 0; i < slotCount; ++i)
		{
			this->slots[i] = 0;
		}

	}
	// �������
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
	// ������
	void SnackSlot::addSnack(Snack* snack ) // �������� ����
	{
		if(this->freeSpace > 0)
		{
			this->freeSpace -= 1;
		}
		else
		{
			this->freeSpace = 0;
			cout << "���� ��������" << endl;
		}
	}
	void SnackSlot::deleteSnack(Snack* snack) // ������ ����
	{
		if (this->freeSpace < 10)
		{
			this->freeSpace += 1;
		}
		else
		{
			this->freeSpace = 10;
			cout << "���� ��� ����" << endl;
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