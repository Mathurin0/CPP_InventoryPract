#pragma once
#include "consumable.h"
#include "IBackable.h"
#include "FoodType.h"

class Dish : public Consumable
{
public:
	Dish(uint8_t foodType, uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability);

	void SetEffect(uint8_t foodType);
	uint8_t GetEffect();
	bool HasEffect(uint8_t foodType);
	void AddEffect(uint32_t foodType);
	void RemoveEffect(uint32_t foodType);

private:
	uint8_t mFoodType;
};
