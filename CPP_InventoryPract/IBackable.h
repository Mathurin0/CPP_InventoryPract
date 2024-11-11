#include <vector>
#include "item.h"

#pragma once
class IBackable
{
	virtual Item Cook(std::vector<Item> ingredients) = 0;
};
