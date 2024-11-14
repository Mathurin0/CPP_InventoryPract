#include "potion.h"

Potion::Potion(bool isSplash, uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Consumable(effect, name, description, cost, manaConsumptionAmount, curseLevel, durability)
{
	mIsSplash = isSplash;
}

void Potion::SetSplash(bool isSplash)
{
	mIsSplash = isSplash;
}

bool Potion::GetSplash()
{
	return mIsSplash;
}
