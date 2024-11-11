#include "inventory.h"

Inventory::Inventory()
{
	mContent = std::vector<Item>();
}

std::vector<Item> Inventory::GetContent()
{
	return mContent;
}
