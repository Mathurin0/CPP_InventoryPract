#include "armor.h"

Armor::Armor(int armorPoints, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Item (name, description, cost, ItemType::Armor, manaConsumptionAmount, curseLevel, durability)
{
	mArmorPoints = armorPoints;
}

void Armor::Equip()
{
	std::cout << "You equipped the armor : " << mName << std::endl;
}

void Armor::SetArmotPoints(int armorPoints)
{
	mArmorPoints = armorPoints;
}

uint8_t Armor::GetArmorPoints()
{
	return mArmorPoints;
}
