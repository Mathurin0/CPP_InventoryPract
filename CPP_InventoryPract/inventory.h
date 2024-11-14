#pragma once
#include <vector>
#include <iostream>
#include "item.h"
#include "IBackable.h"
#include "food.h"

class Inventory
{
public :
	Inventory();

	std::vector<Item> GetContent();
	std::vector<Item*> GetPotContent();
	void ClearPotContent();
	Item GetItemByIndex(int index);
	Item* GetITemByName(std::string name);
	int GetIndexByName(std::string name);
	void AddToPot(Item* item);

	void PrintInventory();

	bool operator +=(Item item) {
		if (mContent.size() < mMaxSlots)
		{
			if (item.HasType(ItemType::Consumable))
			{
				mConsumables.push_back(item);
			}
			else if (item.HasType(ItemType::Tool))
			{
				mTools.push_back(item);
			}
			else if (item.HasType(ItemType::Weapon))
			{
				mWeapons.push_back(item);
			}
			else if (item.HasType(ItemType::Armor))
			{
				mArmors.push_back(item);
				mContent.push_back(item);
				std::cout << "You added " << item.GetName() << " to inventory" << std::endl;
				return true;
			}

			mContent.clear();
			mContent.insert(mContent.end(), mConsumables.begin(), mConsumables.end());
			mContent.insert(mContent.end(), mTools.begin(), mTools.end());
			mContent.insert(mContent.end(), mWeapons.begin(), mWeapons.end());
			mContent.insert(mContent.end(), mArmors.begin(), mArmors.end());
			std::cout << "You added " << item.GetName() << " to inventory" << std::endl;
			return true;
		}
		std::cout << "Could not add " << item.GetName() << " : inventory full" << std::endl;
		return false;
	}

	bool operator -=(Item item) {
		for (int i = 0; i < mContent.size(); i++)
		{
			if (mContent[i].GetName() == item.GetName()) {
				mContent.erase(mContent.begin() + i);
				std::cout << "You removed " << item.GetName() << " from inventory" << std::endl;
			}
		}

		if (item.HasType(ItemType::Consumable))
		{
			for (int i = 0; i < mConsumables.size(); i++)
			{
				if (mConsumables[i].GetName() == item.GetName()) {
					mConsumables.erase(mConsumables.begin() + i);
					return true;
				}
			}
		}
		else if (item.HasType(ItemType::Tool))
		{
			for (int i = 0; i < mTools.size(); i++)
			{
				if (mTools[i].GetName() == item.GetName()) {
					mTools.erase(mTools.begin() + i);
					return true;
				}
			}
		}
		else if (item.HasType(ItemType::Weapon))
		{
			for (int i = 0; i < mWeapons.size(); i++)
			{
				if (mWeapons[i].GetName() == item.GetName()) {
					mWeapons.erase(mWeapons.begin() + i);
					return true;
				}
			}
		}
		else if (item.HasType(ItemType::Armor))
		{
			for (int i = 0; i < mArmors.size(); i++)
			{
				if (mArmors[i].GetName() == item.GetName()) {
					mArmors.erase(mArmors.begin() + i);
					return true;
				}
			}
		}

		std::cout << "Could not remove " << item.GetName() << " : not found" << std::endl;
		return false;
	}

private :
	std::vector<Item> mContent;
	std::vector<Item> mConsumables;
	std::vector<Item> mTools;
	std::vector<Item> mWeapons;
	std::vector<Item> mArmors;
	std::vector<Item*> mPot;
	int mMaxSlots = 30;
};
