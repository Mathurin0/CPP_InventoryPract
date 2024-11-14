#pragma once
#include <iostream>
#include "item.h"
#include "itemType.h"

class Tool : public Item
{
public :
	Tool(int efficiency, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability);

	void Equip();

	void SetEfficiency(int efficiency);
	uint8_t GetEfficiency();

protected:
	uint8_t mEfficiency;
};

