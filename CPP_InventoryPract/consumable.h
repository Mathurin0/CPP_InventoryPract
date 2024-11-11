#include <iostream>
#include "item.h"
#include "effectType.h"

class Consumable : public Item
{
public :
	Consumable(uint8_t effect, std::string name, std::string description, int cost, uint8_t type, int manaConsumptionAmount, int curseLevel, int durability);

	void Consume();

	void SetEffect(uint8_t effect);
	uint8_t GetEffect();
	bool HasEffect(uint8_t effect);
	void AddEffect(uint32_t effect);
	void RemoveEffect(uint32_t effect);

protected:
	uint8_t mEffect;
};
