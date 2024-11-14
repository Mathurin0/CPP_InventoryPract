#pragma once
#include <iostream>
#include "consumable.h"
#include "foodType.h"
#include "IBackable.h"
#include "dish.h"
#include "itemType.h"

class Food : public Consumable, IBackable
{
public :
	Food(uint8_t foodType, uint8_t effect, std::string name, std::string description, int cost, int manaConsumptionAmount, int curseLevel, int durability);

	void SetFoodType(uint8_t foodType);
	uint8_t GetFoodType();
	bool HasFoodType(uint8_t foodType);
	void AddFoodType(uint32_t foodType);
	void RemoveFoodType(uint32_t foodType);

	Item Cook(std::vector<Item*> ingredients) override;

private :
	uint8_t mFoodType;
};
