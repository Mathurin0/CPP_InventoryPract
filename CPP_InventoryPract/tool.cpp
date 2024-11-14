#include "tool.h"

Tool::Tool(int efficiency, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Item(name, description, cost, ItemType::Tool, manaConsumptionAmount, curseLevel, durability)
{
	mEfficiency = efficiency;
}

void Tool::Equip()
{
	std::cout << "You equipped the tool : " << mName << std::endl;
}

void Tool::SetEfficiency(int efficiency)
{
	mEfficiency = efficiency;
}

uint8_t Tool::GetEfficiency()
{
	return mEfficiency;
}
