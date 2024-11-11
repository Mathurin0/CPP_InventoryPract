#include <vector>
#include <iostream>
#include "item.h"

class Inventory
{
public :
	Inventory();

	std::vector<Item> GetContent();

	bool operator +=(Item item) {
		if (mContent.size() < mMaxSlots)
		{
			mContent.push_back(item);
			return true;
		}
		std::cout << "could not add " << item.GetName() << " : inventory full" << std::endl;
		return false;
	}

	bool operator -=(Item item) {
		for (int i = 0; i < mContent.size(); i++)
		{
			if (mContent[i] == item) {
				mContent.erase(mContent.begin() + i);
				return true;
			}
		}
		std::cout << "could not remove " << item.GetName() << " : not found" << std::endl;
		return false;
	}

private :
	std::vector<Item> mContent;
	int mMaxSlots = 30;
};
