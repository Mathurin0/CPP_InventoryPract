#include <iostream>
#include "consumable.h"
#include "foodType.h"
#include "IBackable.h"
#include "dish.h"
#include "itemType.h"

class Food : public Consumable, IBackable
{
public :
	Food(uint8_t foodType, uint8_t effect, std::string name, std::string description, int cost, uint8_t type, int manaConsumptionAmount, int curseLevel, int durability);

	void SetEffect(uint8_t foodType);
	uint8_t GetEffect();
	bool HasEffect(uint8_t foodType);
	void AddEffect(uint32_t foodType);
	void RemoveEffect(uint32_t foodType);

	Item Cook(std::vector<Item> ingredients) override;

private :
	uint8_t mFoodType;
};
