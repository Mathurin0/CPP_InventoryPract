#pragma once
#include "item.h"

class IFlammable
{
public :
	virtual void SpreadFire(Item item) = 0;
};

