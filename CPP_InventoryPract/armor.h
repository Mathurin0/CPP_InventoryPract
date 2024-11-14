#pragma once
#include <iostream>
#include "item.h"
#include "itemType.h"

class Armor : public Item
{
public :
	Armor(int armorPoints, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability);

	void Equip();

	void SetArmotPoints(int armorPoints);
	uint8_t GetArmorPoints();

protected:
	uint8_t mArmorPoints;
};

