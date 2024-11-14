#pragma once
#include "consumable.h"

class Potion : public Consumable
{
public:
	Potion(bool isSplash, uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability);

	void SetSplash(bool isSplash);
	bool GetSplash();

private:
	bool mIsSplash;
};