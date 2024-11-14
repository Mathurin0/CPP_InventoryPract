#include "dish.h"

Dish::Dish(uint8_t foodType, uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability) : Consumable(effect, name, description, cost, manaConsumptionAmount, curseLevel, durability)
{
	mFoodType = foodType;
}

void Dish::SetEffect(uint8_t foodType)
{
	mFoodType = foodType;
}

uint8_t Dish::GetEffect()
{
	return mFoodType;
}

bool Dish::HasEffect(uint8_t foodType)
{
	if ((mFoodType & foodType) != 0)
	{
		return true;
	}
	return false;
}

void Dish::AddEffect(uint32_t foodType)
{
	mFoodType += foodType;
}

void Dish::RemoveEffect(uint32_t foodType)
{
	mFoodType -= foodType;
}
