#include "inventory.h"

Inventory::Inventory()
{
	mContent = std::vector<Item>();
}

std::vector<Item> Inventory::GetContent()
{
	return mContent;
}

Item Inventory::GetItemByIndex(int index)
{
	return mContent[index];
}

Item* Inventory::GetITemByName(std::string name)
{
	for (int i = 0; i < mContent.size(); i++)
	{
		if (mContent[i].GetName() == name)
		{
			return &mContent[i];
		}
	}

	std::cout << "Not any item in inventory with name : " << name << std::endl;
	return nullptr;
}

int Inventory::GetIndexByName(std::string name)
{
	for (int i = 0; i < mContent.size(); i++)
	{
		if (mContent[i].GetName() == name)
		{
			return i;
		}
	}

	std::cout << "Not any item in inventory with name : " << name << std::endl;
	return -1;
}

std::vector<Item*> Inventory::GetPotContent()
{
	return mPot;
}

void Inventory::ClearPotContent()
{
	mPot.clear();
}

void Inventory::AddToPot(Item* item)
{
	mPot.push_back(item);
	*this -= *item;

	std::cout << "You added to pot : " << item->GetName() << std::endl;
}

void Inventory::PrintInventory()
{
	for (int i = 0; i < mContent.size(); i++)
	{
		std::cout << i << " : " << mContent[i].GetName() << std::endl;
	}
}
